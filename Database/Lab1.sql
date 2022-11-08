CREATE DATABASE company;

USE company;

CREATE TABLE EMPLOYEE(
	Fname VARCHAR(20),
  	Minit VARCHAR(5),
	Lname VARCHAR(20),
  	Ssn CHAR(9),
  	Bdate CHAR(10),
  	Sex CHAR(1),
  	Salary NUMERIC(10,2),
  	Super_ssn CHAR(9),
  	Dno INT
  	PRIMARY KEY (Ssn),
  	FOREIGN KEY (Super_ssn) REFERENCES EMPLOYEE(Ssn),
  	FOREIGN KEY (Dno) REFERENCES DEPARTMENT(Dnumber)
);
CREATE TABLE DEPARTMENT(
  	Dname VARCHAR(20),
  	Dnumber INT,
  	Mgr_ssn CHAR(9),
  	Mgr_start_date CHAR(9),
  	PRIMARY KEY (Dnumber),
  	FOREIGN KEY (Mgr_ssn) REFERENCES EMPLOYEE(Ssn)
);
 CREATE TABLE DEPT_LOCATION(
 	Dnumber INT,
   	Dlocation VARCHAR(20),
   	FOREIGN KEY (Dnumber) REFERENCES DEPARTMENT(Dnumber)
);
 CREATE TABLE PROJECT(
 	Pname VARCHAR(20),
   	Pnumber INT,
   	Plocation VARCHAR(20),
   	Dnum INT,
   	PRIMARY KEY (Pnumber),
   	FOREIGN KEY (Dnum) REFERENCES DEPARTMENT(Dnumber)
 );
 CREATE TABLE WORKS_ON(
 	Essn CHAR(9),
   	Pno INT,
   	Hours INT,
   	FOREIGN KEY (Essn) REFERENCES EMPLOYEE(Ssn),
   	FOREIGN KEY (Pno) REFERENCES PROJECT(Pnumber)
 );
 CREATE TABLE DEPENTDENT(
 	Essn CHAR(9),
   	Dependent_name VARCHAR(20),
   	Sex CHAR(1),
   	Bdate CHAR(10),
   	Relationship VARCHAR(10),
   	FOREIGN KEY (Essn) REFERENCES EMPLOYEE(Ssn)
 );
 

 alter table EMPLOYEE 
 add column Partner_ssn VARCHAR (50) not null;
 SET FOREIGN_KEY_CHECKS=0;
 insert into DEPT_LOCATION(Dnumber, Dlocation)
 values('34', '34de56');
 SET FOREIGN_KEY_CHECKS=1;

 drop table DEPENDENT;