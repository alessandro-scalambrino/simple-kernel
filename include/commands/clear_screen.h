#ifndef CLEAR_SCREEN_H
#define CLEAR_SCREEN_H

#include "./commands.h"

void clear_screen_command();
void register_clear_command(command_t *commands, int *index);

#endif // CLEAR_SCREEN_H
