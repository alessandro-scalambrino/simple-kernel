#include "../../include/commands/commands.h"
#include "../../include/screen.h"
#include "../../include/io.h"

void clear_screen_command() {
    clear_screen();
}

void register_clear_command(command_t *commands, int *index) {
    commands[*index].name = "clear";
    commands[*index].handler = clear_screen_command;
    (*index)++;
}
