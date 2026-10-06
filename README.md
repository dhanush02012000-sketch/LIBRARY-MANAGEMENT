# 📚 Library Management System in C

A **menu-driven Library Management System** developed in **C programming** using **singly linked lists, structures, pointers, dynamic memory allocation, and file handling**.

The system provides functionality to manage books, track book availability, issue and return books, calculate fines for late returns, and permanently store library records using text files.

---

## 📌 Project Overview

The Library Management System is a console-based application designed to simplify common library operations.

The system maintains two types of records:

1. **Book Records**
2. **Book Issue Records**

Book records are maintained using a singly linked list, while issued-book records are maintained using a separate singly linked list.

The application supports:

- Adding new books
- Updating book details
- Deleting books
- Searching books
- Viewing all books
- Issuing books
- Returning books
- Tracking issued books
- Calculating late-return fines
- Saving records to files
- Loading records when the program starts

The main menu provides **10 operations** for managing the library.

---

# 🎯 Objectives

The main objectives of this project are:

- To implement a real-world application using C
- To understand **structures**
- To implement **singly linked lists**
- To understand pointers
- To practice dynamic memory allocation
- To implement file handling
- To manage book records efficiently
- To implement searching and updating
- To implement insertion and deletion in linked lists
- To track book issue and return operations
- To calculate fines for late returns
- To develop a modular C application

---

# ✨ Features

## 1. ➕ Add New Book

The system allows the librarian/user to add a new book.

Book information includes:

- Book ID
- Book Title
- Author Name
- Quantity

The program automatically finds the **smallest available Book ID** before adding the new record.

Example:

```text
=========================================
      LIBRARY MANAGEMENT SYSTEM
=========================================
1. Add New Book
2. Update Book Details
3. Remove Book
4. Search Book
5. View All Books
6. Issue Book
7. Return Book
8. List Issued Books
9. Save Data
10. Exit
-----------------------------------------
Enter your choice : 1

Book ID : 1
Enter Book Title : C Programming
Enter Author Name : Dennis Ritchie
Enter Quantity : 5

Book Added Successfully...
```

---

# 2. ✏️ Update Book Details

Existing book information can be modified using:

- Book ID
- Book Name

The following details can be changed:

- Book Title
- Author Name
- Quantity

The update operation searches the linked list and modifies the matching book record.

Example:

```text
------ Update Book ------
1. Update By Book ID
2. Update By Book Name
3. Back

Enter Choice : 1
Enter Book ID : 1

Enter New Book Title : C Programming
Enter New Author Name : Dennis Ritchie
Enter New Quantity : 10

Book Updated Successfully...
```

---

# 3. 🗑️ Remove Book

A book can be removed using:

- Book ID
- Book Name

The program adjusts the linked-list connections and releases the memory of the deleted node using `free()`.

Example:

```text
----- Remove Book -----
1. Delete By Book ID
2. Delete By Book Name
3. Back

Enter Choice : 1
Enter Book ID : 2

Book Deleted Successfully...
```

---

# 4. 🔍 Search Book

The system provides three search methods:

### Search by Book ID

```text
Enter Book ID : 1
```

### Search by Book Name

```text
Enter Book Name : C Programming
```

### Search by Author Name

```text
Enter Author Name : Dennis Ritchie
```

When searching by author, the program can display multiple books written by that author.

Search menu:

```text
------ Search Book ------
1. Search By Book ID
2. Search By Book Name
3. Search By Author Name
4. Back
```

---

# 5. 📋 View All Books

The **View All Books** option displays all books currently present in the library.

Example:

```text
==============================================================
ID      TITLE                   AUTHOR                  QUANTITY
==============================================================
1       C Programming           Dennis Ritchie          5
2       Data Structures         Mark Allen              3
3       Embedded C              Michael J. Pont         4
==============================================================
```

The records are traversed using the linked-list `next` pointer.

---

# 6. 📖 Issue Book

The system allows a book to be issued to a user.

The user provides:

- Book ID
- User ID
- User Name
- Issue Date
- Due Date

An issue record is created dynamically and added to the issue linked list.

When a book is issued, its available quantity is automatically decreased by one.

Example:

```text
Enter Book ID : 1
Enter User ID : 101
Enter User Name : Dhanush
Enter Issue Date (dd/mm/yyyy) : 01/10/2026
Enter Due Date (dd/mm/yyyy) : 15/10/2026

Book Issued Successfully...
```

If the quantity of the selected book is zero:

```text
Book Not Available...
```

---

# 7. 🔄 Return Book

A user can return an issued book using:

- Book ID
- User ID

The program verifies that an active issue record exists.

The user then enters:

- Return Date
- Number of Late Days

