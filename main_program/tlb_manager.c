#include "types_constants.h"


int tlb_next_index = 0;
void update_TLB(TLBEntry *tlb, unsigned int page_number, unsigned int frame_number) {
    for (int i = 0; i < TLB_SIZE; i++) {
        if (tlb[i].valid && tlb[i].page_number == page_number) {
            tlb[i].frame_number = frame_number;
            return;
        }
    }

    tlb[tlb_next_index].page_number = page_number;
    tlb[tlb_next_index].frame_number = frame_number;
    tlb[tlb_next_index].valid = true;
    tlb_next_index = (tlb_next_index + 1) % TLB_SIZE;
}

int search_TLB(const TLBEntry *tlb, unsigned int page_number, int *total_tlb_hits) {
    for (int i = 0; i < TLB_SIZE; i++) {
        if (tlb[i].valid && tlb[i].page_number == page_number) {
            (*total_tlb_hits)++;
            return tlb[i].frame_number;
        }
    }
    return -1;
}
