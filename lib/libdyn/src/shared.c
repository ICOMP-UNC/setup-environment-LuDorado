#include "shared.h"
#include <stdio.h>
#include <string.h>

int shared_lib_function(char* msg)
{
    printf("Hi! I'm shared lib that receives '%s',and return '%d'\n", msg, strlen(msg));
    return strlen(msg);
}
