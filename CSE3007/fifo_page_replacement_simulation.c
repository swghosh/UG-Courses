#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PAGE_SIZE 1000
struct page {
    unsigned int id;
    // each page can contain 1000 bytes of information
    char data[PAGE_SIZE]; // actual data contained inside the page
};
#define PAGE struct page

struct frame {
    unsigned int id;
    // each frame can contain data equivalent in size to page
    bool is_allocated;
    unsigned int page_id;
    char data[PAGE_SIZE];
};
#define FRAME struct frame

void print_frames(FRAME *frames, int f_count) {
    int iter_index;
    char page_disp[20];
    for(iter_index = 0; iter_index < f_count; iter_index++) {
        sprintf(page_disp, "Page%02d", frames[iter_index].page_id);
        printf("| Frame%04d | %s | %s |\n", frames[iter_index].id, 
            (frames[iter_index].is_allocated ? page_disp : "NoPage"), 
            (frames[iter_index].is_allocated ? "✔" : "x"));
    }
}

void copy_data(PAGE *from_page, FRAME *to_frame) {
    char byte; int iter_index;
    for(iter_index = 0; iter_index < PAGE_SIZE; iter_index++) {
        to_frame->data[iter_index] = from_page->data[iter_index];
    }
}

void fifo_entry(FRAME *frames, int f_count, PAGE *page) {
    int allocated_count, iter_index, entry_id;
    allocated_count = 0;
    for(iter_index = 0; iter_index < f_count; iter_index++) {
        if(frames[iter_index].is_allocated) {
            allocated_count++;
        }
    }

    // all frames are full
    if(allocated_count == f_count) {
        entry_id = 0;
    }
    else {
        entry_id = allocated_count;
    }
    frames[entry_id].is_allocated = true;
    frames[entry_id].page_id = page->id;
    copy_data(page, &frames[entry_id]);
    printf("Allocated page %d to frame %d.\n", frames[entry_id].page_id, 
        frames[entry_id].id);
}

bool is_page_present(FRAME *frames, int f_count, int page_id) {
    int iter_index;
    for(iter_index = 0; iter_index < f_count; iter_index++) {
        if(frames[iter_index].is_allocated && frames[iter_index].page_id == page_id) {
            return true;
        }
    }
    return false;
}

int main() {
    int p_count, f_count, r_count;
    int iter_index, iter_index2, extra_id, fault_count;
    PAGE *pages; FRAME *frames;
    int *page_requirements;

    printf("How many pages do you want to create? (integer expected): ");
    scanf("%d", &p_count);
    
    puts("");
    puts("Creating pages..");
    pages = (PAGE*) malloc(sizeof(PAGE) * p_count);
    for(iter_index = 0; iter_index < p_count; iter_index++) {
        // assign each page an id
        pages[iter_index].id = iter_index;
        printf("| Page%d ", pages[iter_index].id);
    }
    printf("|\n\n");

    printf("How many frames do you want to use? (integer expected): ");
    scanf("%d", &f_count);
    
    frames = (FRAME*) malloc(sizeof(FRAME) * f_count);
    for(iter_index = 0; iter_index < f_count; iter_index++) {
        // assign each frame an id
        frames[iter_index].id = iter_index + 1000; // frame names will look fancy like 1000, 1001, ...
        frames[iter_index].is_allocated = false;
    }

    puts("");

    printf("How many page requirements do you want to process? (integer expected): ");
    scanf("%d", &r_count);

    page_requirements = (int*) malloc(sizeof(int) * r_count);
    for(iter_index = 0; iter_index < r_count; iter_index++) {
        printf("Page Requirement %d? (use page id, integer expected): ", iter_index + 1);
        scanf("%d", &page_requirements[iter_index]);
    }
    
    puts("");
    puts("The following are your page requirements.");
    for(iter_index = 0; iter_index < r_count; iter_index++) {
        printf("| Page%d ", page_requirements[iter_index]);
    }
    printf("|\n");

    puts("");
    
    puts("Using FIFO page replacement.");
    fault_count = 0;
    print_frames(frames, f_count);
    for(iter_index = 0; iter_index < r_count; iter_index++) {
        printf("Step %d:\n", iter_index + 1);
        extra_id = page_requirements[iter_index];
        if(!is_page_present(frames, f_count, extra_id)) {
            fifo_entry(frames, f_count, pages + extra_id);
            fault_count++;
        }
        print_frames(frames, f_count);
    }
    printf("Total page faults: %d\n", fault_count);
    return 0;
}