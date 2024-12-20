#include "../include/keyboard.h"
#include "../include/screen.h"
#include "../include/io.h"
#include "../include/lib/fakelib.h"


void read_user_input(char *buffer);
void execute_command(const char *input);
void login(char *entered_username);




void read_user_input(char *buffer) {
    while (!input_ready); 
    input_ready = 0;
    int i = 0;
    while (input_buffer[i] != '\0') {
        buffer[i] = input_buffer[i];
        i++;
    }
    buffer[i] = '\0';
}

void login(char *entered_username) {
    char entered_password[128];
    
    while (1) {
       
        kprint("Username: ");
        read_user_input(entered_username);
        
        kprint("Password: ");
        read_user_input(entered_password);
    
        kprint("Login successful!");
        break;
    }
}