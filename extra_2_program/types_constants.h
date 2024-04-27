#ifndef TYPES_CONSTANTS_H
#define TYPES_CONSTANTS_H

#include <stdbool.h>

#define TLB_SIZE 16
#define PAGE_SIZE 256
#define FRAME_SIZE 256
#define NUM_FRAMES 256
#define MAX_PAGES NUM_FRAMES


typedef struct {
    unsigned int page_number;
    unsigned int frame_number;
    bool valid;
    int counter; // Add counter field for LRU replacement
} TLBEntry;

typedef struct {
    unsigned int frame_number;
    bool valid;
} PageTableEntry;

extern unsigned char physical_memory[NUM_FRAMES][FRAME_SIZE];

#endif