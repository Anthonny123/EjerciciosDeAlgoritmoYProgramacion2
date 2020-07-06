#include<stdlib.h>
#include<stdio.h>



struct list {
	int value;
	list *next;
};

void insertElement(list **p, int x);
void showElements(list *p);
void removeElement(list **p, int x);
void insertElementInOrder(list **p, int x);
void removeLastTimeItAppears(list **p, int x);
void removeEqualElements(list **p, int x);
void checkIfIsItFound(list *p, int x);
void returnBoxFound(list *p, int x);
void deletePrimeNumbers(list **p);
void deleteOddNumbers(list **p);
void deleteOddNumbersOfDigits(list **p);
void deleteFoundNumbers(list **p);
void deleteCapicuaNumbers(list **p);
void deleteCommomElements(list **p);
void flipList(list **p);
void quickSort(list **p, int posIzq, int posDer);
void searchAndDestroy2lists(list *p, list *q);


int main(){
	int x = 0;
	int a = 0;
	int b = 10;
	list *p = NULL; 
	list *q = NULL;
	int op = -1;
	while(op!=0){
		system("cls");
		printf("Menu Lista\n");
		printf("1.-Insertar un valor a la lista A\n");
		printf("2.-Insertar un valor en orden ascendente en la lista\n");
		printf("3.-Eliminar un valor de la lista\n");
		printf("4.-Eliminar el ultimo elemento repetido de la lista\n");
		printf("5.-Eliminar tpdps los elementos repetidos de la lista\n");
		printf("6.-Chequear si un elemento se encuentra en la lista\n");
		printf("7.-Devolver el numero buscado en casillas\n");
		printf("8.-Eliminar numeros primos de la lista\n");
		printf("9.-Eliminar numeros primos de la lista\n");
		printf("10.-Eliminar todos los numeros cuya cantidad de digitos sea impar\n");
		printf("11.-Eliminar todos los numeros que contienen al menos un digito 3, 5 o 7\n");
		printf("12.-Eliminar todos los numeros Capicuas\n");
		printf("13.-Eliminar todos los numeros Comunes\n");
		printf("14.-Voltear lista\n");
		printf("15.-Metodo de Ordenamiento -QuickSort-\n");
		printf("16.-Insertar un valor a la lista B\n");
		printf("17.-Contar Elementos comunes en la lista\n");
		printf("18.-Mostrar Lista\n");
		scanf("%i", &op);
		switch(op){
			case 1:
				printf("\nEscriba el numero que desee Insertar en la lista 1\n");
				scanf("%i",&x);
				insertElement(&p, x);
			break;
			case 2:
				printf("\nEscriba el numero que desee Insertar en la lista\n");
				scanf("%i",&x);
				insertElementInOrder(&p, x);
			break;
			case 3:
				printf("\nEscriba el numero que desee eliminar en la lista\n");
				scanf("%i",&x);
				removeElement(&p, x);
			break;
			case 4:
				printf("\nEscriba el numero que desee eliminar en la lista\n");
				scanf("%i",&x);
				removeLastTimeItAppears(&p, x);
			break;
			case 5:
				printf("\nEscriba el numero que desee eliminar en la lista\n");
				scanf("%i",&x);
				removeEqualElements(&p, x);
			break;
			case 6:
				printf("\nEscriba el numero que desee chequear en la lista\n");
				scanf("%i",&x);
				checkIfIsItFound(p, x);
			break;
			case 7:
				printf("\nEscriba el numero que desee chequear en la lista\n");
				scanf("%i",&x);
				returnBoxFound(p, x);
			break;
			case 8: deletePrimeNumbers(&p);
			break;
			case 9: deleteOddNumbers(&p);
			break;
			case 10: deleteOddNumbersOfDigits(&p);
			break;
			case 11: deleteFoundNumbers(&p);
			break;
			case 12: deleteCapicuaNumbers(&p);
			break;
			case 13: deleteCommomElements(&p);
			break;
			case 14: flipList(&p);
			break;
			case 15:
				for(struct list *aux = p; aux!=NULL; a++, aux=aux->next);
				quickSort(&p, 0, (a-1));
				a = 0;
				break;
			case 16:{
				printf("\nEscriba el numero que desee Insertar en la lista numero 2\n");
				scanf("%i",&x);
				insertElement(&q, x);
				break;
			}
			case 17:searchAndDestroy2lists(p,q);
			break;
			case 18: 
			showElements(p);
			showElements(q);
			break;
		}
	}
}

