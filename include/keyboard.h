#ifndef KEYBOARD_H
#define KEYBOARD_H

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define ENTER_KEY_CODE 0x1C
#define BUFFER_SIZE 128

extern unsigned int current_loc;
extern char *vidptr;
extern unsigned char keyboard_map[128]; 
extern char input_buffer[BUFFER_SIZE]; /* this is for the shell */
extern volatile int buffer_index;
extern volatile int input_ready;

void kb_init(void);
void keyboard_handler_main(void);
void keyboard_handler(void);
void kprint_newline(void);

#endif /* KEYBOARD_H */

