# OSMS-API

Simple API to partially implement four sample functionalities of an Online Shopping Management System.

### API Endpoint 1: {url}/api/users/administrators/login

Administrator login functionality<br>
Input Method: **POST**<br>
Input Body: `{"username": "test.name", "password": "test_password"}`<br>
Output: `true | false`<br>

### API Endpoint 2: {url}/api/users/customers/login

Customer login functionality<br>
Input Method: **POST**<br>
Input Body: `{"username": "test.name", "password": "test_password"}`<br>
Output: `true | false`<br>

### API Endpoint 3: {url}/api/users/customers/signup

Customer signup functionality<br>
Input Method: **POST**<br>
Input Body: `{"name": "FirstName LastName", "email": "someone@example.com", "username": "test.name", "password": "test_password", "phone": 0000000000, "address": "Street Name, City, Country"}`<br>
Output: `{**same as input**} | null`<br>
  
### API Endpoint 4: {url}/api/catalogue

Catalogue as a list of products<br>
Input Method: **GET**<br>
Output: `[{"id": 1, "name": "Product Name 1", "category": "Some Category", "price": 50000.0, "qtyAvailable": 50}, ...]`<br>

#

{url} can be replaced with https://cse2017-osms.herokuapp.com

The project has been written using the Java Servlets API and is deployed to the [Heroku PaaS platform](https://heroku.com/) so that it can be tested using API testing tools like [Postman](https://getpostman.com/).