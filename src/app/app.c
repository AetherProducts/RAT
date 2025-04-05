#define HOST "127.0.0.1"
#define PORT 2002


#include "controller.h"
#include "rsa.h"
#include "certificate.h"

char pem_certificate_public[CPUBLIC_SIZE] = {
    #include "../../cert/public_certificate.in"
};

// char pem_certificate_private[CPRIVATE_SIZE] = {
//     #include "../../cert/private_certificate.in"
// };



void
app(void)
{
    controller *controller = NULL;
    pcertificate certificate_public = NULL;
    pkey_public public_key = NULL;

    if(
        (certificate_public = init_certificate(pem_certificate_public, CPUBLIC_SIZE)), IS_NULL(certificate_public)
    )
    {
        ERROR_LOG("app -> certificate_public is null")
        return;
    }

    if((public_key = init_public_key(certificate_public)), IS_NULL(public_key))
    {
        ERROR_LOG("app -> public_key is null")
        return;
    }

    if((controller = new_controller(HOST, PORT, public_key)), IS_NULL(controller))
    {
        ERROR_LOG("app -> new_controller is null")

        return;
    }

    controller_start(controller);

    controller_free(controller);
}


