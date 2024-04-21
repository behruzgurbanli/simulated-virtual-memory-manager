
# Virtual Memory Management Simulation

This repository contains a C project designed to simulate the workings of virtual memory management, including mechanisms like TLB (Translation Lookaside Buffer), page table, and disk operations for handling page faults. It is intended as an educational tool to help understand how operating systems handle memory.

## Features

- TLB with FIFO replacement strategy
- Page table management
- Disk operations simulating hard disk reads
- Logging of operations and memory states

## Getting Started

### Prerequisites

Ensure you have GCC installed on your machine to compile the project. GCC can be installed via package managers on most Linux distributions, and on macOS with Homebrew.

### Compiling the Project

Navigate to the project directory where the source files are located and run the following command:

```bash
gcc -o vm_sim main.c memory_initialization.c tlb_manager.c page_manager.c disk_operations.c -I.
```

This command compiles the source files and links them into a single executable named `vm_sim`.

### Running the Simulation

To run the program, simply execute:

```bash
./vm_sim
```

Ensure you have the necessary data files in the same directory, such as `addresses.txt`, which should contain the virtual addresses to be resolved by the simulation.

## Project Structure

- `main.c`: The entry point of the program. It handles file operations and coordinates the simulation.
- `memory_initialization.c`: Initializes TLB, page tables, and physical memory.
- `tlb_manager.c`: Manages TLB operations, including search and update functions.
- `page_manager.c`: Handles page table updates and page faults.
- `disk_operations.c`: Simulates reading pages from a disk when page faults occur.
- `types_constants.h`: Contains type definitions and constants used across the project.

## Additional Notes

- The simulation is designed for educational purposes and does not encompass all aspects of a real operating system's memory management.
- Modify the `addresses.txt` to test different scenarios or virtual address patterns.

## Contributing

Contributions are welcome! If you'd like to improve the simulation or extend it, please fork the repository and submit a pull request.

## License

This project is open-source and available under the MIT License.
