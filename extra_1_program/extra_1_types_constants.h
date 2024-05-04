#ifndef TYPES_CONSTANTS_H
#define TYPES_CONSTANTS_H

#include <stdbool.h>

#define TLB_SIZE 16
#define PAGE_SIZE 256
#define FRAME_SIZE 256 // the same as the page size
#define NUM_FRAMES 64 // memory_size divided by page size
#define MAX_PAGES NUM_FRAMES

typedef struct {
    unsigned int page_number;
    unsigned int frame_number;
    bool valid;
} TLBEntry;

typedef struct {
    unsigned int frame_number;
    bool valid;
    bool referenced;  // adding R bit for tracking usage of pages
} PageTableEntry;

extern unsigned char physical_memory[NUM_FRAMES][FRAME_SIZE];

extern bool frame_occupied[NUM_FRAMES];

#endif