#include<stdio.h>
#include<stdlib.h>

int llenarVector(int *arr, int *n);
int mostrarVector(int *arr, int n);
void intercambio(int *px, int *py);
int bbleSort(int *arr, int n);
int qckSort(int *arr, int posI, int posD, int conteo);
void checkEficiencia(int *arr, int n);

int main(){
	int op = -1;
	int arr_long = 0;
	int nIntQckSort = 0;
	int A[20];
	while(op!=0){
		system("cls");
		printf("Menu Lista\n");
		printf("1.-Insertar un valor al vector\n");
		printf("2.-Mostrar vector\n");
		printf("3.-BubbleSort\n");
		printf("4.-QuickSort\n");
		printf("5.-Chequear Eficiencia de los algoritmos de Ordenamiento\n");
		scanf("%i", &op);
		switch(op){
		case 1: llenarVector(&A[0], &arr_long);
			break;
		case 2: mostrarVector(&A[0], arr_long);
			break;
		case 3: bbleSort(&A[0], arr_long);
			break;
		case 4: qckSort(&A[0], 0, arr_long - 1, nIntQckSort);
			break;
		case 5: checkEficiencia(&A[0], arr_long);
			break;
		}
	}
}

int llenarVector(int *arr, int *n){
	int i = 0;
	printf("Indique cual sera la longitud de su vector\n");
	scanf("%i",n);
	if(*n<1||*n>21){
		printf("El valor que introdujo es incorrecto, la longitud no debe exceder de 20 y no puede ser menor a 1\n");
		system("pause");
		system("cls");
		llenarVector(arr, n);
	}else{
		for(i=0; i<*n; arr++, i++){
			printf("A[%i]: ", i);
			scanf("%i", arr);
		}
		system("pause");
		system("cls");
	}
}

int mostrarVector(int *arr, int n){
	for(int i = 0; i<n; i++){
		printf("|%i|", *(arr+i));
	}
	printf("\n");
	system("pause");
	system("cls");
}

int bbleSort(int *arr, int n){
	int i = 0;
	int j = 0;
	int count;
	for(i = 0; i<n-1; i++){
		count = 0;
		for(j = 0; j<n-1-i; j++){
			if(arr[j]>arr[j+1]){
				count++;
				intercambio(&arr[j], &arr[j+1]);
			}
		}
		if(count == 0)break;
	}
}

int qckSort(int *arr, int posI, int posD, int conteo){
	if(posI>posD) return 0;
	int aux = conteo;
	int m = posI, n = posD + 1, pivote = arr[posI];
	while(1==1){
		do m++; while(arr[m]<=pivote&&(m<posD));
		do n--; while(arr[n]>=pivote&&(n>posI));
		if(m>=n)break;
		intercambio(&arr[m], &arr[n]);
		aux++;
	}
	intercambio(&arr[n],&arr[posI]);
	aux++;
	printf("Nro de intercambios hasta antes de la recursividad: %i\n", aux);
	system("pause");
	qckSort(arr, posI, n-1, aux);
	qckSort(arr, n+1, posD, aux);
	return aux;
}

void checkEficiencia(int *arr, int n){
	int countQ = 0;
	int nroInt = 0;
	int arr_aux[n];
	int i = 0;
	int aux = 0;
	for(i = 0; i<n; i++){
		arr_aux[i] = arr[i];
	}
	nroInt = qckSort(arr_aux, 0, n-1, 0);
	//mostrarVector(arr_aux, n);
	printf("Nro de intercambios: %i\n", nroInt);
	system("pause");
}

void intercambio(int *px, int *py){
	int aux;
	aux = *px;
	*px = *py;
	*py = aux;
};
