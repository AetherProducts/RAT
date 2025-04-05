#ifndef TYPE_H
#define TYPE_H

#include <stdint.h>
#include <string.h>

typedef struct
{
    char *buffer;
    size_t len;
} string_t;
typedef string_t* pstring_t;

pstring_t new_string(size_t len); 

void resize_string(pstring_t str, size_t len);


#endif