#include "debug.h"

#ifdef DEBUG
# define ERROR_LOG(fmt, ...)                      \
  {                                               \
        fprintf (stderr, "%s:%s():%d: ",              \
                                                 __FILE__, __func__, __LINE__);       \
        fprintf (stderr, fmt, ##__VA_ARGS__);         \
  }
#else
# define ERROR_LOG(...)
#endif

#define IS_NULL(x) x == NULL