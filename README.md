# library-management-system-cpp
A simple console-based Library Management System written in C++. It allows managing books and students, issuing and returning books, and storing data using text files.

# 📚 Library Management System (C++)

A simple console-based **Library Management System** written in **C++**.  
It helps manage books and students, allowing administrators to issue and return books, with all data stored persistently using file handling.

---

## 🚀 Features

### 👩‍🎓 Student Management
- Add new students  
- Search, modify, and delete student records  
- Store USN, name, and address information  

### 📘 Book Management
- Add new books  
- Search, modify, and delete book details  
- Store book number, name, and author  

### 🔁 Book Issue & Return
- Issue a single book per student  
- Track issued books by USN  
- Calculate fines for late returns  

### 💾 File Handling
- Data stored in:
  - `books.dat` → Book records
  - `students.dat` → Student records
- Files are auto-created and updated when new data is added

---

## 🧱 Project Structure

📦 library-management-system-cpp
┣ 📜 main.cpp # Source code for the system
┣ 📜 books.dat # Book data file (auto-generated)
┣ 📜 students.dat # Student data file (auto-generated)
┗ 📜 README.md # Project documentation


---

## ⚙️ Installation & Usage

### Prerequisites
Make sure you have a **C++ compiler** installed (like `g++` or `clang++`).

### Compile and Run
#### On Linux / macOS:
```bash
g++ main.cpp -o library
./library


On Windows (CMD or PowerShell):

g++ main.cpp -o library.exe
library.exe
Main Menu
1. Book Issue
2. Book Deposit
3. Admin Menu
4. Exit

Admin Menu
1. Add Student
2. Show All Students
3. Search Student
4. Modify Student
5. Delete Student
6. Add Book
7. Show All Books
8. Search Book
9. Modify Book
10. Delete Book
11. Back to Main Menu

📂 Data Storage
File Name	Description
books.dat	Contains all book records (Book No, Name, Author)
students.dat	Contains student details (USN, Name, Address, Issued Book No)

⚠️ Both files are created automatically the first time you add data.

🧠 Example Interaction
--- LIBRARY MANAGEMENT SYSTEM ---
1. Book Issue
2. Book Deposit
3. Admin Menu
4. Exit
Enter choice: 3

--- ADMIN MENU ---
1. Add Student
2. Show All Students
...
Enter choice: 1
Enter USN: 1......
Enter Student Name: ramu
Enter Address: Bangalore
Student Added! 

💡 Future Enhancements

Allow issuing multiple books per student

Implement admin authentication

Replace .dat files with a database (SQLite/MySQL)

Add GUI using Qt or a web interface

👨‍💻 Author

Sudarshan G K
📧 sudarshangk801@gmail.com

🔗 GitHub: https://github.com/sudarshan-801
