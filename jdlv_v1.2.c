//Juego de la vida. Segundo intento, simplificando la cuenta de los vecinos con fors en lugar de hacerlo directo

#include<stdio.h> //libreria standard input output
#include<stdlib.h> //librería standard en donde están la función rand 
#include<time.h> //Libreria para poder llamar la función de tiempo

int i,j,x,k,l; //creamos 5 espacios en la memoria para enteros

const int N = 100;  //creamos un espacio para un entero constante que será la base de la matriz

int matriz[100][100]; //Declaramos una matriz de nxn. En ste caso le damos explicitamente con número la matriz

int mconteo[100][100]; //Declaramos matriz para almacenar suma de vecinos de matriz original

//Declaramos la función principal
int main (void){
	
	//esta función genera una semilla para generar un número aleatorio. Dentro del primer paréntesis se pone "time" para indicar que el tiempo es lo que determinará la semilla.
	srand(time(NULL));	
	
	//el primer for con la instrucción de ejecutarse de 0 a n. El segundo for hace lo mismo.
	//Esto genera una matriz de dimensión 2 
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){
		
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
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){
			printf ("%i ", matriz[i][j]);
		}
	printf("\n");
	}
	
		int m=3;
	//fors para generar la matriz de las sumas de celdas vecinas
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){
		
			//Condición para borde izquierdo, suma las i-1 con los bordes derechos
			if((i==0)&&((j!=N-1)&&(j!=0))){
				
				for(l=0;l<3;l++){
					for (k=0;k<2;k++){
						
						mconteo[i][j] += matriz[i+k][j-1+l];
					}
				
				mconteo[i][j] += matriz[N-1][j-1+l];
				
				}
				
			mconteo[i][j] -= matriz[i][j];
			}
			
			
			
			//Condición borde derecho, suma las i+1 con el borde izquierdo
			else if(i==(N-1)&&((j!=N-1)&&(j!=0))){
				for(l=0;l<3;l++){
					for (k=0;k<2;k++){
						
						mconteo[i][j] += matriz[i-1+k][j-1+l];
					}
				
				mconteo[i][j] += matriz[0][j-1+l];
				
				}
			
			mconteo[i][j] -= matriz[i][j];
			
			}
			
			//Condición borde superior, suma j-1 con borde inferior
			else if((j==0)&&((i!=N-1)&&(i!=0))){
			
				for(l=0;l<3;l++){
					for(k=0;k<2;k++){
						
						mconteo[i][j] += matriz[i-1+l][j+k];
					}
				
				mconteo[i][j] += matriz[i-1+l][N-1];
				
				}
				
					
				mconteo[i][j] -= matriz[i][j];
			}
			
			//Condición borde inferior, suma j+1 con el borde superior
			else if(j==(N-1)&&((i!=0)&&(i!=N-1))){
			
				for(l=0;l<3;l++){
					for(k=0;k<2;k++){
						
						mconteo[i][j] += matriz[i-1+l][j-1+k];
					}
					
				mconteo[i][j] += matriz[i-1+l][0];
				
				}
				
				mconteo[i][j] -= matriz[i][j];

			}
			
			//Condición esquina superior izquierda, suma i-1 con borde izquierdo y j-1 con borde inferior
			else if((i==0)&&(j==0)){
			
				for(l=0;l<2;l++){
					for(k=0;k<2;k++){
					
						mconteo[i][j] += matriz[i+k][j+l];
					
					}
				
				mconteo[i][j] += matriz[N-1][j+l];
				mconteo[i][j] += matriz[i+l][N-1];
				
				}
				
				mconteo[i][j] += matriz[N-1][N-1];
				mconteo[i][j] -= matriz[i][j];
			}
			
			//Condición esquina superior derecha, suma i+1 con borde izquierdo y j-1 con borde inferior
			else if((i==N-1)&&(j==0)){
			
				for(l=0;l<2;l++){
					for(k=0;k<2;k++){
						
						mconteo[i][j] += matriz[i-1+k][j+l];
					}
				mconteo[i][j] += matriz[0][j+l];
				mconteo[i][j] += matriz[i-1+l][N-1];
				}
				mconteo[i][j] += matriz[0][N-1];
				mconteo[i][j] -= matriz[i][j];
				
				
			}
			
			//Condición esquina inferior izquierda, suma i-1 con borde derecho y j+1 con borde superior
			else if((i==0)&&(j==N-1)){
			
				for(l=0;l<2;l++){
					for(k=0;k<2;k++){
						mconteo[i][j] += matriz[i+k][j-1+l];
					}
					mconteo[i][j] += matriz[N-1][j-1+l];
					mconteo[i][j] += matriz[i+l][0];
				}
				mconteo[i][j] += matriz[N-1][0];
				mconteo[i][j] -= matriz[i][j];
				
			}
			
			//Condición esquina inferior derecha, suma i+1 con borde izquierdo y j+1 con borde superior
			else if((i==N-1)&&(j==N-1)){
			
				for(l=0;l<2;l++){
					for(k=0;k>2;k++){
					
						mconteo[i][j]+=matriz[i-1+k][j-1+l];
					
					}
					
					mconteo[i][j]+=matriz[i-1+l][0];
					mconteo[i][j]+=matriz[0][j-1+l];
					
				}
				
				mconteo[i][j]+=	matriz[0][0];
				mconteo[i][j]-= matriz[i][j];
			}
			
			//Condición para el resto de la matriz para sumar valor de vecions
			else{
				for(l=0;l<m;l++){
					for(k=0;k<m;k++){
						
						mconteo[i][j] += matriz[i-1+k][j-1+l];
					}
				}
				mconteo[i][j] -= matriz[i][j];
				
			}
		}
	}
	
	//Saltos de línea para distinguir matrices
	printf("\n\n");
	
	//fors para imprimir matriz de conteo
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){
		
			printf("%i ", mconteo[i][j]);
		}
		printf("\n");
	
	}

	
	return 0;
}
