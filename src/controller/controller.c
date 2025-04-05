#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define loop while(1)
#define PAGE_DEFAULT_SIZE 4096

#include "controller.h"

controller *
new_controller(const char *host, uint16_t port, pkey_public public_key)
{
    controller *object = malloc(sizeof(controller));
    if (object == NULL) {
        ERROR_LOG("malloc")
        return NULL;
    }
    OSSL_LIB_CTX *libctx = NULL;
    const char *propquery = NULL;

    object->openssl_config.ctx  = EVP_PKEY_CTX_new_from_pkey(libctx,public_key,propquery);
    if(IS_NULL(object->openssl_config.ctx))
    {
        ERROR_LOG("new_controller -> contex is null")

        return;
    }

    object->host = host;
    object->port = port;

    return object;
}

void
controller_start(controller *controller)
{
    int client_socket = NULL;
    if(IS_NULL(controller))
    {   
        ERROR_LOG("controller pointer is null")
        return;
    }

    if(client_socket = socket(AF_INET,SOCK_STREAM,0), IS_NULL(client_socket))
    {   
        ERROR_LOG("socket is null")
        
        return;
    }

    struct sockaddr_in address = {
        AF_INET,
        htons(controller->port)
    };
    address.sin_addr.s_addr  = inet_addr(controller->host);

    int connection_server = connect(client_socket,(struct sockaddr*)&address, sizeof(struct sockaddr_in));
    if (connection_server == -1)
    {
        ERROR_LOG("connection")

        close(client_socket);
        return;
    }

    loop {
        pstring_t str = new_string(PAGE_DEFAULT_SIZE);

        str->len = recv(client_socket,str->buffer,PAGE_DEFAULT_SIZE,0);
        if(str->len != PAGE_DEFAULT_SIZE)
            resize_string(str,str->len);
        
        pstring_t buffer = rsa_encrypt(str->buffer,str->len,controller->openssl_config.ctx);
        if(!buffer) {
            goto next;
        }
        
        
        // create thread

        next:
            free(str);
            continue;
    }
}

void        
controller_free(void *controller)
{
    if(IS_NULL(controller))
    {   
        ERROR_LOG("controller pointer is null");

        return;
    }

    free(controller);
}



