# 📚 Library Management System 
This is a simple library management system application developed in C++.

---

## 🎓 Purpose
This project was developed as a school assignment. It allows users to manage and borrow items such as books and magazines.

---

## 🔧 Technologies Used
- **C++**
- **Makefile** (Works with MinGW or GNU Make)
- Console-based interface

---

## 🧩 Features 
- 📖 Add Book  
- 📰 Add Magazine 
- 👤 Add User  
- 📚 Borrow Book  
- 🔁 Return Book  
- 📋 View All Items 
- 🧑‍💻 View All Users
- ❌ Exit 

---

## ▶️ How to Run
### Requirements
- `g++` (MinGW or GCC)
- `make` or `mingw32-make`

---

### Build and Run
make run / mingw32-make run

---

### Clean Build Files
make clear / mingw32-make clear

---

## 📁 File Structure

---

📦 Library-Management-System/
├── .vscode/                      # (Optional) VS Code settings (for your personal development environment)
│   ├── c_cpp_properties.json
│   └── settings.json
├── include/                      # Header files (class definitions)
│   ├── Book.h
│   ├── LibraryException.h
│   ├── LibraryItem.h
│   ├── LibrarySystem.h
│   ├── Magazine.h
│   └── User.h
├── logs/                         # Log files for application transactions
│   └── transactions.txt
├── src/                          # Source files and object files
│   ├── Book.cpp / Book.o
│   ├── LibraryException.cpp / LibraryException.o
│   ├── LibraryItem.cpp / LibraryItem.o
│   ├── LibrarySystem.cpp / LibrarySystem.o
│   ├── Magazine.cpp / Magazine.o
│   └── User.cpp / User.o
├── main.cpp                      # Entry point of the application
├── main.o                        # Compiled object file for main.cpp
├── library_system.exe            # Final executable (Windows)
├── Makefile                      # Makefile for compiling and running the project
└── README.md                     # Project documentation

---

⚠️ Disclaimer
This project is shared for educational purposes. Please use it as inspiration while creating your own version, rather than copying it directly.
