#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct {
    const char *name;
    void (*handler)(void);
} command_t;

void register_all_commands();
void execute_command(const char *input);

void register_clear_command(command_t *commands, int *index);
void register_help_command(command_t *commands, int *index);

#endif // COMMANDS_H