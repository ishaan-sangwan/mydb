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
        int args_assigned = sscan(
            inputbuffer->buffer, "insert %d, %s, %s",
            &statement->row_to_insert.id,
            &statement->row_to_insert.username,
            &statement->row_to_insert.email
              );
        if (args_assigned < 3) {
            return PREPARE_SYNTAX_ERROR;
        } 
        return PREPARE_SUCCESS;
   }
  return PREPARE_UNRECOGNIZED_STATEMENT; 
}

