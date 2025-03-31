#include <sys/types.h>
#include <string.h>
#include "inputbuffer.h"
#include <stdlib.h>

InputBuffer* new_input_buffer(){
    InputBuffer* inputbuffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    inputbuffer->buffer = NULL;
    inputbuffer->buffer_length = 0;
    inputbuffer->input_length = 0;
    return inputbuffer;
}


void print_prompt(){
    printf("db > ");
}

void read_input(InputBuffer* inputbuffer){

    ssize_t bytes_read = getline( &(inputbuffer->buffer) , &(inputbuffer->buffer_length) , stdin);

    if (bytes_read <= 0) {
        printf("Error Reading input");
        exit(EXIT_FAILURE);

    }

    inputbuffer->input_length = bytes_read - 1 ;
    inputbuffer->buffer[bytes_read -1] = 0;


}
