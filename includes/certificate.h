#ifndef CERTIFICATION_H
#define CERTIFICATION_H

#define CPUBLIC_SIZE 460
#define CPRIVATE_SIZE 1732


#include <stdint.h>
#include <stdio.h>

#include "errors.h"

typedef FILE* PCERTIFICATE;


PCERTIFICATE init_certificate(void* ptr, size_t size);





#endif