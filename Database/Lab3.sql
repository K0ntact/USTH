USE northwind;
-- List all orders made after ‘2006-03-24’
SELECT * FROM orders
WHERE order_date >"2006-03-24";

-- Show product_code, unit_price, quantity, value of orders details whose order_id = 31.
-- Note: value can be calculated as unit_price * quantity * (1-discount)
SELECT product_code, unit_price, quantity, unit_price*quantity*(1-discount) as "value"
FROM order_details
INNER JOIN products ON order_details.product_id = products.id
WHERE order_id = 31;

-- Write a query to show the order id, order_date, the company name of customer, value
-- of each row for orders made after ‘2006-03-24’
select order_id, order_date, company , unit_price*quantity*(1-discount) as "value"
from orders
inner join order_details on orders.id = order_details.order_id
inner join customers on orders.customer_id = customers.id
where order_date >"2006-03-24";

-- Write a query to show information of each order including: order id, order_date,
-- company name, sub_total value of orders made after ‘2006-03-24’
select order_id, order_date, company, sum(unit_price*quantity*(1-discount)) as "sub_total"
from orders
inner join customers on orders.customer_id = customers.id
inner join order_details on orders.id = order_details.order_id
where order_date > "2006-03-24"
group by order_id
order by order_id;

-- Write a query to show information of each order including: order id, order_date,
-- company name, sub_total of orders made after ‘2006-03-24’ and sub_total greater than
-- or equal to 800. Hint: using HAVING
select order_id, order_date, company, sum(unit_price*quantity*(1-discount)) as "sub_total"
from orders
inner join customers on orders.customer_id = customers.id
inner join order_details on orders.id = order_details.order_id
where order_date > "2006-03-24"
group by order_id
having sub_total >= 800
order by order_id;

-- As the company will give rewards for employees who sold more than 1000$, the
-- director needs a report listing these employees (full_name, sale in dolars) from high to
-- low. Write a query for this report.
select CONCAT(first_name," ",last_name) as full_name,  sum(unit_price*quantity*(1-discount)) as "sub_total"
from orders
inner join employees on orders.employee_id = employees.id
inner join order_details on orders.id = order_details.order_id
group by full_name
having sub_total>1000
order by sub_total desc;

-- Create a view consisting all partners (customers and suppliers) of Northwind. The
-- columns consist of company, full_name, email_address, and type (C for customers, S
-- for suppliers)
select "C" as type, CONCAT(first_name," ",last_name) as full_name, company, email_address from customers
union
select "S", CONCAT(first_name," ",last_name) as full_name, company, email_address from suppliers;

-- Show all categories, eliminate duplicated rows, and sort the results according to
-- alphabet order
-- THIS SEEMS TO NOT HAVE ANY DUPLICATED VALUE?
select CONCAT(first_name," ",last_name) as full_name, "C" as type, customers.* from customers
union
select CONCAT(first_name," ",last_name) as full_name, "S", suppliers.* from suppliers
order by full_name;

-- Show minimum, maximum, average, standard deviation, and variance of standard_cost
-- of products
select MIN(standard_cost) as minimium, MAX(standard_cost) as maximum, AVG(standard_cost) as average,
STD(standard_cost) as standard_deviation, VARIANCE(standard_cost) as variance
from products;

-- Show the average list_price of each category.
select category, AVG(list_price) as list_price from products
group by category
order by category;

--  Create a stored procedure listing top n categories whose average prices are highest. The
-- procedure should accept n as a parameter.

DELIMITER //
create procedure get_top_n(n int)
begin
	select list_price from products
    order by list_price desc
    limit n;
end //

DELIMITER ;

call get_top_n(8);
drop procedure if exists get_top_n;

-- Create a stored procedure listing top n categories whose average prices are highest. The
-- procedure should accept n as a parameter

DELIMITER //
create procedure list_top_avg(n int)
begin
	select TEST.category from (
		select category, AVG(list_price) as avg_price
		from products
		group by category
		order by avg_price desc
		limit n
	)
    TEST;
end //

DELIMITER ;

call list_top_avg(8);
drop procedure if exists list_top_avg;

-- Among avarage list_prices of categories above, show the minimum value

select test1.avg_price from( 
	select category, AVG(list_price) as avg_price
    from products 
    group by category
    order by avg_price
	limit 1
	) test1;

-- For each purchase_order, show their id, full_name of person creating, and full_name
-- of person approving.

select p.id,  CONCAT(c.first_name," ",c.last_name) as full_name_customer, CONCAT(e.first_name," ",e.last_name) as full_name_employee
from purchase_orders p
left join customers c on p.created_by = c.id
left join employees e on p.approved_by = e.id;

