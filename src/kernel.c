#include "../include/keyboard.h"
#include "../include/screen.h"
#include "../include/io.h"
#include "../include/shell.h"
#include "../include/fs.h"
#include "../include/lib/fakelib.h"
#include "../include/commands/commands.h"






void main(void)
{	
	char username[128];
	const char *str = "my first kernel with keyboard support";
	clear_screen();
	kprint(str);
	kprint_newline();
	kprint_newline();

	kprint("Loading command.....");  
	register_all_commands();

	kprint("Loading fs.....");
    kprint_newline();

	fs_init();

	
	kprint_newline();

	idt_init();
	kb_init();
	login(username);
	kprint_newline();
	kprint("Simple Shell: Type a command (e.g., help) and press Enter.");
    kprint_newline();
	

    while (1) {
		kprint(username);
		kprint(">");
        char input[128];
        read_user_input(input);
        execute_command(input);
    }

}
