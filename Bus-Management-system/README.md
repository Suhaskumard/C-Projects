🚌 Bus Management System (C Language)

📌 Overview

The Bus Management System is a console-based application developed in C language that simulates a real-world bus ticket booking and management system.

The system supports admin and passenger operations, uses linked lists for dynamic data handling, and ensures data persistence using file handling. It is designed to demonstrate strong fundamentals in C programming and data structures.

🎯 Objectives

Manage bus details efficiently
Enable passengers to book and cancel tickets
Maintain ticket and revenue records
Demonstrate secure admin authentication
Persist data across program executions
🧠 Features

🔐 Admin Module

Secure admin login (password hashing)
Add new buses
View all buses
👨‍💼 Passenger Module

View available buses
Book tickets with seat validation
View ticket using Ticket ID
Cancel tickets with refund calculation
📊 Reports

Total revenue calculation
Export booking data to CSV (Excel compatible)
💾 System Features

Linked list–based data structures
Binary file storage (.dat files)
Runtime password hashing
Automatic data loading and saving
Unique ticket ID generation
Date and time stamping
🛠️ Technologies Used

Programming Language: C

Concepts:

Structures
Pointers
Linked Lists
File Handling
Hashing
Dynamic Memory Allocation
📁 File Structure Bus-Management-System/ ├── bus.c
├── buses.dat
├── bookings.dat
├── bookings.csv
└── README.md

▶️ How to Compile and Run

1️⃣ Compile

gcc bus_final_fixed.c -o bus

2️⃣ Run

./bus

🔐 Admin Credentials

Username: admin Password: root

📈 Sample Output

Successful admin authentication
Bus listing and route display
Ticket generation with unique Ticket ID
Revenue calculation
CSV export for bookings
🧪 Test Coverage

Valid and invalid admin login
Duplicate bus detection
Seat availability validation
Ticket booking and cancellation
Revenue accuracy
Data persistence on restart
🎓 Academic Relevance

This project demonstrates:

Strong command over C programming
Practical use of data structures
Real-world system design
Secure authentication handling
File-based data persistence
✔ Suitable for:

CSE Mini Projects
Data Structures Lab
System Programming coursework
Resume and GitHub portfolio
🔮 Future Enhancements

Login attempt limit
Password salting
GUI interface
Database integration
Multi-file modular structure
Performance optimization for large datasets
🧑‍🏫 Evaluation Note
“This project demonstrates system-level thinking and strong fundamentals in C programming.”