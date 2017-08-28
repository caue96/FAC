#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "operacoes.h"

//encontrando determinante
double determinante(double **matriz){
	double deter;
	return deter=((matriz[0][0]*matriz[1][1]*matriz[2][2])+(matriz[0][1]*matriz[1][2]*matriz[2][0])+(matriz[0][2]*matriz[1][0]*matriz[2][1]))-((matriz[2][0]*matriz[1][1]*matriz[0][2])+(matriz[2][1]*matriz[1][2]*matriz[0][0])+(matriz[2][2]*matriz[1][0]*matriz[0][1]));
}

double *xey(double **matriz){
	double *xEy = (double *)malloc(2 * sizeof(double*));
	double equacao1[4], equacao2[4], equacao3[4], deterA, deterAx, deterAy, raio;
	int i;

	//variável -2ax
	equacao1[0] = -2*matriz[0][0];
	equacao2[0] = -2*matriz[1][0];
	equacao3[0] = -2*matriz[2][0];
  
  	//variavel -2by
	equacao1[1] = -2*matriz[0][1];
	equacao2[1] = -2*matriz[1][1];
	equacao3[1] = -2*matriz[2][1];
	  
	//variavel a²
	equacao1[2] = matriz[0][0]*matriz[0][0];
	equacao2[2] = matriz[1][0]*matriz[1][0];
	equacao3[2] = matriz[2][0]*matriz[2][0];
  
    // variavel b²
	equacao1[3] = matriz[0][1]*matriz[0][1];
	equacao2[3] = matriz[1][1]*matriz[1][1];
	equacao3[3] = matriz[2][1]*matriz[2][1];
  
	// subtraindo equacao1- equacao2:
	for(i=0;i<4;i++){
		equacao1[i] = equacao1[i] - equacao2[i];
	}

  	// subtraindo: equacao2- equacao3;
	for(i=0;i<4;i++){
	  	equacao3[i] = equacao2[i] - equacao3[i];
	}
  
  	equacao1[2] = equacao1[2]+equacao1[3];
  	equacao3[2] = equacao3[2]+equacao3[3];
  
  	// usando a regra de cramer 
  	//calculando determinante de A
  	deterA =(equacao1[0]*equacao3[1]) - (equacao1[1]*equacao3[0]);
  	deterAx = (-equacao1[2]*equacao3[1])-(equacao1[1]*(-equacao3[2]));
  	deterAy = (equacao1[0]*(-equacao3[2]))-(-equacao1[2]*equacao3[0]);
  
  	//printf("deterA: %lf,deterAx: %lf,deterAy: %lf\n",deterA,deterAx,deterAy);
	xEy[0]= deterAx/deterA;
	xEy[1]= deterAy/deterA;
	
	return xEy;
}

double raio(double **matriz, double x, double y){
	double a, b, raio;
	a =	matriz[0][0];
	b = matriz[0][1];
	
	raio = (((x-a)*(x-a)) + ((y-b)*(y-b)));
	raio = sqrt(raio);

	return raio;
}