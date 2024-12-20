#include "../../include/commands/commands.h"
#include "../../include/screen.h"
#include "../../include/io.h"

void help_command() {
    kprint("Available commands:");
    kprint_newline();
    kprint("help - Show this help message");
    kprint_newline();
    kprint("clear - Clear the screen");
    kprint_newline();
}

void register_help_command(command_t *commands, int *index) {
    commands[*index].name = "help";
    commands[*index].handler = help_command;
    (*index)++;
}
