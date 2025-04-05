#include "debug.h"

#ifdef  DEBUG
    #define ERROR_LOG(msg...) \
        printf("error : %s",msg);
#else
    #define ERROR_LOG(msg)
#endif

#define IS_NULL(x) x == NULL