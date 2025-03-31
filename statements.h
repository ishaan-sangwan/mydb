#ifndef STATEMENTS
#define STATEMENTS
#include "inputbuffer.h"
typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
}StatementType;

typedef struct {
    StatementType type;
}Statement;


typedef enum {
    PREPARE_SUCCESS, 
    PREPARE_UNRECOGNIZED_STATEMENT
}PrepareResults;

PrepareResults prepare_statement(InputBuffer* inputbuffer,
        Statement* statement);


#endif
