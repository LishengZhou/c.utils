// By: Lisheng Zhou

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "split.h"

// This function splits a string (s1) by a delimiter (s2)
char **split ( const char *s1, const char *s2) {

    char **lista;
    char *aux = (char*)malloc(strlen(s1) + 1);
    strcpy(aux, s1);
    char *token_Ptr;
    int i = 0;

    lista = (char **) malloc (sizeof (char *));
    token_Ptr = strtok(aux, s2);
    lista[i] = token_Ptr;
    i++;
    while(token_Ptr != NULL)
    {
        lista = (char **)realloc(lista, sizeof(char*) * (i + 1));
        token_Ptr = strtok(NULL, s2);
        lista[i] = token_Ptr;
        i++;
    }
    return lista;
}

/* Example
int main(){

        char **list;
        list = split("1,2,3,4,5", ",");
        printf ("%s\n", list[4]);
        free(list[0]);
        free(list);
        return 0;
}
*/
