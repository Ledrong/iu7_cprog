#include "myfunctions.h"

int main()
{
    char str[MAX_STR][MAX_LEN_OF_WORD], newstr[MAX_STR][MAX_LEN_OF_WORD];
    
    int size = input_str(str);
    
    reverse_str(str, newstr, size);
}