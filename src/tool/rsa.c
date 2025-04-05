#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/err.h>
#include <openssl/decoder.h>
#include <openssl/core_names.h>

#include "rsa.h"

pkey_public 
init_public_key(void *buffer)
{
    if(IS_NULL(buffer))
    {
        ERROR_LOG("init_public_key -> buffer is null")

        return NULL;
    }

    EVP_PKEY *public_key = PEM_read_PUBKEY((FILE*)buffer ,NULL, NULL, NULL);
    if(IS_NULL(public_key))
    {
        ERROR_LOG("init_public_key -> public_key is null")

        return NULL;
    }
    
    return public_key;
}

// PKEY_PRIVATE 
// init_private_key(void *buffer)
// {
//     if(IS_NULL(buffer))
//     {
//         ERROR_LOG("init_public_key -> buffer is null")

//         return;
//     }

    
//     EVP_PKEY *private_key = PEM_read_PrivateKey((FILE*)buffer ,NULL, NULL, NULL);
//     if(IS_NULL(private_key))
//     {
//         ERROR_LOG("init_public_key -> private_key is null")

//         return;
//     }
    
//     return private_key;
// }


pstring_t 
rsa_encrypt(const char *str, size_t len, EVP_PKEY_CTX *ctx)
{
    pstring_t buffer = malloc(sizeof(string_t));
    if(IS_NULL(buffer))
    {   
        ERROR_LOG("rsa_encrypt -> buffer is null")
        return;
    }


    int encypt_result = EVP_PKEY_encrypt_init(ctx);
    if(encypt_result <= 0)
    {   
#ifdef DEBUG
        switch (encypt_result)
        {
        case -2:
            ERROR_LOG("EVP_PKEY_encrypt_init -> -2 indicates the operation is not supported by the public key algorithm.")
            break;

        default:
            ERROR_LOG("EVP_PKEY_encrypt_init -> error")
        }
#endif 
        free(buffer);
        return NULL;
    }


    

    encypt_result = EVP_PKEY_encrypt(ctx,buffer->buffer,&buffer->len,str,len);
    if(encypt_result <= 0)
    {
#ifdef DEBUG
        switch (encypt_result)
        {
        case -2:
            ERROR_LOG("EVP_PKEY_encrypt_init -> -2 indicates the operation is not supported by the public key algorithm.\n")
            break;

        default:
            ERROR_LOG("EVP_PKEY_encrypt_init -> error\n")
        }
#endif 
    free(buffer);
    return NULL;
    }

    return buffer;
}

pstring_t
rsa_decrypt(const char* str, size_t len, EVP_PKEY_CTX *ctx)
{
    int decrypt_result = NULL;

    pstring_t buffer = malloc(sizeof(string_t));
    if(IS_NULL(buffer))
    {
        ERROR_LOG("decrypt -> buffer is null")

        return NULL;
    }


    if(
        (decrypt_result = EVP_PKEY_decrypt_init(ctx)), decrypt_result <= 0
    )
    {
#ifdef DEBUG
        switch (decrypt_result)
        {
        case -2:
            ERROR_LOG("EVP_PKEY_encrypt_init -> -2 indicates the operation is not supported by the public key algorithm.")
            break;

        default:
            ERROR_LOG("EVP_PKEY_encrypt_init -> error")
        }
#endif 
    free(buffer);
    return NULL; 
    }

    
    if(
        (decrypt_result = EVP_PKEY_decrypt(ctx,str,len,buffer->buffer,buffer->len)), decrypt_result = NULL
    )
    {
#ifdef DEBUG
        switch (decrypt_result)
        {
        case -2:
            ERROR_LOG("EVP_PKEY_encrypt_init -> -2 indicates the operation is not supported by the public key algorithm.")
            break;

        default:
            ERROR_LOG("EVP_PKEY_encrypt_init -> error")
        }
#endif 
    free(buffer);
    return NULL; 
    }

    return buffer;
}