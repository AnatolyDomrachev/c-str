#include "my_strlen.h"

int my_strlen(char* str)
{
    int i = 0;
    while(str[i] != '\0')
        i++;
        
    return i;
}
