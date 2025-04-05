#include "certificate.h"





pcertificate 
init_certificate(void* ptr, size_t size)
{
    FILE *object = NULL;

    if(IS_NULL(ptr) || !size)
    {
        ERROR_LOG("init_certificate_public -> one param is null")
        return NULL;
    }

    if((object = tmpfile()), IS_NULL(object))
    {
        ERROR_LOG("init_certificate_public -> object is null")
        return NULL;
    }

    if(!fwrite(ptr,sizeof(ptr[0]), size, object))
    {
        ERROR_LOG("init_certificate_public -> fwrite is null")

        fclose(object);
        return NULL;
    }
    rewind(object);

    return object;
}