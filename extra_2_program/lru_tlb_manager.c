#include "types_constants.h"

int lru_tlb_next_index = 0;
int lru_tlb_counter = 0;

void update_LRU_TLB(TLBEntry *tlb, unsigned int page_number, unsigned int frame_number) {
    // Check if the page is already in the TLB and update it
    for (int i = 0; i < TLB_SIZE; i++) {
        if (tlb[i].valid && tlb[i].page_number == page_number) {
            tlb[i].frame_number = frame_number;
            return;
        }
    }

    // Find the index of the least recently used entry
    int lru_index = -1;
    int lru_counter = lru_tlb_counter + 1; // Increment counter to find LRU
    for (int i = 0; i < TLB_SIZE; i++) {
        if (!tlb[i].valid) {
            lru_index = i;
            break;
        }
        if (tlb[i].counter < lru_counter) {
            lru_index = i;
            lru_counter = tlb[i].counter;
        }
    }

    // Insert new entry at the LRU index
    tlb[lru_index].page_number = page_number;
    tlb[lru_index].frame_number = frame_number;
    tlb[lru_index].valid = true;
    tlb[lru_index].counter = ++lru_tlb_counter;
}

int search_LRU_TLB(TLBEntry *tlb, unsigned int page_number, int *total_tlb_hits) {
    for (int i = 0; i < TLB_SIZE; i++) {
        if (tlb[i].valid && tlb[i].page_number == page_number) {
            (*total_tlb_hits)++;
            // Update the counter for LRU
            tlb[i].counter = ++lru_tlb_counter;
            return tlb[i].frame_number;
        }
    }
    return -1;
}