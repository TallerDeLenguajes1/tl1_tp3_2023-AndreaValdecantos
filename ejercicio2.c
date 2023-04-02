#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int produccion[5][12];

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 12; j++){
            produccion[i][j] = rand() % 40001 + 10000;
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 12; j++){
            printf("%7d", produccion[i][j]);
        }
        printf("\r\n");
    }

    return 0;
}