#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "errors.h"

#include <stdint.h>
#include <openssl/evp.h>

#include "rsa.h"

typedef struct { 
    const char  *host;
    uint16_t    port;

    
    struct {
        EVP_PKEY_CTX   *ctx;
    } openssl_config;   
} controller;

controller *new_controller(const char* host, uint16_t port, PKEY_PUBLIC public_key);

void        controller_start(controller *controller);
void        controller_free(void *controller);
#endif