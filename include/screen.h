#ifndef SCREEN_H
#define SCREEN_H

#define BYTES_FOR_EACH_ELEMENT 2
#define COLUMNS_IN_LINE 80
#define ROWS_ON_SCREEN 25
#define SCREENSIZE (COLUMNS_IN_LINE * ROWS_ON_SCREEN * BYTES_FOR_EACH_ELEMENT)

void kprint(const char *str);
void kprint_newline(void);
void clear_screen(void);

/* current location and videomem-pointer*/
extern unsigned int current_loc;
extern char *vidptr;


#endif



