#include "../../include/commands/commands.h"
#include "../../include/screen.h"
#include "../../include/lib/fakelib.h"

#define MAX_COMMANDS 128

command_t command_table[MAX_COMMANDS];
int command_count = 0;

void register_all_commands() {
    register_clear_command(command_table, &command_count);
    register_help_command(command_table, &command_count);
    // Add additional command registration here.
}

void execute_command(const char *input) {
    for (int i = 0; i < command_count; i++) {
        if (strcmp(input, command_table[i].name) == 0) {
            command_table[i].handler();
            return;
        }
    }
    kprint("Unknown command: ");
    kprint(input);
    kprint_newline();
}
