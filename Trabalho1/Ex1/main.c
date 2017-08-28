#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"
#include "entrada_saida.h"
#include "variaveis.h"
#include "operacoes.c"
#include "entrada_saida.c"

int main()
{
	double *xEy = (double *)malloc(2 * sizeof(double*));
	double **matrizAux = (double **)malloc(3 * sizeof(double*));
	int i, j;
	CirculoStruct circulo;

	for(i=0;i<3;i++){
		matrizAux[i] = (double *)malloc(3 * sizeof(double*));
    }
	
	matrizAux = coordenadas();

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		    if(j==2){
			    circulo.matriz[i][j] =1;
            }
            else{
				circulo.matriz[i][j] = matrizAux[i][j];
            }
		}
	}
	
	if(determinante(matrizAux) == 0.0){
		circuloNaoViavel();
		return 0;
	}

	xEy = xey(matrizAux);

	circulo.x = xEy[0];
	circulo.y = xEy[1];

	circulo.raio = raio(matrizAux, circulo.x, circulo.y);
	
	ratio(circulo.raio);

	centro(circulo.x, circulo.y);

	return 0;
}