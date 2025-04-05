#ifndef RSA_H
#define RSA_H

// extern includes
#include <openssl/rsa.h>
#include <openssl/evp.h>

#include "errors.h"
#include "type.h"

typedef EVP_PKEY* pkey_public;
//typedef EVP_PKEY* PKEY_PRIVATE;

pkey_public     init_public_key(void *buffer);
// PKEY_PRIVATE    init_private_key(void *buffer);

pstring_t       rsa_encrypt(const char* str, size_t len, EVP_PKEY_CTX *ctx);
pstring_t       rsa_decrypt(const char* str, size_t len, EVP_PKEY_CTX *ctx);

#endif