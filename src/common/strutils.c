#include "strutils.h"
#include <stdlib.h>
#include <string.h>
#include "common/types.h"

char* STR_CopyString(char* in)
{
    char* out = malloc((usize)strlen(in) + 1);
    strcpy(out, in);
    return out;
}