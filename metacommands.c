#include <stdio.h>
#include "metacommands.h"
#include <string.h>
#include <stdlib.h>

MetaCommandResult execute_meta_command(InputBuffer* inputbuffer){
    if ( strcmp(inputbuffer->buffer, ".exit") == 0){
        exit(EXIT_SUCCESS);
    }
    else {
        return META_COMMAND_NOT_RECOGNIZED;
    }
}
