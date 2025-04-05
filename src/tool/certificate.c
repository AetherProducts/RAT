#include "../../includes/certificate.h"





PCERTIFICATE 
init_certificate(void* ptr, size_t size)
{
    if(IS_NULL(ptr) || IS_NULL(size))
    {
        ERROR_LOG("init_certificate_public -> one param is null")
        return NULL;
    }

    FILE*  object = tmpfile();
    if(IS_NULL(object))
    {
        ERROR_LOG("init_certificate_public -> object is null")
        return NULL;
    }

    if(IS_NULL(
        fwrite(ptr,sizeof(ptr[0]),size,object)
    ))
    {
        ERROR_LOG("init_certificate_public -> fwrite is null")

        fclose(object);
        return NULL;
    }
    rewind(object);

    return object;
}