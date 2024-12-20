#ifndef FAKE_LIB_H
#define FAKE_LIB_H
#include <stddef.h>
#include <stdarg.h>
#include <stddef.h>

size_t strlen(const char *str);
int strcmp(const char *str1, const char *str2);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void printdsk(const char *format, ...);

#endif // FAKE_LIB_H
