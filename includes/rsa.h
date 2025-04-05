#ifndef RSA_H
#define RSA_H

#include <stdio.h>
// extern includes
#include <openssl/rsa.h>
#include <openssl/evp.h>

#include "errors.h"

typedef EVP_PKEY* PKEY_PUBLIC;
//typedef EVP_PKEY* PKEY_PRIVATE;


PKEY_PUBLIC     init_public_key(void *buffer);
//PKEY_PRIVATE    init_private_key(void *buffer);

typedef struct
{
    char    *buffer;
    size_t  len;
}RSA_STRING;

typedef RSA_STRING* PRSA_STRING;

PRSA_STRING rsa_encrypt(const char* str, size_t len, EVP_PKEY_CTX *ctx);


#endif