When the book is returned, its quantity is increased by one.

Example:

```text
Enter Book ID : 1
Enter User ID : 101
Enter Return Date (dd/mm/yyyy) : 17/10/2026
Enter Number of Late Days : 2

Book Returned Successfully...
Fine Amount : Rs.10
```

---

# 💰 Fine Calculation

The project calculates a fine when a book is returned late.

The current implementation uses:

```c
fine = late_days * 5;
```

Therefore:

```text
Fine = Number of Late Days × ₹5
```

Example:

| Late Days | Fine |
| --------: | ---: |
|         0 |   ₹0 |
|         1 |   ₹5 |
|         2 |  ₹10 |
|         5 |  ₹25 |
|        10 |  ₹50 |

The fine calculation is implemented in `book_return.c`.

---

# 8. 📑 List Issued Books

The system provides a separate option to display all issued-book records.

The following information is displayed:

- Issue ID
- Book ID
- User ID
- User Name
- Issue Date
- Due Date
- Return Date
- Fine

Example:

```text
=============================================================================================================
IssueID BookID  UserID  User Name      Issue Date     Due Date       Return Date     Fine
=============================================================================================================
1       1       101     Dhanush        01/10/2026     15/10/2026     Not Returned    0
=============================================================================================================
```

This information is maintained using the `ISSUE` linked-list structure.

---

# 9. 💾 Save Data

The system stores data permanently using two text files:

```text
books.txt
issued.txt
```

### `books.txt`

Stores:

- Book ID
- Book Title
- Author
- Quantity

### `issued.txt`

Stores:

- Issue ID
- Book ID
- User ID
- User Name
- Issue Date
- Due Date
- Return Date
- Fine

The `save_file()` function writes the linked-list data into these files using `fprintf()`.

---

# 10. 📂 Load Data

When the application starts, `load_file()` is called automatically.

```c
load_file();
```

The program reads existing records from:

```text
books.txt
issued.txt
```

and rebuilds the linked lists dynamically using `malloc()`.

This provides **persistent storage**, so records can be retained between program executions.

---

# 🧠 Data Structures Used

The project uses **two singly linked lists**.

## 1. Book Linked List

The book structure is:

```c
typedef struct book
{
    int id;
    char title[50];
    char author[50];
    int quantity;
    struct book *next;
} BOOK;
```

Each node contains:

- Book ID
- Title
- Author
- Quantity
- Pointer to next book

### Example

```text
HEAD
  |
  v
+--------------------------------+
| ID: 1                          |
| Title: C Programming           |
| Author: Dennis Ritchie         |
| Quantity: 5                    |
| Next --------------------------|----+
+--------------------------------+    |
                                      v
                              +----------------+
                              | ID: 2          |
                              | Data Structures|
                              | Quantity: 3    |
                              | Next ----------|----> NULL
                              +----------------+
```

---

# 2. Issue Linked List

Issued-book information uses a separate structure:

```c
typedef struct issue
{
    int issue_id;
    int book_id;
    int user_id;
    char user_name[50];
    char issue_date[20];
    char due_date[20];
    char return_date[20];
    int fine;
    struct issue *next;
} ISSUE;
```

The list is maintained using:

```c
ISSUE *ihead;
```

---

# 🔄 Program Flow

```text
                    ┌───────────────────┐
                    │   Program Start   │
                    └─────────┬─────────┘
                              ↓
                    ┌───────────────────┐
                    │    Load Data      │
                    │ books.txt         │
                    │ issued.txt        │
                    └─────────┬─────────┘
                              ↓
                    ┌───────────────────┐
                    │     Main Menu     │
                    └─────────┬─────────┘
                              ↓
       ┌──────────┬───────────┼───────────┬───────────┐
       ↓          ↓           ↓           ↓           ↓
      Add       Update      Delete      Search      Show
       │          │           │           │           │
       └──────────┴───────────┼───────────┴───────────┘
                              ↓
                    ┌───────────────────┐
                    │    Issue Book     │
                    └─────────┬─────────┘
                              ↓
                    ┌───────────────────┐
                    │    Return Book    │
                    └─────────┬─────────┘
                              ↓
                    ┌───────────────────┐
                    │  Issued Book List │
                    └─────────┬─────────┘
                              ↓
                    ┌───────────────────┐
                    │    Save Data      │
                    └─────────┬─────────┘
                              ↓
                    ┌───────────────────┐
                    │       Exit        │
                    └───────────────────┘
```

---

# 🖥️ Main Menu

The current program provides the following menu:

```text
=========================================
      LIBRARY MANAGEMENT SYSTEM
=========================================
1. Add New Book
2. Update Book Details
3. Remove Book
4. Search Book
5. View All Books
6. Issue Book
7. Return Book
8. List Issued Books
9. Save Data
10. Exit
-----------------------------------------
Enter your choice :
```

