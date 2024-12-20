# Compiler, Assembler, Linker
CC = gcc
AS = nasm
LD = ld
SRC = ./src/
#Flags
CFLAGS =  -fno-stack-protector -m32
ASFLAGS = -f elf32
LDFLAGS = -m elf_i386 -T $(SRC)link.ld

# Source and Object Files
ASM_SRC = $(SRC)kernel.asm
C_SRC = $(SRC)kernel.c $(SRC)keyboard.c $(SRC)screen.c $(SRC)io.c $(SRC)shell.c $(SRC)fs.c $(SRC)fakelib.c $(SRC)/commands/commands.c $(SRC)/commands/clear_screen.c $(SRC)/commands/help.c#add .c here
ASM_OBJ = $(SRC)kasm.o
C_OBJ = $(C_SRC:.c=.o)  
OUTPUT = dsk-kernel

# Default Target
all: $(OUTPUT)

# ASM
$(ASM_OBJ): $(ASM_SRC)
	$(AS) $(ASFLAGS) $(ASM_SRC) -o $(ASM_OBJ)

# GCC
$(C_OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# linker
$(OUTPUT): $(ASM_OBJ) $(C_OBJ)
	$(LD) $(LDFLAGS) -o $(OUTPUT) $(ASM_OBJ) $(C_OBJ)

# Clean Target
clean:
	rm -f $(ASM_OBJ) $(C_OBJ) $(OUTPUT)
