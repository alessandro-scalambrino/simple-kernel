#ifndef IO_H
#define IO_H

/* Interrupt Descriptor Table (IDT), gate type/privilege leve, kernel code address x86*/
#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

char read_port(unsigned short port);  /*read from i/o port*/
void write_port(unsigned short port, unsigned char data); 
/*IDT stuff*/
void load_idt(unsigned long *idt_ptr);
void idt_init(void);

#endif /* IO_H */