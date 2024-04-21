#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TLB_SIZE 16
#define PAGE_SIZE 256
#define FRAME_SIZE 256
#define NUM_FRAMES 256
#define MAX_PAGES NUM_FRAMES

typedef struct {
    unsigned int page_number;
    unsigned int frame_number;
    bool valid;
} TLBEntry; // TLB entry

TLBEntry tlb[TLB_SIZE]; // TLB

typedef struct {
    unsigned int frame_number;
    bool valid;
} PageTableEntry;

PageTableEntry page_table[MAX_PAGES];

unsigned char physical_memory[NUM_FRAMES][FRAME_SIZE]; // Physical memory

void init_TLB() {
    for (int i = 0; i < TLB_SIZE; i++) {
        tlb[i].valid = false;
    }
}

void init_physical_memory() {
    memset(physical_memory, 0, sizeof(physical_memory));
}

void init_page_table() {
    for (int i = 0; i < MAX_PAGES; i++) {
        page_table[i].valid = false;
    }
}

void update_page_table(unsigned int page_number, unsigned int frame_number) {
    page_table[page_number].frame_number = frame_number;
    page_table[page_number].valid = true;
}

int tlb_next_index = 0;

void update_TLB(unsigned int page_number, unsigned int frame_number) {
    // Check if the page is already in the TLB and update it
    for (int i = 0; i < TLB_SIZE; i++) {
        if (tlb[i].valid && tlb[i].page_number == page_number) {
            tlb[i].frame_number = frame_number;
            return;
        }
    }

    // Insert new entry at the next index in a FIFO manner
    tlb[tlb_next_index].page_number = page_number;
    tlb[tlb_next_index].frame_number = frame_number;
    tlb[tlb_next_index].valid = true;

    // Increment the next index, wrapping around in a circular buffer fashion
    tlb_next_index = (tlb_next_index + 1) % TLB_SIZE;
}

int search_TLB(unsigned int page_number) {
    for (int i = 0; i < TLB_SIZE; i++) {
        if (tlb[i].valid && tlb[i].page_number == page_number) {
            return tlb[i].frame_number; // TLB hit, return frame_number
        }
    }
    return -1; // TLB miss, return -1
}

bool frame_occupied[NUM_FRAMES] = {false};

// Function to read from the physical memory
int read_page_from_disk(unsigned int page_number) {
    const char *disk_filename = "disk_sim";
    FILE *disk = fopen(disk_filename, "rb");
    if (disk == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    unsigned char BUFFER[PAGE_SIZE];
    int frame_number = -1; // Need to implement logic to find an emptry frame or use a replacement algorithm

    long offset = (long) page_number * PAGE_SIZE; // Calculate the position to read from the disk
    fseek(disk, offset, SEEK_SET); // Move the file pointer to the calculated position

    if(fread(BUFFER, 1, PAGE_SIZE, disk) == PAGE_SIZE) {
        for (int i = 0; i < NUM_FRAMES; i++) {
            if (!frame_occupied[i]) {  // Check if the frame is free
                memcpy(physical_memory[i], BUFFER, PAGE_SIZE);
                frame_occupied[i] = true;
                frame_number = i;
                break;
            }
        }
    }

    fclose(disk);
    return frame_number;
}

int handle_page_fault(unsigned int page_number) {
    int frame_number = read_page_from_disk(page_number);
    if (frame_number != -1) {
        update_page_table(page_number, frame_number);
        update_TLB(page_number, frame_number);
    }
    return frame_number;
}

int main(int argc, char *argv[]) {

    // Opening the addresses.txt file
    const char *virtual_addr_filename = "addresses.txt";
    FILE *virtual_addr_file = fopen(virtual_addr_filename, "r");
    if (virtual_addr_file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    unsigned int logical_address;
    unsigned int page_number;
    unsigned int offset;
    int frame_number;

    init_TLB();
    init_physical_memory();
    init_page_table();

    // Reading the logical addresses from the file
    while (fscanf(virtual_addr_file, "%u", &logical_address) != EOF) {
        
        page_number = logical_address / PAGE_SIZE;
        offset = logical_address % PAGE_SIZE;
        frame_number = search_TLB(page_number); // Search TLB for page_number

        if (frame_number != -1) 
            printf("Logical address: %5u,  Page number: %3u,  Offset: %3u, Frame number: %3u (TLB Hit)\n", logical_address, page_number, offset, frame_number);
        else {
            frame_number = handle_page_fault(page_number);
            printf("Logical address: %5u,  Page number: %3u,  Offset: %3u, Frame number: %3u (TLB Miss)\n", logical_address, page_number, offset, frame_number);
        }
    }

    fclose(virtual_addr_file);
    return EXIT_SUCCESS;

}

/*
• Program address space: 16-bit
• Page size: 2^8 bytes (256 bytes)
• TLB capacity: 16 entries
• Number of frames: 256
• Physical memory size: 64 KB
*/