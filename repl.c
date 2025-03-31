#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include "metacommands.h"
#include "inputbuffer.h"
#include "statements.h"

void close_input_buffer(InputBuffer* inputbuffer){
    free(inputbuffer->buffer);
    free(inputbuffer);
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

        Statement statement;
        switch (prepare_statement(input_buffer, &statement)){
            case PREPARE_SUCCESS:
                printf("Statement Compile successfully \n");
                break;
            case PREPARE_UNRECOGNIZED_STATEMENT:
                printf("Statement Compile failed \n");
                continue;
        }
    }
            
    return 0;
} 
