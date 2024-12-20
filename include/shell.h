#ifndef SHELL_H
#define SHELL_H


void read_user_input(char *buffer);
void execute_command(const char *input);
char* login(char *entered_username);

#endif /* SHELL_H */
