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
        printf("Anio %d", i+1);
        for (int j = 0; j < 12; j++){
            printf("%7d", produccion[i][j]);
        }
        printf("\r\n");
    }

    //promedio de ganancia por año
    for (int i = 0; i < 5; i++){
        int suma = 0;
        float promedio = 0;
        for (int j = 0; j < 12; j++){
            suma += produccion[i][j];
        }
        promedio = (float)suma/12;
        printf("Promedio de ganancia anio %d: %.2f\r\n", i+1, promedio);
    }

    //valor máximo y mínimo
    int minimo = 50000, maximo = 10000, mesMinimo, mesMaximo, anioMinimo, anioMaximo;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 12; j++){
            if (produccion[i][j] <= minimo){
                minimo = produccion[i][j];
                mesMinimo = j + 1;
                anioMinimo = i + 1;
            }
            if (produccion[i][j] >= maximo){
                maximo = produccion[i][j];
                mesMaximo = j + 1;
                anioMaximo = i + 1;
            }
        }
    }
    printf("Valor minimo: %d\tMes: %d\tAnio: %d\r\n", minimo, mesMinimo, anioMinimo);
    printf("Valor maximo: %d\tMes: %d\tAnio: %d\r\n", maximo, mesMaximo, anioMaximo);
    

    return 0;
}