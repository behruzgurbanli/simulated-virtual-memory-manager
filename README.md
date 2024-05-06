# Memory Management Simulator
This project simulates a virtual memory manager with support for different page replacement algorithms. It's designed to help users understand how different memory management strategies work, including FIFO, Second Chance, and LRU (Least Recently Used) algorithms.

## Features
- Simulated Virtual Memory Manager: Implements a basic virtual memory management system.
- Page Replacement Algorithms:
- FIFO (First In First Out): Pages are removed in the order they were added.
- Second Chance: An enhancement over FIFO that gives pages a second chance before removal.
- LRU (Least Recently Used): Pages least recently accessed are removed first.
## Getting Started
### Prerequisites
- GCC compiler or any standard C compiler
- Make (optional for building)
- Basic command line knowledge

### Installation
Clone the repository using git:
`git clone https://github.com/yourusername/memory-management-simulator.git`

`cd memory-management-simulator`

### Compilation
Compile the program using GCC:
`gcc -o memory_manager main.c page_manager.c tlb_manager.c disk_operations.c memory_initialization.c -Wall`

Alternatively, if you have a Makefile:
`make`

### Usage
Run the program by specifying the algorithm type:
`./memory_manager`

Upon execution, the program will prompt you to choose the page replacement algorithm by entering a number:
`Choose algorithm (1 for FIFO, 2 for Second Chance, 3 for LRU):`

Enter the number corresponding to the desired algorithm and press Enter.

## Contributing
Contributions to enhance the functionality, improve the simulation accuracy, or refactor the codebase are welcome. Please follow the steps below:

- Fork the repository.
- Create your feature branch (git checkout -b feature/AmazingFeature).
- Commit your changes (git commit -am 'Add some AmazingFeature').
- Push to the branch (git push origin feature/AmazingFeature).
- Open a pull request.
