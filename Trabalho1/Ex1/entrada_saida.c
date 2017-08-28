#include <stdio.h>
#include <stdlib.h>
#include "entrada_saida.h"

double ** coordenadas(){
    double **matriz = (double **)malloc(3 * sizeof(double*));;
    int i,j;

    for(i=0;i<3;i++){
        matriz[i] = (double *)malloc(3 * sizeof(double*));
		for(j=0;j<3;j++){
		    if(j==2){
			    matriz[i][j] =1;
            }
            else{
                scanf("%lf",&matriz[i][j]);
            }
        }
    }

    return matriz;
}

void circuloNaoViavel(){
    printf("Circulo nao viavel\n");
}

void centro(double x, double y){
    printf("Centro: (%lf, %lf)\n", x, y);
}

void ratio(double raio){
    printf("Raio: %lf\n",raio);
}