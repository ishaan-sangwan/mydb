#ifndef INPUTBUFFER
#define INPUTBUFFER
#include <stdio.h>
#include <sys/types.h>

typedef struct{
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer ;

InputBuffer* new_input_buffer();

void print_prompt();

void read_input(InputBuffer* inputbuffer);
#endif
