#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "statements.h"
#include "inputbuffer.h"

PrepareResults prepare_statement(InputBuffer* inputbuffer, 
                        Statement* statement){
   if ( strcmp(inputbuffer->buffer, "select") == 0  ){
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
   } 
   else if ( strncmp(inputbuffer->buffer, "insert", 6) == 0  ){
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
   }
  return PREPARE_UNRECOGNIZED_STATEMENT; 
}

