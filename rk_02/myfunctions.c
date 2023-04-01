#include "myfunctions.h"

int input_str(char str[MAX_STR][MAX_LEN_OF_WORD])
{
    int i = 0;
    
    FILE *file = fopen("in.txt", "r");
    
    while(!feof(file))
    {
        fgets(str[i], MAX_LEN_OF_WORD, file);
        
        printf("%s", str[i]);
        
        i++;
    }

    fclose(file);

    return i;
}


void reverse_str(char str[MAX_STR][MAX_LEN_OF_WORD], char newstr[MAX_STR][MAX_LEN_OF_WORD], int size)
{
    int k = 0, s = 0;
    
    for (int i = size - 1; i >= 0; --i)
    {
        for (int j = (int) strlen(str[i])-1; j >= 0; --j)
        {
            newstr[k][s] = str[i][j];
            s++;
        }
        newstr[k][s] = '\0';
        
        k++;
        
        s = 0;
    }
    
    for (int i = size - 1; i >= 0; --i)
    {
        printf("%s", newstr[k]);
    }
}