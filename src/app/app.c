#define HOST "127.0.0.1"
#define PORT 2001

#include <stdio.h>

#include "../../includes/controller.h"
#include "../../includes/rsa.h"
#include "../../includes/certificate.h"

char pem_certificate_public[CPUBLIC_SIZE] = {
    #include "../../cert/public_certificate.in"
};

// char pem_certificate_private[CPRIVATE_SIZE] = {
//     #include "../../cert/private_certificate.in"
// };

void
app(void)
{

    PCERTIFICATE certificate_public = init_certificate(pem_certificate_public,CPUBLIC_SIZE);
    
    PKEY_PUBLIC public_key = init_public_key(certificate_public);


    controller *controller = new_controller(HOST,PORT,public_key);

    controller_start(controller);

    controller_free(controller);
}


