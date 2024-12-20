#include "../include/keyboard.h"
#include "../include/io.h"
#include "../include/screen.h"


unsigned int current_loc = 0;
char *vidptr = (char*)0xb8000;
char input_buffer[BUFFER_SIZE];
volatile int buffer_index = 0;
volatile int input_ready = 0;
unsigned char keyboard_map[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};

void kb_init(void)
{
	/* 0xFD is 11111101 - enables only IRQ1 (keyboard)*/
	write_port(0x21 , 0xFD);
}

void keyboard_handler_main(void) {
    unsigned char status;
    char keycode;

    write_port(0x20, 0x20); // Write EOI

    status = read_port(KEYBOARD_STATUS_PORT);
    if (status & 0x01) {
        keycode = read_port(KEYBOARD_DATA_PORT);
        if (keycode < 0) return;

        char key = keyboard_map[(unsigned char)keycode];
        if (key == '\n') {
            input_buffer[buffer_index] = '\0';
            input_ready = 1; 
            buffer_index = 0; 
            kprint_newline(); 
        } else if (key == '\b') {
            if (buffer_index > 0) {
                buffer_index--; 
                current_loc -= 2; 
                vidptr[current_loc] = ' ';
                vidptr[current_loc + 1] = 0x07;
            }
        } else if (key > 0 && buffer_index < BUFFER_SIZE - 1) {
            input_buffer[buffer_index++] = key; 
            vidptr[current_loc++] = key; 
            vidptr[current_loc++] = 0x07; 
        }
    }
}
