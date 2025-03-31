#ifndef STATEMENTS
#define STATEMENTS
#include "inputbuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include "row.h"
typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
}StatementType;


typedef struct {
    StatementType type;
    Row row_to_insert;
}Statement;


typedef enum {
    PREPARE_SUCCESS, 
    PREPARE_UNRECOGNIZED_STATEMENT,
    PREPARE_SYNTAX_ERROR
}PrepareResults;

PrepareResults prepare_statement(InputBuffer* inputbuffer,
        Statement* statement);


#endif
