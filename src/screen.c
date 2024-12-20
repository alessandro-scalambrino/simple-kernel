#include "../include/screen.h"


void kprint(const char *str) {
    unsigned int i = 0;
    while (str[i] != '\0') {
        if (current_loc >= SCREENSIZE) {
            // Scroll screen
            for (unsigned int j = 0; j < SCREENSIZE - COLUMNS_IN_LINE * BYTES_FOR_EACH_ELEMENT; j++) {
                vidptr[j] = vidptr[j + COLUMNS_IN_LINE * BYTES_FOR_EACH_ELEMENT];
            }
            // Clear the last line
            for (unsigned int j = SCREENSIZE - COLUMNS_IN_LINE * BYTES_FOR_EACH_ELEMENT; j < SCREENSIZE; j += 2) {
                vidptr[j] = ' ';
                vidptr[j + 1] = 0x07;
            }
            current_loc -= COLUMNS_IN_LINE * BYTES_FOR_EACH_ELEMENT;
        }
        vidptr[current_loc++] = str[i++];
        vidptr[current_loc++] = 0x07;
    }
}

void kprint_newline(void) {
    unsigned int line_size = BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE;
    current_loc = current_loc + (line_size - current_loc % line_size);
    if (current_loc >= SCREENSIZE) {
        kprint(""); // Trigger scrolling
    }
}

void clear_screen(void) {
    for (unsigned int i = 0; i < SCREENSIZE; i += 2) {
        vidptr[i] = ' ';
        vidptr[i + 1] = 0x07;
    }
    current_loc = 0;
}