The application automatically saves the data when the user selects **Exit**.

---

# 🏗️ Project Structure

```text
LIBRARY-MANAGEMENT/
│
├── main.c
├── library.h
│
├── book_add.c
├── book_show.c
├── book_update.c
├── book_delete.c
├── book_search.c
│
├── book_issue.c
├── book_return.c
├── issued_list.c
│
├── save_file.c
├── load_file.c
│
├── books.txt
├── issued.txt
│
├── Makefile
├── library
└── README.md
```

The repository currently contains these modules and data files.

---

# 📁 File Description

| File            | Purpose                                                        |
| --------------- | -------------------------------------------------------------- |
| `main.c`        | Main menu and program control                                  |
| `library.h`     | Structures, headers, global pointers and function declarations |
| `book_add.c`    | Adds new books                                                 |
| `book_show.c`   | Displays all books                                             |
| `book_update.c` | Updates book information                                       |
| `book_delete.c` | Deletes books                                                  |
| `book_search.c` | Searches books                                                 |
| `book_issue.c`  | Issues books to users                                          |
| `book_return.c` | Handles book returns and fine calculation                      |
| `issued_list.c` | Displays issued-book records                                   |
| `save_file.c`   | Saves book and issue data                                      |
| `load_file.c`   | Loads saved data                                               |
| `books.txt`     | Persistent book records                                        |
| `issued.txt`    | Persistent issue records                                       |
| `Makefile`      | Automates compilation                                          |
| `library`       | Generated executable                                           |

---

# 🛠️ Technologies Used

| Technology                    | Purpose                                 |
| ----------------------------- | --------------------------------------- |
| **C Programming**             | Main programming language               |
| **Structures**                | Represent books and issue records       |
| **Singly Linked List**        | Dynamic record management               |
| **Pointers**                  | Linked-list traversal and manipulation  |
| **Dynamic Memory Allocation** | Runtime creation of records             |
| **File Handling**             | Persistent data storage                 |
| **GCC**                       | C compiler                              |
| **Makefile**                  | Build automation                        |
| **Git/GitHub**                | Version control and source-code hosting |

The repository's Makefile uses `gcc` and compiles the project into an executable named `library`.

---

# 💻 Requirements

To compile and run this project, you need:

- GCC compiler
- Make utility
- Linux/Unix environment or Windows environment with GCC and Make
- Terminal/Command Prompt

---

# 🚀 Installation & Setup

## 1. Clone the Repository

```bash
git clone https://github.com/dhanush02012000-sketch/LIBRARY-MANAGEMENT.git
```

## 2. Navigate to the Project

```bash
cd LIBRARY-MANAGEMENT
```

## 3. Compile Using Makefile

```bash
make
```

The Makefile compiles all `.c` files into object files and links them into:

```text
library
```

## 4. Run the Program

On Linux:

```bash
./library
```

---

# 🧹 Clean Build Files

To remove generated object files and the executable:

```bash
make clean
```

The Makefile removes:

```text
*.o
library
```

---

# 🔧 Manual Compilation

If Make is not available, the project can be compiled using GCC:

```bash
gcc main.c \
book_add.c \
book_show.c \
book_delete.c \
book_update.c \
book_search.c \
book_issue.c \
book_return.c \
issued_list.c \
save_file.c \
load_file.c \
-o library
```

Then run:

```bash
./library
```

---

# 📊 Example Book Records

```text
==============================================================
ID      TITLE                   AUTHOR                  QUANTITY
==============================================================
1       C Programming           Dennis Ritchie          5
2       Data Structures         Mark Allen              3
3       Embedded C              Michael J. Pont         4
==============================================================
```

---

# 📖 Example Issue Record

```text
=============================================================================================================
IssueID BookID  UserID  User Name      Issue Date     Due Date       Return Date     Fine
=============================================================================================================
1       1       101     Dhanush        01/10/2026     15/10/2026     Not Returned    0
=============================================================================================================
```

---

# 🧩 Important C Concepts Demonstrated

This project provides practical experience with:

### Structures

```c
typedef struct book
{
    int id;
    char title[50];
    char author[50];
    int quantity;
    struct book *next;
} BOOK;
```

### Pointers

```c
BOOK *head;
ISSUE *ihead;
```

### Dynamic Memory Allocation

```c
malloc(sizeof(BOOK));
malloc(sizeof(ISSUE));
```

### Memory Deallocation

```c
free(temp);
```

### String Functions

```c
strcmp()
strcpy()
```