void swap(int *px, int *py){
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
};

void showElements(list *p){
	list *tmp = p;
	if(!tmp){//Si a donde apunta temp = NULL, muestra un mensaje que diga que no existe una lista
		printf("No hay nunguna lista creada\n");
		system("pause");
		return;	
	}
	printf("Inicio");
	while(tmp){
		printf("->[%i]", tmp->value);
		tmp = tmp->next;
	};
	printf("->NULL\n");
	system("pause");
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////1.1) Inserte un valor X dado (sin repeticiones)                       ///////////////
///////////////     1.1.1) Por la cabeza de la lista                                 ///////////////
///////////////     1.1.2) Por el final de la lista                                  ///////////////
///////////////     1.1.3) Ordenadamente (En forma ascendente)                       ///////////////
///////////////     1.1.4) Luego de un valor "Y" dado (sino existe "Y" no se inserta)///////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////*/

/////////// Ejercicios 1.1.1 y 1.1.2 ///////////
void insertElement(list **p, int x){
	list *tmp = *p;
	if(tmp){ //Si existe una lista, crea una nueva estructura y la agrega al final de la lista existente
		while((tmp->next!=NULL)){
			tmp = tmp->next;
		}
		list *aux = new list;
		aux->value = x;
		aux->next = NULL;
		tmp->next = aux;
	}else{//Si no existe crea una lista con un nuevo valor
		tmp = new list;
		tmp->value = x;
		tmp->next = *p;
		*p = tmp;
	}
}

/////////// Ejercicios 1.1.3 ///////////
void insertElementInOrder(list **p, int x){
	list *tmp = *p;
	if(tmp){
		while((tmp->next)&&(tmp->next->value)<=x){
			tmp = tmp->next;
		}
		list *aux = new list;
		aux->value = x;
		aux->next = tmp->next;
		tmp->next = aux;
	}
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////1.2) Elimine un valor X dado en la lista                              ///////////////
///////////////     1.2.1) La primera vez que lo encuentre                           ///////////////
///////////////     1.2.2) La última de las veces que aparece en la lista            ///////////////
///////////////     1.2.3) Todas las veces que se encuentra en la lista              ///////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////*/

/////////// Ejercicios 1.2.1 ///////////
void removeElement(list **p, int x){
	list *tmp = *p;
	if(tmp){
		if(tmp->value == x){
			*p = (*p)->next;
			delete(tmp);
		}else{
			while((tmp->next)&&(tmp->next->value!=x)){
				tmp = tmp->next;	
			}
			if(tmp->next){
				list *aux = tmp->next;
				tmp->next = tmp->next->next;
				delete(aux);
			}
		}
	}
}

/////////// Ejercicios 1.2.2 ///////////
void removeLastTimeItAppears(list **p, int x){
	list *tmp = *p;
	list *tmpCopy = NULL;
	list *aux =NULL;
	if(tmp){
		while(tmp->next){
			if(tmp->next->value == x){
				tmpCopy = tmp;
				aux = tmp->next;
			}
			tmp = tmp->next;
		}
		if(!aux){
			printf("%i No se encuentra en la lista\n",x);
			system("pause");
			return;
		}else{
			tmp = tmpCopy;
			tmp->next = tmp->next->next;
			delete(aux);	
		}
	}
}

/////////// Ejercicios 1.2.3 ///////////
void removeEqualElements(list **p, int x){
	list *tmp = *p;
	list *aux2 = NULL;
	if(tmp){
		while(tmp->next){
			if(tmp->next->value==x){
				list *aux = tmp->next;
				tmp->next = tmp->next->next;
				delete(aux);
			}else{
				tmp = tmp->next;
			}
			//tmp = tmp->next;
		}
		if((*p)->value==x){//Luego de que elimina todos los numeros repetidos, vuelve al inicio y chequea el primero, si el primero es el numero que se desea eliminar, se elimina tambien
			tmp = *p;
			*p = (*p)->next;
			delete(tmp);
		}
	}
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////1.3) Busque un valor X dado en una lista                              ///////////////
///////////////      1.3.1) Devuelva True/False                                      ///////////////
///////////////      1.3.2) Devuelva el apuntador a la casilla que lo contiene       ///////////////
///////////////      1.3.2.1) La primera vez que lo encuentra                        ///////////////
///////////////      1.3.2.2) La última vez que aparece en la lista                  ///////////////
///////////////      1.3.3) Cuantas veces aparece en la lista                        ///////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////*/

/////////// Ejercicios 1.3.1 ///////////

void checkIfIsItFound(list *p, int x){
	int exist = 0;
	if(p){
		while((p->next)&& exist == 0){
			if(p->value == x){
				printf("El Numero %i se encuentra en la lista\n", x);
				exist = 1;
				system("pause");
			}
			p = p->next;
		}
		if(exist == 0){
			printf("El numero %i no se encuentra en la lista\n", x);
			system("pause");
		}		
	}else{
		printf("No hay una lista con valores definida\n");
		system("pause");
	}

}
/////////// Ejercicios 1.3.2.1, 1.3.2.2, 1.3.3 ///////////
void returnBoxFound(list *p, int x){
	list *tmp = p;
	list *firstTime = NULL;
	list *lastTime = NULL;
	int countFirst = 0;
	int countLast = 0;
	int count = 0;
	int timesItAppears = 0;
	if(tmp){
		while(tmp->next){
			if(tmp->value == x){
				if(!firstTime){
					firstTime = tmp;
					countFirst = count;
					timesItAppears++;
				}else{
					lastTime = tmp;
					countLast = count;
					timesItAppears++;
				}
			}
			tmp = tmp->next;
			count++;
		}
		if(!firstTime){
			printf("Ese elemento no se encuentra en la lista\n");
			system("pause");
		}else if(firstTime&&!lastTime){
			printf("Solo se encontro el elemento que contiene a %i la casilla %i\n", firstTime->value, countFirst);
			system("pause");
		}else{
			printf("Se encontro el elemento %i veces.\n", timesItAppears);
			printf("Se encontro el elemento %i en la casilla %i la primera vez.\n", firstTime->value, countFirst);
			printf("Se encontro el elemento %i en la casilla %i la ultima vez.\n", lastTime->value, countLast);
			system("pause");
		}
		
	}
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////1.4) Elimine en la lista                                              ///////////////
///////////////      1.4.1) Todos los números primos que contiene                    ///////////////
///////////////      1.4.2) Todos los números impar que contiene                     ///////////////
///////////////      1.4.3) Todos los números cuya cantidad de digitos sea impar     ///////////////
///////////////      1.4.4) Todos los números que contienen al menos un digito 3,5 o 7 /////////////
///////////////      1.4.5) Todos los números capicúa                                ///////////////
///////////////      1.4.6) Todos los números repetidos                              ///////////////
///////////////      1.4.6.1) Dejando sólo la primera ocurrencia                     ///////////////
///////////////      1.4.6.2) Dejando sólo la última ocurrencia                      ///////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////*/

/////////// Ejercicios 1.4.1 ///////////
int nprime(int x){
	int n = x, i, prime = 1;
	for(i = 2; i < n && prime==1; i++){
		if(n % i == 0){prime = 0;}
	}
	return prime;
}

void deletePrimeNumbers(list **p){
	list *tmp = *p;
	int prime = 0;
	if(tmp){
		while(tmp->next!=NULL){
			prime = nprime(tmp->next->value);
			if(prime){
				list *aux = tmp->next;
				tmp->next = tmp->next->next;
				delete(aux);
			}else{
				tmp = tmp->next;	
			}
		}
		///////Chequeamos la primera casilla//////
		prime=nprime((*p)->value);
		if(prime){
			tmp = *p;
			*p = (*p)->next;
			delete(tmp);
		}
	}else{
		printf("No existe ninguna lista\n");
		system("pause");
	}
}

/////////// Ejercicios 1.4.2 ///////////
void deleteOddNumbers(list **p){
	list *tmp = *p;
	if(tmp){
		while(tmp->next!=NULL){
			if((tmp->next->value)%2!=0){
				list *aux = tmp->next;
				tmp->next = tmp->next->next;
				delete(aux);
			}else{
				tmp = tmp->next;
			}
		}
		///////Chequeamos la primera casilla//////
		if(((*p)->value)%2!=0){
			tmp = *p;
			*p = (*p)->next;
			delete(tmp);
		}
	}else{
		printf("No existe ninguna lista\n");
		system("pause");
	}
}

int oddDigits(int x){
	int times;
	for(times = 1; x>=10; times++){
		x = x/10;
	}
	return times;
}

/////////// Ejercicios 1.4.3 ///////////
void deleteOddNumbersOfDigits(list **p){
	list *tmp = *p;
	int digits = 0;
	if(tmp){
		while(tmp->next!=NULL){
			digits = oddDigits(tmp->next->value);
			if(digits%2!=0){
				list *aux = tmp->next;
				tmp->next = tmp->next->next;
				delete(aux);
			}else{
				tmp = tmp->next;
			}
		}
		digits = oddDigits((*p)->value);
		if(digits%2!=NULL){
			tmp = *p;
			*p = (*p)->next;
			delete(tmp);
		}
	}else{
		printf("No existe ninguna lista\n");
		system("pause");	
	}
}


/////////// Ejercicios 1.4.4 ///////////
int foundNumbers(int x){
	int nfound = 0;
	while((x>=10)&&(nfound)==0){
		if(x%10==3||x%10==5||x%10==7){
			nfound = 1;
		}
		x = x/10;
	}
	if(nfound==0){
		if(x%10==3||x%10==5||x%10==7){
			nfound = 1;
		}
	}
	return nfound;
}

void deleteFoundNumbers(list **p){
	list *tmp = *p;
	int found = 0;
	if(tmp){
		while(tmp->next!=NULL){
			found = foundNumbers(tmp->next->value);
			if(found == 1){
				list *aux = tmp->next;
				tmp->next = tmp->next->next;
				delete(aux);
			}else{
				tmp = tmp->next;
			}
		}
		found = foundNumbers((*p)->value);
		if(found == 1){
			tmp = *p;
			*p = (*p)->next;
			delete(tmp);
		}
	}else{
		printf("No existe ninguna lista\n");
		system("pause");		
	}
}

/////////// Ejercicios 1.4.5 ///////////
int flipNumber(int x){////Metodo para voltear el numero////
	int n = 0;
	while(x>0){
		n = (n*10)+(x%10);
		x = x/10;
	}
	return n;
}

void deleteCapicuaNumbers(list **p){
	list *tmp = *p;
	int capicua = 0;
	if(tmp){
		while(tmp->next!=NULL){
			capicua = flipNumber(tmp->next->value);////Guardo el numero copiado en una variable interna de la funcion
			if(tmp->next->value == capicua){////Si el valor de la siguiente casilla de la lista es igual a capicua, entonces elimino
				list *aux = tmp->next;
				tmp->next = tmp->next->next;
				delete(aux);
			}else{
				tmp = tmp->next;///Si no lo es, continua a la siguiente casilla 
			}
		}
		capicua = flipNumber((*p)->value);
		if((*p)->value == capicua){
			tmp = *p;
			*p = (*p)->next;
			delete(tmp);
		}
	}else{
		printf("No existe ninguna lista\n");
		system("pause");
	}
}

/////////// Ejercicios 1.4.6 ///////////
void searchAndDestroy(list *q){
	list *tx = q, *aux = NULL, *del = NULL;
	aux = tx;
	while(aux->next){
		if(aux->next->value == tx->value){
			del = aux->next;
			aux->next = aux->next->next;
			delete(del);	
		}else{
			aux = aux->next;	
		}
	}
}

void deleteCommomElements(list **p){
	list *tmp = *p;
	if(tmp){
		while(tmp){
			searchAndDestroy(tmp);
			tmp = tmp->next;
		}
	}else{
		printf("No existe ninguna lista creada");
	}
}

/////////// Ejercicio Voltear lista ///////////

void flipList(list **p){
	list *tmp = *p;
	list *aux = NULL;
	if(tmp){
		while(tmp){
			list *t = new list;
			t->value = tmp->value;
			t->next = aux;
			aux = t;
			*p = (*p)->next;
			delete(tmp);
			tmp = *p;	
		}
	}else{
		printf("No hay ninguna lista creada\n");
		system("pause");
	}
	*p = aux;
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////1.6) Metodos de Ordenamiento                                          ///////////////
///////////////      1.6.1) QuickSort                                                ///////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////*/

/////////// Ejercicio 1.6.1 ///////////

struct list *backPos(struct list *p, int x){
	int pos = 0;
	while(pos<x){
		p = (p)->next;
		pos++;
	}
	return p;
}

void quickSort(list **p, int posIzq, int posDer){
	list *tmp = *p; 
	if(tmp){
		if(posIzq>=posDer)return;
		list *positionL = backPos(tmp, posIzq); list *positionR = backPos(tmp, posDer);
		int pivot = positionL->value;
		int m = posIzq, n = posDer +1;
		while(1){
			do{
				m++;
				positionL = positionL->next;
			}while((positionL->value<=pivot) &&(m < posDer));
			do{
				n--;
				positionR = backPos(tmp, n);
			}while((positionR->value>=pivot)&& (n>posIzq));
			if(m>=n)break;
			swap(&positionR->value, &positionL->value);	
		}
		positionL = backPos(tmp,posIzq);
		swap(&positionL->value, &positionR->value);
		quickSort(&(*p),posIzq,n-1);
		quickSort(&(*p),n+1,posDer);
	}else{
		printf("No se encontro una lista para ordenar\n");
		system("pause");
	}
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////// 2) Dadas dos listas A y B de enteros                                         ///////////////
///////////////		2.1.1) Cuente los elementos comunes                                      ///////////////
/////////////// 	2.1.2) Cuente los elementos comunes (aquí si necesita una lista auxiliar)///////////////
///////////////		2.1.2) Borre en A todas las veces que aparezca u elemento común con B    ///////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////*/

//////////////Ejercicio 2.1.1//////////////
void searchAndDestroy2lists(list *p, list *q){
	list *tx = p;
	list *ty = q;
	int cNumbers = 0;
	if(tx && ty){
		while(tx){
			while(ty){
				if(tx->value == ty->value){
					cNumbers++;
					ty = ty->next;
				}else{
					ty = ty->next;
				}
			}
			ty = q;
			tx = tx->next;	
		}
	}
	if(cNumbers>0)cNumbers++;
	printf("Hay %i elementos comunes\n", cNumbers);
	system("pause");
}

//////////////Ejercicio 2.1.2//////////////

