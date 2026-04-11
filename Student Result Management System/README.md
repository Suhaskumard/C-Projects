# 🎓 Student Result Management System (C Project)

## 📌 Overview

The Student Result Management System is a console-based application developed in C. It helps manage student academic records efficiently using file handling. The system allows users to perform operations like adding, viewing, searching, updating, and deleting student data.

---

## ✨ Features

* ➕ Add new student records
* 📋 Display all student details
* 🔍 Search student by roll number
* ✏️ Update student marks
* 🗑️ Delete student records
* 📊 Automatic calculation of:

  * Total marks
  * Percentage
  * Grade (A, B, C, F)
* 💾 Persistent data storage using file handling

---

## 🛠️ Technologies Used

* Programming Language: C
* Concepts:

  * Structures
  * File Handling
  * Functions
* Compiler: GCC / CodeBlocks / Turbo C

---

## 📁 Project Structure

```
Student-Result-Management-System/
│
├── student.c        # Main source code
├── students.dat     # Data file (auto-created)
├── temp.dat         # Temporary file for deletion
└── README.md        # Documentation
```

---

## ⚙️ How to Run

1. Save the code as:

   ```
   student.c
   ```

2. Compile the program:

   ```
   gcc student.c -o student
   ```

3. Run the program:

   ```
   ./student
   ```

---

## 📋 Menu Options

```
1. Add Student
2. Display All
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

---

## 📊 Sample Output

```
===== STUDENT RESULT SYSTEM =====
1. Add Student
2. Display All
3. Search Student
...

Roll: 101
Name: Suhas Kumar
Marks: 80 75 90
Total: 245
Percentage: 81.67%
Grade: B
```

---

## 🚀 Advantages

* Simple and easy to use
* Reduces manual work
* Stores data permanently
* Efficient record management

---

## ⚠️ Limitations

* Console-based (no GUI)
* No authentication
* Suitable for small datasets only

---

## 🔮 Future Enhancements

* 🏆 Ranking system / Topper list
* 🔐 Login authentication
* 📊 Advanced grading system
* 📁 Export to CSV/Excel
* 🖥️ GUI-based application

---

## 👨‍💻 Author

Developed as a mini-project for learning C programming concepts like structures and file handling.

---

## 📚 References

* C Programming Books
* GeeksforGeeks
* TutorialsPoint
