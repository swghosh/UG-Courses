CREATE TABLE customer (
    name TEXT,
    phone NUMERIC(10),
    address TEXT,
    username TEXT,
    password TEXT,
    email TEXT,
    PRIMARY KEY(username)
);

INSERT INTO customer VALUES ('Navish Setia', 9784955552, 'Rajasthan, India', 'setian', 'helloworld123', 'navish.setia@example.com');
INSERT INTO customer VALUES ('Aditi Poonia', 9748905621, 'Rajasthan, India', 'paditi', 'smile456', 'aditi.poonia@example.com');

CREATE TABLE adminstrator (
    name TEXT,
    phone NUMERIC(10),
    username TEXT,
    password TEXT,
    email TEXT,
    PRIMARY KEY(username)
);

INSERT INTO adminstrator VALUES ('Dev Kartik Agarwal', 8961516542, 'devka', 'iamadmin123', 'dev.agarwal@example.com');
INSERT INTO adminstrator VALUES ('Aryan Agarwal', 9837549292, 'aryanar', 'iamsugarbaby69', 'aryan.agarwal@example.com');


CREATE TABLE product(
    id SERIAL,
    name TEXT,
    price NUMERIC(7, 2),
    qty NUMERIC(5),
    catergory TEXT,
    PRIMARY KEY(id)
);

INSERT INTO  product ("name", "price", "qty", "catergory") VALUES ('Apple MacBook Air', 50000, 50, 'Electronics');
INSERT INTO  product ("name", "price", "qty", "catergory") VALUES ('OnePlus 6T', 30000, 20, 'Electronics');
INSERT INTO  product ("name", "price", "qty", "catergory") VALUES ('Allen Solly Sneaker Blue', 3000, 10, 'Clothing');
INSERT INTO  product ("name", "price", "qty", "catergory") VALUES ('Reebok Sports Shoe Ortholite', 6000, 5, 'Clothing');
INSERT INTO  product ("name", "price", "qty", "catergory") VALUES ('VLCC Sunscreen Lotion', 400, 15, 'Cosmetics');
