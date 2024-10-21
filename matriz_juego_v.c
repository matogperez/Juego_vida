//Juego de la vida. Primer intento

#include<stdio.h> //libreria standard input output
#include<stdlib.h> //librería standard en donde están la función rand 
#include<time.h> //Libreria para poder llamar la función de tiempo

int i,j,conteo,x; //creamos 4 espacios en la memoria para enteros

const int n = 100;  //creamos un espacio para un entero constante que será la base de la matriz

int matriz[100][100]; //Declaramos una matriz de nxn. En ste caso le damos explicitamente con número la matriz


//Declaramos la función principal
int main (void){
	
	//esta función genera una semilla para generar un número aleatorio. Dentro del primer paréntesis se pone "time" para indicar que el tiempo es lo que determinará la semilla.
	srand(time(NULL));	
	
	//el primer for con la instrucción de ejecutarse de 0 a n. El segundo for hace lo mismo.
	//Esto genera una matriz de dimensión 2 
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
		
			//Se le asigna un valor a la variable x que va de 0 a 99
			x=rand()%100;
			
			//Condicional para que en alrededor de un quinto de las veces haga 1
			if(x<20){
				matriz[i][j]=1;	
			
			//Condición para hacer 0 el resto de la matriz
			}
			else{
				matriz[i][j]=0;
		
			}	
		}
	
	}
	
	//Fors para imprimir la matriz
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			printf ("%i", matriz[i][j]);
		}
	printf("\n");
	}
	

}
