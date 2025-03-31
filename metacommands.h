#ifndef METACOMMANDS
#define METACOMMANDS
#include "inputbuffer.h"

typedef enum{
    META_COMMAND_SUCCESS,
    META_COMMAND_NOT_RECOGNIZED
} MetaCommandResult;

MetaCommandResult execute_meta_command(InputBuffer* inputbuffer);

#endif
