# Minimal C Password Manager

## Description
This project is a **minimal password manager written in C**, designed to be **modular, maintainable, and easily extensible**.  
It allows storing, viewing, and saving passwords for different websites and services via a simple **CLI interface**.  
The program can be compiled as a native executable or converted to **WebAssembly (WASM)** to run directly in a web browser, for example inside an Angular portfolio.

---

## Features
- Add a new entry (site, username, password)
- View all saved entries
- Persistent storage using file I/O
- Simple and interactive CLI menu
- Modular structure, easily extendable with future features:
  - search and filter entries
  - modify or delete entries
  - password encryption
  - export to CSV

---

## Project Structure
password-manager-c/
├── src/
│ ├── main.c # Entry point of the program
│ ├── app.c/h # Main application logic
│ ├── storage.c/h # Memory and file I/O management
│ ├── menu.c/h # Menu and user interaction
├── Makefile # Build instructions
├── build/ # Optional folder for compiled binaries
└── wasm/ # Output folder for WebAssembly build

---

## Technologies
- Language: **C (C11 standard)**
- Storage: **Binary file I/O**
- Modular design: structs, header files, separated source files
- Future-ready: **WebAssembly (WASM) integration for web applications**

---

## How to Build and Run
### Native Compilation
```bash
make ./password_manager
```

##Clean Build
```bash
make clean
```
