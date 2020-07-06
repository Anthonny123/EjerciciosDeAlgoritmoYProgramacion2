#include<stdio.h>
#include<stdlib.h>

int llenarvector(int *arr, int *n);
void mostrarvector(int *arr, int n);
void bubbleSort(int *arr, int n);
void simpleSort(int *arr, int n);
void selectionSort(int *arr, int n);
void insertSort(int *arr, int n);
void quickSort(int *arr, int izq, int der);
void swap(int *px, int *py);
int main(){
	int op = -1, arr_long = 0;
	int A[20];
	while(op!=0){
		printf("///////////Menu///////////\n");
		printf("1.- Llenar Vector\n");
		printf("2.- Mostrar Vector\n");
		printf("3.- Metodo de Ordenamiento - BubbleSort -\n");
		printf("4.- Metodo de Ordenamiento - Simple -\n");
		printf("5.- Metodo de Ordenamiento - Seleccion -\n");
		printf("6.- Metodo de Ordenamiento - Insercion -\n");
		printf("7.- Metodo de Ordenamiento - QuickSort -\n");
		printf("0.- Salir \n");
		scanf("%i", &op);
		switch(op){
			case 1: llenarvector(&A[0],&arr_long);
			break;
			case 2: mostrarvector(&A[0], arr_long);
			break;
			case 3: bubbleSort(&A[0], arr_long);
			break;
			case 4: simpleSort(&A[0], arr_long);
			break;
			case 5: selectionSort(&A[0], arr_long);
			break;
			case 6: insertSort(&A[0], arr_long);
			break;
			case 7: quickSort(&A[0], 0, arr_long - 1);
			break;
		}	
	}
	return 0;	
}

int llenarvector(int *arr, int *n){
	int i = 0;
	printf("Cual sera la longitud de su vector?\n");
	scanf("%d", n);
	if((*n<1)||(*n>21)){
		printf("Error!\n");
		system("pause");
		system("cls");
		return 0;
	}
	for(i = 0; i<*n; i++, arr++){
		printf("A[%i] = ", i);
		scanf("%d", arr);
	}
	system("pause");
	system("cls");
	return 0;
}

void mostrarvector(int *arr, int n){
	int i = 0;
	for(i = 0; i<n; i++){
		printf("A[%i] = %i\n", i, *(arr+i));
	}
	system("pause");
	system("cls");
}

void bubbleSort(int *arr, int n){
	int i = 0;
	int j = 0;
	int aux = 0, cont;
	for(i = 0; i<n-1; i++){
		cont = 0;
		for(j = 0; j<n-1-i; j++){// el -i se le coloca ya que va disminuyendo el nro de casillas chequeadas conforme avanzan los ciclos
			if(*(arr+j)>*(arr+j+1)){
				cont++;
				aux = *(arr+j);
				*(arr+j) = *(arr+j+1);
				*(arr+j+1) = aux;
				mostrarvector(arr, n);
			}
		}
		if(cont == 0) break;
		/* 
		Muestra de como se va realizando el procedimiento paso a paso
		
		*/
		
	}
	printf("//////////////////////Vector Ordenado///////////////////////\n");
	mostrarvector(arr, n);
	system("pause");
	system("cls");
}

void simpleSort(int *arr, int n){
	int i = 0;
	int j = 0;
	int aux = 0;
	for(i = 0; i<n-1; i++){
		for(j = i+1; j<n; j++){
			if(*(arr+i)>*(arr+j)){
				aux = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = aux;
			}
		}
		/*
		//Muestra como se realiza el procedimiento paso a paso
		printf("Pasada Nro.%i\n", i);
		mostrarvector(arr,n);
		*/
	}
	printf("//////////////////////Vector Ordenado///////////////////////\n");
	mostrarvector(arr, n);
	system("pause");
	system("cls");
}

void selectionSort(int *arr, int n){
	int i = 0;
	int j = 0;
	int min = 0, aux = 0;
	for(i = 0; i<n; i++){
		min = i; //guardamos la posicion del primero en min
		for(j = i+1; j<n; j++){
			if(*(arr + min) > *(arr + j)){
				min = j;//la posicion de J ahora va a ser el nuevo minimo
			}
		}
		aux = *(arr+i);
		*(arr + i) = *(arr + min);
		*(arr + min) = aux;// arr + min, seria la posicion de J
		printf("Swap Nro.%i\n", i+1);
		mostrarvector(arr, n);
	}
}

void insertSort(int *arr, int n){
	int pos, aux;
	int i = 0;
	for(i = 0; i < n; i++){
		pos = i;
		aux = arr[i];
		while((pos>0) && (arr[pos - 1]>aux)){
			arr[pos] = arr[pos - 1];
			pos--;
		};
		arr[pos] = aux;	
	};
	mostrarvector(arr, n);
};


void quickSort(int *arr, int izq, int der){
	if(izq>=der)return;
	int m = izq, n = der + 1, pivote = arr[izq];
	while(1==1){
		do m++; while(arr[m]<=pivote && (m<der));
		do n--; while(arr[n]>=pivote && (n>izq));
		if(m>=n)break;
		swap(&arr[m],&arr[n]);	
	};
	//arr[izq] = arr[n];
	//arr[n] = pivote;
	swap(&arr[n], &arr[izq]);
	quickSort(arr,izq,n-1);
	quickSort(arr, n+1, der);
};

void swap(int *px, int *py){
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
};
