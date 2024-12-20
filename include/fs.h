#ifndef FS_H
#define FS_H

#define MAX_FILENAME_LENGTH 255
#define BLOCK_SIZE 512
#define NUM_BLOCKS 1024  // Number of data blocks
#define NUM_INODES 64    // Number of inodes (files - max 64)

// Inode structure: Describes a file (name, size, start block)
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    unsigned int size;
    unsigned int start_block;
} inode_t;

typedef struct {
    inode_t inodes[NUM_INODES];
    char blocks[NUM_BLOCKS][BLOCK_SIZE]; 
} simple_fs_t;

void fs_init();
int fs_create_file(const char *filename, const char *data, unsigned int size);
int fs_read_file(const char *filename, char *buffer);
int fs_write_file(const char *filename, const char *data, unsigned int size);
void fs_list_files();
int fs_find_file(const char *filename);

#endif // FS_H
