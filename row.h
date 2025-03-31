#ifndef ROW
#define ROW

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

#include <stdlib.h>
typedef struct {
    u_int32_t id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
}Row;

#define size_of_attr(Struct, Attribute) sizeof(((Struct*)0)->Attribute) 

const u_int32_t ID_SIZE = size_of_attr(Row, id);
const u_int32_t USERNAME_SIZE = size_of_attr(Row, username);
const u_int32_t EMAIL_SIZE = size_of_attr(Row, email);

const u_int32_t ID_OFFSET = 0;
const u_int32_t USERNAME_OFFSET = ID_OFFSET+USERNAME_SIZE;
const u_int32_t EMAIL_OFFSET = USERNAME_OFFSET + EMAIL_SIZE;

const u_int32_t ROW_SIZE = ID_SIZE+EMAIL_SIZE+USERNAME_SIZE;

#endif
