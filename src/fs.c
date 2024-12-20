#include "../include/fs.h"
#include "../include/lib/fakelib.h"

#include <string.h>
#include <stdio.h>

simple_fs_t simple_fs;  

//clear all inodes
void fs_init() {
    for (int i = 0; i < NUM_INODES; i++) {
        simple_fs.inodes[i].filename[0] = '\0';
        simple_fs.inodes[i].size = 0;
        simple_fs.inodes[i].start_block = 0;
    }
    printdsk("Filesystem initialized.\n");
}

int fs_create_file(const char *filename, const char *data, unsigned int size) {
    for (int i = 0; i < NUM_INODES; i++) {
        if (simple_fs.inodes[i].filename[0] == '\0') {
            strncpy(simple_fs.inodes[i].filename, filename, MAX_FILENAME_LENGTH - 1);
            simple_fs.inodes[i].filename[MAX_FILENAME_LENGTH - 1] = '\0';
            simple_fs.inodes[i].size = size;
            simple_fs.inodes[i].start_block = i;

            memcpy(simple_fs.blocks[i], data, size);
            printdsk("File '%s' created successfully.\n", filename);
            return 0;
        }
    }
    printdsk("Error: No space left for new files.\n");
    return -1;
}

int fs_read_file(const char *filename, char *buffer) {
    int file_idx = fs_find_file(filename);
    if (file_idx == -1) {
        printdsk("Error: File '%s' not found.\n", filename);
        return -1;
    }

    // Copy file data to buffer and null-terminate.
    memcpy(buffer, simple_fs.blocks[file_idx], simple_fs.inodes[file_idx].size);
    buffer[simple_fs.inodes[file_idx].size] = '\0';  // Null-terminate.
    printdsk("File '%s' read successfully.\n", filename);
    return simple_fs.inodes[file_idx].size;
}


int fs_write_file(const char *filename, const char *data, unsigned int size) {
    // Find the file by its name
    int file_idx = fs_find_file(filename);
    if (file_idx == -1) {
        printdsk("Error: File '%s' not found.\n", filename);
        return -1;
    }

    // Update file data in the corresponding block
    memcpy(simple_fs.blocks[file_idx], data, size);
    simple_fs.inodes[file_idx].size = size;  

    printdsk("File '%s' written successfully.\n", filename);
    return 0;
}

// List all files in the filesystem
void fs_list_files() {
    printdsk("Listing files:\n");
    for (int i = 0; i < NUM_INODES; i++) {
        if (simple_fs.inodes[i].filename[0] != '\0') {
            printdsk("- %s\n", simple_fs.inodes[i].filename);
        }
    }
}

//Search files, return i-node
int fs_find_file(const char *filename) {
    for (int i = 0; i < NUM_INODES; i++) {
        if (strcmp(simple_fs.inodes[i].filename, filename) == 0) {
            return i;  // Return inode index if file found
        }
    }
    printdsk("File not found\n");
    return -1;
}
