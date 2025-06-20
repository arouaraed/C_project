# ☎️ Phone Directory Management System

A **C-based contact management application** using linked lists for dynamic and efficient handling of contacts.

---

## 📂 Files

- `main.c` — Main program with menu-driven interface
- `projet.c` — Function implementations
- `projet.h` — Header file with declarations
- `repertoire.txt` — Data storage file

---

## ✨ Features

- ➕ **Add contacts**
  - At the beginning, end, or at a specific position
- ➖ **Delete contacts**
  - By position, phone number, city, or area code
- 🔍 **Search contacts**
  - By phone number, name, city, or area code
- 📝 **Modify contacts**
  - Update address or phone number
- 🔢 **Sort contacts**
  - By phone number
- 💾 **File operations**
  - Save to / load from `repertoire.txt`

---

## ⚙️ Build and Run

```bash
gcc -o repertoire main.c projet.c
./repertoire
