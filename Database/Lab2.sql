USE northwind;
-- Query to get discontinued Product list 
SELECT * FROM northwind.products
WHERE discontinued = 1;

-- Retrieve the top 4 cheapest products
SELECT product_name, list_price 
FROM products
ORDER BY list_price 
LIMIT 4;

-- Write a query to get Product list (id, name, list_price) whose list_price cost between $15 and $25
SELECT id, product_name, list_price
FROM products
WHERE list_price BETWEEN 15 AND 25;

-- List employees with two columns: id, full_name which is constructed from first_name and last_name.
SELECT id, CONCAT(first_name, ' ' , last_name) as full_name
FROM employees;

-- Find employees whose names start with ‘A’.
SELECT first_name
FROM employees
WHERE first_name LIKE 'A%';

-- Show how many different cities the employees living in
SELECT COUNT(distinct city)
FROM employees;

-- Show ship_name of table orders without duplicated values
SELECT distinct ship_name
FROM orders
ORDER BY ship_name;

--  Show the minimum, maximum of list price in Products table
SELECT MIN(list_price) as minimun, MAX(list_price) as maximun
FROM products;

-- Display the number of current (mean Discontinued = 0) products.
SELECT COUNT(discontinued)
FROM products
WHERE discontinued = 0;

-- Show the average and standard deviation of the list_price of products
SELECT AVG(list_price) as average, STD(list_price) as standard_deviation
FROM products;

-- Use subquey, show Product list (name, list_price) expensive than the average price
SELECT product_name, list_price
FROM products
WHERE list_price > 
	(SELECT AVG(list_price)
	 FROM products);
     
-- Insert a new row to table Suppliers with the following values: company = ‘Habeco’, 
-- last_name = ‘Nguyễn’, first_name = ‘Hồng Linh’ city = ‘Hanoi’, country_region = ‘Vietnam’
INSERT INTO suppliers(company, last_name, first_name, city, country_region)
VALUES ('Habeco', 'Nguyễn', 'Hồng Linh', 'Hanoi', 'Vietnam');

-- Insert a new product into table products with the following values: product_code =
-- ‘TBTruc Bach’, SupplierID = the value corresponding to ‘Habeco’, list_price = 22,
-- discontinued = 0, category = ‘Beverages’
INSERT INTO products(product_code, supplier_ids, list_price, discontinued, category)
VALUES ('TBTruc Bach', (SELECT id FROM suppliers WHERE company = 'Habeco'), 22, 0, 'Beverages');

-- Modify the information of ‘Truc Bach’: standard_cost = 18
update products
	SET standard_cost = 18
	where product_code = 'TBTruc Bach';

-- Try deleting the row which is just inserted in table Suppliers
DELETE FROM suppliers WHERE company = 'Habeco';


