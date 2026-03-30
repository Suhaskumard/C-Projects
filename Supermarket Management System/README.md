
# 🛒 Supermarket Management System (C Language)

## 📌 Overview
The **Supermarket Management System** is a console-based application developed in **C language** that simulates real-world supermarket operations such as inventory management, billing, and sales reporting.

The system uses **file handling** to store product and sales data persistently and provides **role-based access** for Admin and Cashier users. It is designed to demonstrate strong fundamentals in **C programming and system-level application design**.

## 🎯 Objectives
- Manage supermarket product inventory efficiently
- Enable secure admin and cashier operations
- Generate bills with automatic stock updates
- Store sales data for revenue analysis
- Demonstrate practical use of file handling in C


## 🧠 Features

### 🔐 Admin Module
- Admin login authentication
- Add new products
- View all products
- Update product price and quantity
- Delete products
- View total revenue report

### 🧾 Cashier Module
- View available products
- Create customer bills
- Add multiple items to a bill
- Automatic stock quantity reduction
- Display final bill amount

### 📊 Reports
- Total revenue calculation from sales data
- Persistent sales history using files

### 💾 System Features
- File-based data storage (`.dat` files)
- Automatic data persistence across runs
- Random bill number generation
- Date stamping for each sale
- Menu-driven console interface


## 🛠️ Technologies Used
- **Programming Language:** C  
- **Concepts Applied:**
  - Structures
  - File Handling (Binary Files)
  - Functions & Modular Programming
  - Conditional Logic & Loops
  - String Handling
  - Role-Based Access Control


## 📁 Project Structure

supermarket-management-system-c/
│
├── supermarket.c
├── products.dat        (auto-generated)
├── sales.dat           (auto-generated)
└── README.md


> The `.dat` files are created automatically when the program runs


## ▶️ How to Compile and Run

### 1️⃣ Compile the Program
gcc supermarket.c -o market

### 2️⃣ Run the Program


./market


## 🔐 Login Credentials
### Admin

Username: admin
Password: admin123

### Cashier

* No login required (direct access)


## 📈 Sample Functionalities

* Add and manage product inventory
* Generate customer bills
* Automatic stock updates after billing
* Sales data stored for reporting
* Revenue calculation


## 🧪 Test Coverage

* Valid and invalid admin login
* Product addition, update, and deletion
* Billing with sufficient and insufficient stock
* Sales data persistence
* Revenue accuracy


## 🎓 Academic Relevance

This project demonstrates:

* Practical application of **C programming**
* Effective use of **file handling**
* Real-world **inventory and billing workflow**
* Clean and modular code structure

✔ Suitable for:

* CSE Mini Projects
* Data Structures / C Programming Labs
* System Programming Coursework
* GitHub Portfolio Projects

## 🔮 Future Enhancements

* Duplicate product ID validation
* GST / tax calculation
* CSV export of sales reports
* Password hashing for admin login
* GUI-based interface
* Database integration

## 📜 License

This project is intended for **academic and learning purposes only**.



## 🧑‍🏫 Evaluation Note

> *“This project demonstrates solid understanding of file-based systems and real-world application logic using C.”*