### File Handling[https://github.com/dhanush02012000-sketch/INTEGERATED-INDUSTRIAL-HAZARDS-MONITORING-AND-SECURE-ACCESS-CONTROL-SYSTEM](https://github.com/dhanush02012000-sketch/INTEGERATED-INDUSTRIAL-HAZARDS-MONITORING-AND-SECURE-ACCESS-CONTROL-SYSTEM)&#xA;fclose()&#xA;fprintf()&#xA;fscanf()

### Linked List Operations

- Insertion
- Traversal
- Searching
- Deletion
- Updating

---

# 🔐 Data Management

The project maintains two independent linked lists:

```text
             Library Management System
                       │
             ┌─────────┴─────────┐
             ↓                   ↓
        BOOK Linked List     ISSUE Linked List
             │                   │
       Book details        Issue information
             │                   │
       books.txt            issued.txt
```

This separation makes it easier to manage book inventory and issue transactions independently.

---

# ⚠️ Current Limitations

The current implementation has some limitations:

1. It is a **command-line application**.
2. There is no username/password authentication.
3. Data is stored in text files rather than a database.
4. Date validation is not automated.
5. The user manually enters the number of late days during return.
6. Book titles/authors are stored using whitespace-delimited file fields, so persistence of multi-word titles/authors needs improvement.
7. There is no separate admin/member role.
8. There is no graphical user interface.
9. There is no online/multi-user access.
10. There is no automated backup system.

These limitations provide good opportunities for future enhancement.

---

# 🚀 Future Enhancements

The project can be extended with:

### 🔐 Authentication

- Admin login
- Librarian login
- Student/member login
- Password protection

### 🗄️ Database

Replace text files with:

- MySQL
- SQLite
- PostgreSQL

### 🖥️ GUI

Create a graphical interface using:

- C GUI libraries
- Java Swing
- Python Tkinter
- Web technologies

### 📅 Automatic Date Management

Instead of manually entering late days, the system can:

1. Store issue date
2. Store due date
3. Get the current date
4. Calculate overdue days automatically
5. Calculate the fine automatically

### 🔎 Advanced Search

Add:

- Partial title search
- Partial author search
- Category search
- Available-only search

### 📊 Reports

Generate:

- Total books
- Available books
- Issued books
- Returned books
- Pending returns
- Total fines

### 🌐 Web-Based Library

The project can eventually be converted into a web-based system with:

- Frontend
- Backend
- Database
- User authentication
- Online book search
- Book reservation

---

# 🎓 Learning Outcomes

After completing this project, the following concepts can be explained confidently:

- What is a structure in C?
- What is a linked list?
- How does a singly linked list work?
- How are nodes dynamically created?
- How does `malloc()` work?
- Why is `free()` required?
- How is a node deleted?
- How is a linked list traversed?
- How does file handling work?
- Difference between `fscanf()` and `fprintf()`
- How data is saved permanently
- How book quantity changes during issue/return
- How fine calculation works
- How modular programming works
- How a Makefile simplifies compilation

---

# 🧠 Project Architecture

The application follows a modular approach:

```text
                    main.c
                      │
                      ↓
                ┌───────────┐
                │ library.h │
                └─────┬─────┘
                      │
       ┌──────────────┼──────────────┐
       ↓              ↓              ↓
  Book Management   Issue/Return   File Management
       │              │              │
       ├─ Add         ├─ Issue        ├─ Save
       ├─ Update      ├─ Return       └─ Load
       ├─ Delete      └─ List
       ├─ Search
       └─ Show
```

This modular structure separates different responsibilities into different source files, making the project easier to maintain and understand.

---

# 👨‍💻 Author

**Dhanush R**

GitHub:

[Dhanush R — GitHub](https://github.com/dhanush02012000-sketch?utm_source=chatgpt.com)

Project Repository:

[LIBRARY-MANAGEMENT — GitHub Repository](https://github.com/dhanush02012000-sketch/LIBRARY-MANAGEMENT?utm_source=chatgpt.com)

---

# 📜 License

This project is developed for **educational and learning purposes**.

---

# ⭐ Acknowledgement

This project was developed to gain practical knowledge of:

**C Programming + Data Structures + Linked Lists + Dynamic Memory Allocation + File Handling + Modular Programming**

It demonstrates how fundamental C concepts can be combined to create a practical **Library Management System**.

---

## ⭐ Project Highlights

```text
✔ Add Books
✔ Update Books
✔ Delete Books
✔ Search Books
✔ Display Books
✔ Issue Books
✔ Return Books
✔ Track Issued Books
✔ Calculate Fines
✔ Save Data
✔ Load Data
✔ Linked List Implementation
✔ File Handling
✔ Dynamic Memory Allocation
✔ Modular C Programming
```
