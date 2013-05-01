#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){

double delta_x = 0.10;
double delta_t = 0.00003;
double alpha = delta_t/(delta_x*delta_x);
  
double *u_inicial;
double *u_pasada;
double *u_ahora;
double *u_nueva;

double *x;
double *t;

int n_t=100000;
int n_x=100;

int i;
int j;
int k;

//Alocacion de memoria para los arrays y mensaje de error
u_inicial = malloc(n_x*sizeof(double));  
u_pasada = malloc(n_x*sizeof(double));
u_ahora = malloc(n_x*sizeof(double));
u_nueva = malloc(n_x*sizeof(double));
x = malloc(n_x*sizeof(double));
t = malloc(n_t*sizeof(double));


if(!u_inicial || !u_pasada || !u_ahora || !u_nueva || !x || !t){
    printf("Problema con memoria");
    exit(1);
  }

//Se fijan las condiciones iniciales de la distribucion de calor
for(i = 0; i < n_x; i ++){
	
	x[i] = i*delta_x - 5.0;
	u_inicial[i] = 4*delta_x*i*(1-delta_x*i);
}

//Se construye el array con los tiempos
for(j = 0; j < n_t; j ++){
	
	t[j] = j*delta_t;

}

//Se fijan las condiciones de frontera
u_nueva[0] = 0.0;
u_nueva[n_x - 1] = 0.0;

//Se pasa u_inicial a u_ahora
for (i = 1; i < n_x-1; i ++){

u_nueva[i] = alpha*u_inicial[i+1] + (1.0 - 2.0*alpha)*u_inicial[i]+alpha*u_inicial[i-1];
u_ahora[i] = u_nueva[i];

}

//Se itera para conseguir el estado de la funcion en 10 tiempos distintos
for(k = 0; k < 10; k ++){

	char num[20];
	int temp = 10 + k;
	sprintf(num, "%d", temp);
	FILE *export;
	export = fopen(strcat(num,".dat"), "w");
	
	
	for (j = 0; j < (n_t*k/100); j ++)
	{	
		for (i = 1; i < n_x-1; i ++)	
		{
			u_nueva[i] = alpha*u_ahora[i+1] + (1.0 - 2.0 * alpha)*u_ahora[i]+alpha*u_ahora[i-1];
			u_ahora[i] = u_nueva[i];
		}
		
	}


	for (i = 0; i < n_x; i ++){

		fprintf(export,"%e %e \n", x[i],u_ahora[i]);
		
	}
	fclose(export);
}

return 0;
}
