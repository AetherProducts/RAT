#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <arpa/inet.h>

#include "../../includes/controller.h"

#define loop while(1)

controller *
new_controller(const char *host, uint16_t port, PKEY_PUBLIC public_key)
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
    if(IS_NULL(controller))
    {   
        ERROR_LOG("controller pointer is null")
        return;
    }

    int client_socket = socket(AF_INET,SOCK_STREAM,0);

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
        // recv message 
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



