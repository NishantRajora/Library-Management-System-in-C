# Library Management System (C Project)

## Overview

This project is a console-based Library Management System developed in C.  
It provides fundamental book management operations including adding, searching, viewing, and deleting book records using file-based storage.

The system demonstrates practical understanding of:

- File handling in C  
- String manipulation  
- Structured programming  
- Menu-driven user interface design  
- Persistent data storage using text files  

This project was built as an academic exercise to strengthen core C programming concepts.

---

## Project Objectives

- Implement file-based persistent storage  
- Develop CRUD operations (Create, Read, Search, Delete)  
- Design a login-based console application  
- Practice structured programming in C  
- Apply string comparison and pattern matching  

---

## Key Features

### 1. Login System

- Hardcoded username and password  
- Basic credential validation before access  
- Prevents unauthorized access to system functions  

---

### 2. Book Management Operations

#### Add Books
- Store book title  
- Store author name  
- Store unique book code  
- Append records to `bookdata.txt`  

#### Search Books
- Search by title  
- Search by author  
- Search by book code  
- Uses string comparison functions  

#### View All Books
- Displays all stored records  
- Reads sequentially from text file  

#### Delete Book
- Removes book entry based on keyword match  
- Uses temporary file mechanism  
- Applies `remove()` and `rename()` functions  

---

## Technologies and Concepts Used

| Component | Technology / Concept |
|------------|----------------------|
| Programming Language | C (Standard C89) |
| File Handling | fopen, fprintf, fscanf, remove, rename |
| String Functions | strcmp, strstr |
| Input Handling | scanf, fgets |
| Program Structure | Menu-driven CLI application |

---

## Project Structure

```
LibraryManagementSystem/
│
├── main.c
└── bookdata.txt
```

- `main.c` – Complete source code  
- `bookdata.txt` – Persistent storage file (auto-created at runtime)  

---

## Compilation and Execution

### Compile

```
gcc main.c -o library
```

### Run

```
./library
```

On Windows:

```
library.exe
```

---

## Login Credentials

| Username | Password |
|----------|----------|
| n        | 1234     |

---

## Program Menu

```
1. Add Books
2. Search Books
3. View Books
4. Delete Book
5. Exit
```

---

## Data Storage Format

Entries in `bookdata.txt` follow this format:

```
Title: HarryPotter
Author: JKRowling
Book Code: HP001
```

Each book record is stored sequentially with labeled fields.

---

## Program Workflow

1. User logs in  
2. Main menu is displayed  
3. User selects desired operation  
4. File operations are performed  
5. System returns to menu until exit  

---

## Learning Outcomes

- Understanding file operations in C  
- Working with structured text storage  
- Implementing CRUD functionality  
- Managing temporary files for safe deletion  
- Building menu-driven CLI applications  
- Handling string comparison and search logic  

---

## Limitations

- Multi-word titles and author names are not supported due to `scanf("%s")` usage  
- Case-sensitive search functionality  
- Deletes only first matched entry  
- Hardcoded authentication credentials  
- Plain text storage without encryption  
- No error handling for corrupted files  

This project is designed strictly for academic learning purposes.

---

## Future Improvements

- Replace `scanf` with `fgets` for multi-word support  
- Implement case-insensitive search  
- Add user registration system  
- Store records in structured binary format  
- Integrate SQLite database  
- Add pagination for viewing records  
- Implement role-based access (Admin/User)  
- Introduce structured error handling  

---

## Possible Extensions

- Convert to GUI using GTK  
- Add book issuing and return management  
- Maintain borrower records  
- Implement due date tracking  
- Add fine calculation module  

---

## Ideal For

- C Programming coursework  
- Mini academic projects  
- Learning file handling and string functions  
- Understanding structured procedural programming  

---

## Author

Nishant Rajora  
Data Science Undergraduate  
Focused on building strong programming foundations and system-level understanding
