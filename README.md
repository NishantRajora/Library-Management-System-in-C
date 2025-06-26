# 📚 Library Management System (C Project)

A simple **Library Management System** written in **C** that allows users to **add**, **search**, **view**, and **delete** books using a text file for persistent storage. The system includes a **login interface**, file handling, and a basic text-based menu system.


---

## 🧰 Features

- 🔐 **Login System** (Hardcoded username and password)
- 📘 **Add Books** – Input book title, author, and code
- 🔍 **Search Books** – By title, author, or book code
- 📖 **View All Books** – Display all stored book entries
- ❌ **Delete Book** – Remove book entry by keyword match
- 📂 **File Storage** – Uses `bookdata.txt` for storing data

---

## 🛠️ Technologies Used

| Feature            | Tool / Concept   |
|--------------------|------------------|
| Programming Lang.  | C (Standard C89) |
| File Handling      | `fopen`, `fprintf`, `fscanf`, `remove`, `rename` |
| String Operations  | `strcmp`, `strstr`, `scanf`, `fgets`             |

---

## 📁 File Structure

```
📦 LibraryManagementSystem/
├── main.c              // Complete C code
├── bookdata.txt        // Stores all book entries (created at runtime)
```

---

## 🖥️ How to Run

### 🧱 Compile
```bash
gcc main.c -o library
```

### 🚀 Execute
```bash
./library
```

---

## 🔑 Login Credentials

| Username | Password |
|----------|----------|
| n        | 1234     |

---

## 🧪 Program Menu

```
+-----------------------------------------------------------------+
|                   MAIN MENU                                     |
+-----------------------------------------------------------------+
|    1.  Add Books                                                |
|    2.  Search Books                                             |
|    3.  View Books                                               |
|    4.  Delete Book                                              |
|    5.  Exit                                                     |
+-----------------------------------------------------------------+
```

---

## 📘 Sample Book Entry Format (Stored in `bookdata.txt`)

```
Title: HarryPotter
Author: JKRowling
Book Code: HP001

Title: CProgramming
Author: DennisRitchie
Book Code: C001
```

> Note: Title, author, and code are stored in a single-line format, separated by labels.

---

## ⚠️ Known Limitations

- Does not support **multi-word** book titles or author names due to `scanf(" %s", ...)` usage.
- No **encryption** or secure user authentication.
- Deletes first match only; not case-insensitive.
- Data is overwritten if formatting in the file is changed manually.

---

## 🌱 Future Improvements

- 🧾 Support **multi-word input** using `fgets()` or input buffers
- 🔒 Add **user registration/authentication** with encryption
- 🗃️ Store data in **binary file** or **database (SQLite)**
- 🖥️ Add a **GUI** using C libraries like GTK

---

## 🧑‍🏫 Project Info

> 🎓 **Mini Project** for 2nd/3rd Semester (C Programming)  
> 🏫 Suitable for coursework and understanding **file handling**, **string functions**, and **user-driven programs** in C.
