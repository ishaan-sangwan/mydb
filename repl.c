#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer ;

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

void close_input_buffer(InputBuffer* inputbuffer){
    free(inputbuffer->buffer);
    free(inputbuffer);
}


typedef enum{
    META_COMMAND_SUCCESS,
    META_COMMAND_NOT_RECOGNIZED
} MetaCommandResult;

MetaCommandResult execute_meta_command(InputBuffer* inputbuffer){
    printf("the command to execute is %s \n", inputbuffer->buffer);
    if (strcmp(inputbuffer->buffer, ".exit") == 0) {
    exit(EXIT_SUCCESS);
      }
    else {
        return META_COMMAND_NOT_RECOGNIZED;
    }
}


int main(int argc, char* argv[]){
   InputBuffer* input_buffer = new_input_buffer(); 
    while(1){
        print_prompt();
        read_input(input_buffer);
    /* checking for meta commands */    
        if (input_buffer->buffer[0] == '.'){
        
        switch (execute_meta_command(input_buffer)){
            case META_COMMAND_SUCCESS:
                continue;
            case META_COMMAND_NOT_RECOGNIZED:
                printf("Meta command not recognized- %s \n", input_buffer->buffer);
            }
        }
    }
            
    return 0;
} 
