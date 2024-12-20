#include "../include/lib/fakelib.h"
#include "../include/io.h"
#include "../include/screen.h"

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

size_t strlen(const char *str) {
    size_t len = 0;
    while (*str++) {
        len++;
    }
    return len;
}

int strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}

char *strcpy(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++)) {}
    return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
    char *d = dest;
    size_t i;
    for (i = 0; i < n && *src; i++) {
        *d++ = *src++;
    }
    for (; i < n; i++) {
        *d++ = '\0';
    }
    return dest;
}

void *memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;
    const unsigned char *s = src;
    while (n--) {
        *d++ = *s++;
    }
    return dest;
}

void printdsk(const char *format, ...) {
    char buffer[256];
    va_list args;
    va_start(args, format);

    int i = 0;
    while (*format && i < sizeof(buffer) - 1) {
        if (*format == '%' && *(format + 1) == 's') {
            const char *str = va_arg(args, const char*);
            while (*str && i < sizeof(buffer) - 1) {
                buffer[i++] = *str++;
            }
            format++;
        } else {
            buffer[i++] = *format;
        }
        format++;
    }
    buffer[i] = '\0';
    va_end(args);

    kprint(buffer);  
}


