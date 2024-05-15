# Simulated Virtual Memory Manager
This project simulates a virtual memory manager with support for various page replacement algorithms, providing users with an interactive way to understand different memory management strategies such as FIFO (First-In-First-Out), Second Chance, and LRU (Least Recently Used).

## Table of Contents
1. [Features](#features)
2. [Installation](#installation)
    - [Clone the repository](#1-clone-the-repository)
    - [Open project in C IDE](#2-open-project-in-c-ide)
    - [Compile the program using GCC](#3-compile-the-program-using-gcc)
    - [Run the program](#4-run-the-program)
    - [Choose an algorithm](#5-choose-an-algorithm)
3. [Contributing](#contributing)

## Features
- **Simulated Virtual Memory Manager**: Implements a basic virtual memory management system.
- **Page Replacement Algorithms**:
  - **FIFO (First In First Out)**: Pages are removed in the order they were added.
  - **Second Chance**: An enhancement over FIFO that gives pages a second chance before removal.
  - **LRU (Least Recently Used)**: Pages least recently accessed are removed first.
  
## Installation

### 1. Clone the repository:
  - Clone the repository to your local machine: `https://github.com/behruzgurbanli/simulated-virtual-memory-manager`

### 2. Open project in C IDE:
   - Open the project in any C-compatible IDE such as VS Code, Xcode, CLion etc...

## Usage

### 3. Compile the program using GCC: 
  - Open terminal and compile the program using this command: `gcc main.c -o mainprogram page_manager.c tlb_manager.c disk_operations.c memory_initialization.c -I.`

### 4. Run the program: 
  - Execute the program by running: `./mainprogram`
    
### 5. Choose an algorithm:
 - Upon execution, the program will prompt you to choose the page replacement algorithm by entering a number: `Choose algorithm (1 for FIFO, 2 for Second Chance, 3 for LRU):`

Enter the number corresponding to the desired algorithm and press Enter. A log file named log.txt will be generated, containing the execution log.

## Contributing
Contributions to enhance the functionality, improve the simulation accuracy, or refactor the codebase are welcome. Please follow the steps below:

- Fork the repository.
- Create your feature branch (git checkout -b feature/NewFeature).
- Commit your changes (git commit -am 'Add some NewFeature').
- Push to the branch (git push origin feature/NewFeature).
- Open a pull request.
