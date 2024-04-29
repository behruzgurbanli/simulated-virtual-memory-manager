#include "types_constants.h"

#include <stdlib.h>

extern int read_page_from_disk(unsigned int page_number, unsigned char physical_memory[NUM_FRAMES][FRAME_SIZE], bool *frame_occupied);
extern void update_page_table(PageTableEntry *page_table, unsigned int page_number, unsigned int frame_number);
extern int handle_page_fault(PageTableEntry *page_table, TLBEntry *tlb, unsigned int page_number, bool *frame_occupied, int *total_page_faults);
extern void update_TLB(TLBEntry *tlb, unsigned int page_number, unsigned int frame_number);

void update_page_table(PageTableEntry *page_table, unsigned int page_number, unsigned int frame_number) {
    page_table[page_number].frame_number = frame_number;
    page_table[page_number].valid = true;
}

int handle_page_fault(PageTableEntry *page_table, TLBEntry *tlb, unsigned int page_number, bool *frame_occupied, int *total_page_faults) {
    (*total_page_faults)++;
    int frame_number = read_page_from_disk(page_number, physical_memory, frame_occupied);
    if (frame_number != -1) {
        update_page_table(page_table, page_number, frame_number);
        update_TLB(tlb, page_number, frame_number);
    }
    return frame_number;
}