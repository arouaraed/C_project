# Phone Directory Management System

A C-based contact management application using linked lists.

## Files
- [`main.c`](main.c) - Main program with menu interface
- [`projet.c`](projet.c) - Function implementations
- [`projet.h`](projet.h) - Header with declarations
- [`repertoire.txt`](repertoire.txt) - Data storage file

## Features
- **Add contacts** - at beginning, end, or specific position
- **Delete contacts** - by position, phone number, city, or area code
- **Search contacts** - by phone, name, city, or area code
- **Modify contacts** - update address or phone number
- **Sort contacts** - by phone number
- **File operations** - save/load from file

## Build and Run
```bash
gcc -o repertoire main.c projet.c
./repertoire
```

## Usage
Run the program and navigate through the menu system:
1. Create directory
2. Update contacts
3. Search and display
4. File operations
5. Exit

## Data Storage
Contacts are saved to [`repertoire.txt`](repertoire.txt) in the format:
```
phone_number last_name first_name street city postal_code birth_date email
```
