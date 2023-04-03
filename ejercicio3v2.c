#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char **vectorNombres;
    char *buff;
    int cantidadDeNombres;

    printf("Ingrese la cantidad de nombres: ");
    scanf("%d", &cantidadDeNombres);
    
    vectorNombres = (char**)malloc(cantidadDeNombres*sizeof(char*));
    buff = (char*)malloc(100*sizeof(char));

    puts("Ingrese los nombres");
    getchar();
    for (int i = 0; i < cantidadDeNombres; i++){
        gets(buff);
        vectorNombres[i] = (char*)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(vectorNombres[i], buff);
    }
    
    printf("Nombres:\r\n");
    for (int i = 0; i < cantidadDeNombres; i++){
        printf("%s\r\n", vectorNombres[i]);
        free(vectorNombres[i]);
    }

    free(buff);
    free(vectorNombres);

    return 0;
}