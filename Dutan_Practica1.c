//Programacion II: Ayudantia: Punteros
//Hecho por Kevin Dutan el 15/10/2025

//librerias empleadas
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAXDIM 100

void menu(int *opcion){
	printf("Menu\n");
	printf("1. Intercambiar valores usando punteros\n");
	printf("2. Sumar elementos de un arreglo usando punteros\n");
	printf("3. Modificar arreglo desde una funcion\n");
	printf("4. Contar vocales en una cadena con punteros\n");
	printf("5. Ordenar un arreglo usando punteros\n");
	printf("6. Salir.\n");
	printf("Opcion a elegir:\n");
	scanf("%d", opcion);
	getchar();
}

void intercambio(int *entero1, int *entero2){
	int aux= *entero1;
	*entero1 = *entero2;
	*entero2 = aux;
}

void sumaElementos(int *suma){
	int vector[MAXDIM], dim, i;
	printf("Ingrese la cantidad de numeros a ingresar (max. 100):");
	scanf("%d", &dim);
	getchar();
	
	for(i=0; i<dim; i++){
		printf("Ingrese un numero entero: ");
		scanf("%d", (vector + i));
		getchar();
		*suma+= *(vector + i);
	}
	
}

void duplicar(int *vector, int dim){
	int i;
	printf("\nValores duplicados: ");
	for(i=0; i<dim; i++){
		*(vector+i)=2*(*(vector+i));
		printf("%d ", *(vector+i));
	}
	printf("\n");
}

void contarVocales(char *cadena){
	int i, cont=0;
	char *p=cadena;
	while(*p!='\0'){
		char c=*p;
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
		   c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
			cont++;
		}
		p++;
	}
	printf("Cantidad de vocales: %d\n", cont);
}

void ordenarArreglo(int *vector, int dim){
	int i, j, temp;
	for(i=0; i<dim-1; i++){
		for(j=i+1; j<dim; j++){
			if(*(vector+i)>*(vector+j)){
				temp=*(vector+i);
				*(vector+i)=*(vector+j);
				*(vector+j)=temp;
			}
		}
	}
	
	printf("\nArreglo ordenado: ");
	for(i=0; i<dim; i++){
		printf("%d ", *(vector+i));
	}
	printf("\n");
}

//funcion principal
int main(){
	int op=0;
	while(op!=6){
		menu(&op);
		switch(op){
			case 1:{//intercambiar valores usando punteros
				int a, b;
				printf("Ingrese el valor para el primer entero: ");
				scanf("%d", &a);
				getchar();
				printf("Ingrese el valor para el segundo entero: ");
				scanf("%d", &b);
				getchar();
				
				printf("Valores: %d; %d\n", a, b);
				intercambio(&a, &b);
				printf("Nuevos valores: %d; %d\n", a, b);
				break;
			}//sumar elementos de un arreglo usando punteros
			case 2:{
				int suma=0;
				sumaElementos(&suma);
				printf("Total de la suma del vector: %d\n", suma);
				break;
			}
			case 3:{//modificar un arreglo usando punteros
				int arreglo[MAXDIM/4], i, dim;
				printf("Ingrese la cantidad de elementos a generar: ");
				scanf("%d", &dim);
				getchar();
				srand(time(NULL));
				
				printf("Valores originales: ");
				for(i=0; i<dim; i++){
					*(arreglo+i)=rand()%100+1;
					printf("%d ", *(arreglo+i));
				}
				printf("\n");
				
				duplicar(arreglo, dim);
				break;
			}
			case 4:{//contar vocales en una cadena con punteros
				char cadena[MAXDIM];
				printf("Ingrese una cadena simple:\n");
				fgets(cadena, MAXDIM, stdin);
				cadena[strcspn(cadena, "\n")] = '\0';
				
				contarVocales(cadena);
				break;
			}
			case 5:{ //ordenar arreglo usando punteros
				int vector[MAXDIM], dim, i;
				printf("Ingrese la cantidad de numeros a ordenar: ");
				scanf("%d", &dim);
				getchar();
				
				for(i=0; i<dim; i++){
					printf("Numero %d: ", i+1);
					scanf("%d", (vector+i));
					getchar();
				}
				
				ordenarArreglo(vector, dim);
				break;
			}
			case 6:{
				printf("Saliendo del programa...\n");
				break;
			}
			default:{
				printf("Opcion no valida\n");
				break;
			}
		}
	}
	return 0;
}