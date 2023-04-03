#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *vectorNombres[5];
    char *buff;

    buff = (char*)malloc(100*sizeof(char));

    puts("Ingrese los nombres");
    for (int i = 0; i < 5; i++){
        gets(buff);
        vectorNombres[i] = (char*)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(vectorNombres[i], buff);
    }
    
    printf("Nombres:\r\n");
    for (int i = 0; i < 5; i++){
        printf("%s\r\n", vectorNombres[i]);
        free(vectorNombres[i]);
    }

    free(buff);

    return 0;
}