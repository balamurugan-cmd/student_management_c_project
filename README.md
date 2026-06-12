# 🎓 Student Record Management System — C (Linked List)

> Console-based Student Record Management System written in **C**, using a **Singly Linked List** for dynamic memory management.  
> Multi-file project with a menu-driven interface for managing student data.

---

## 📋 Features

| Option | Feature        | Description                                          |
|--------|----------------|------------------------------------------------------|
| A/a    | ➕ Add          | Add student records with auto-incremented Roll No    |
| S/s    | 👁️ Show         | Display all records in a formatted table             |
| D/d    | 🗑️ Delete        | Delete a record by Roll No or Name                   |
| L/l    | 🗑️ Delete All    | Remove all student records at once                   |
| M/m    | ✏️ Modify        | Update Name or Mark (search by Roll No or Name)      |
| T/t    | 🔃 Sort          | Sort alphabetically by Name or descending by Marks   |
| R/r    | 🔄 Reverse       | Display the full list in reverse order (Recursive)   |
| V/v    | 💾 Save          | Save all records to a text file (`data.text`)        |
| E/e    | 🚪 Exit          | Exit the program                                     |

---

## 🗂️ Project Structure

```
student-record-system/
│
├── struct.h       →  Node structure definition + extern declaration
├── front.c        →  Main menu (program entry point)
├── add.c          →  Add new student record
├── show.c         →  Display all student records
├── del.c          →  Delete record by Roll No or Name
├── del_all.c      →  Delete all records
├── modify.c       →  Modify name or mark of existing record
├── sort.c         →  Sort records by name or mark
├── reverse.c      →  Reverse the linked list display (recursive)
├── save.c         →  Save records to file
└── print.c        →  Shared formatting and print function
```

---

## 📐 Data Structure Used — Singly Linked List

Each student is stored as a **node** in a singly linked list:

```c
struct add {
    int    roll;       // Auto-incremented Roll Number
    float  mark;       // Mark (0 to 100)
    char   name[25];   // Student Name
    struct add *next;  // Pointer to next student node
};
```

- **Head Pointer:** `struct add *hptr` — declared in `front.c`, shared across all files using `extern`
- New nodes are allocated using `malloc()` and freed using `free()` on deletion

### Memory Flow

```
hptr → [roll|name|mark|next] → [roll|name|mark|next] → [roll|name|mark|NULL]
         Student 1                 Student 2                 Student N
```

---

## 🔧 Compilation & Run

Compile all `.c` files together using `gcc`:

```bash
gcc front.c add.c show.c del.c del_all.c modify.c sort.c reverse.c save.c print.c -o student_record
```

Run the program:

```bash
./student_record
```

> ⚠️ **Windows users:** Replace `system("clear")` in `front.c` with `system("cls")`

---

## 🖥️ Menu Preview

```
+-------------------------------+
| **** STUDENT RECORD MENU **** |
| A/a : Add New Record          |
| D/d : Delete A Record         |
| S/s : Show the List           |
| M/m : Modify A record         |
| V/v : Save                    |
| E/e : Exit                    |
| T/t : Sort the List           |
| L/l : Delete All the Records  |
| R/r : Reverse the List        |
+-------------------------------+
```

---

## 📄 File-by-File Code Explanation

### `struct.h` — Shared Header
- Defines the `struct add` node with `roll`, `mark`, `name`, `next`
- Declares `extern struct add *hptr` so all files share one global head pointer
- Includes `stdio.h`, `stdlib.h`, `string.h`

### `front.c` — Main Menu
- Program entry point — `hptr` is defined here as `NULL`
- Displays the main menu using `printf`
- Reads user input and calls the correct function using `switch-case`

### `add.c` — Add Student
- Allocates a new node using `malloc()`
- Auto-assigns Roll No using a `static int x` counter
- Uses `do-while` loop to add multiple students
- Validates mark ≤ 100 before saving
- Uses `goto` label `A:` for input retry on invalid mark

### `show.c` — Show All Students
- Traverses the linked list from `hptr` to `NULL`
- Calls `pf()` from `print.c` for formatted display
- Handles the empty list case

### `del.c` — Delete Record
- **By Roll No (`roll()`):** Traverses list, matches roll, unlinks and frees the node
- **By Name (`name()`):** Finds and displays matching record, then calls `roll()` to delete
- Handles both head-node deletion and mid/end-node deletion correctly using `prev` pointer

### `del_all.c` — Delete All Records
- Loops through the entire list, freeing each node one by one
- Resets `hptr` to `NULL` after full deletion

### `modify.c` — Modify Record
- **By Roll No:** Finds node, lets user update Name or Mark in-place (direct pointer update)
- **By Name:** Finds and shows the record, then calls `roll_modify()` to update

### `sort.c` — Sort Records
- **By Name (`name_sort()`):** Outer loop iterates `'a'` to `'z'`, inner loop checks first character using `strncmp()`
- **By Mark (`prec_sort()`):** Outer loop goes 100 → 0, inner loop checks `(int)(ptr->mark) == num`
- This is a **selection-style display sort** — nodes are not reordered in memory, only printed in sorted order

### `reverse.c` — Reverse Display (Recursive)
- Uses **recursion** to reach the last node first
- Prints records from last → first on return path
- `flag` prevents the header from printing more than once

### `save.c` — Save to File
- Opens `data.text` in write mode using `fopen()`
- Writes formatted student data using `fprintf()`
- Local `pf()` mirrors `print.c` but writes to the file instead of stdout

### `print.c` — Shared Print Function
- `pf(int roll, char *name, float mark)` — formats and prints one student row
- Calculates spacing dynamically based on `strlen(name)` and mark digits

---

## 💡 Key C Concepts Demonstrated

| Concept                    | Where Used                              |
|----------------------------|-----------------------------------------|
| Singly Linked List         | All files — core data structure         |
| `malloc()` / `free()`      | `add.c`, `del.c`, `del_all.c`           |
| `extern` global variable   | `hptr` shared across all `.c` files     |
| `static` variable          | Roll counter in `add.c`, flag in `save.c` |
| Recursion                  | `reverse.c`                             |
| File I/O (`fopen`, `fprintf`) | `save.c`                             |
| String functions           | `strcmp`, `strncmp`, `strlen` in multiple files |
| `switch-case` menu         | `front.c`, `del.c`, `sort.c`, `modify.c` |
| `goto` statement           | Input retry in `add.c`                  |
| Multi-file project + Header | Entire project                         |
| Pointer arithmetic         | `prev` pointer logic in `del.c`         |

---

## ⚠️ Known Limitations & Improvements

| Issue | Suggestion |
|---|---|
| `main()` called recursively inside switch cases | Replace with a `while(1)` loop in `main()` — avoids stack overflow risk |
| Data lost on program exit | Always press `V` to save before exiting |
| Roll number does not reset after deletion | Add a re-numbering function after delete |
| No input validation for name | Add length check to prevent buffer overflow |
| `sleep(3)` used without `unistd.h` | Add `#include <unistd.h>` in `sort.c` |
| `goto` usage | Can be replaced with a proper loop for cleaner code |

---

## 👤 Author

**Bala Murugan**  
B.E. — Electrical and Electronics Engineering  

---

## 📜 License

This project is open for learning and educational use.

---

> 💬 *Built to practise C programming, singly linked list data structures, multi-file project organisation, and file I/O handling.*
