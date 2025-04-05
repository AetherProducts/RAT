#include "type.h"

pstring_t
new_string(size_t len)
{
    pstring_t str = malloc(sizeof(len));
    if(!str)
        return (void*)0;

    return str;
}

void
resize_string(pstring_t str, size_t len)
{
    char *buffer = (void*)0;
    if(!str)
        return;
    
    if((buffer = malloc(len)), !buffer)
        return;

    memcpy(buffer,str->buffer,len);
    free(str->buffer);
    
    str->buffer = buffer;
    str->len = len;
}