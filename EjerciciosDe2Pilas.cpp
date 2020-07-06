#include<stdio.h>
#include<stdlib.h>

struct lista{
	int valor;
	lista *prox;
};

struct pila{
	int valor;
	struct pila *prox;
};

int vacio (struct pila *p){
	return (p == NULL);
}

int tope(struct pila *p){
	if(!(vacio(p))){
		return (p->valor);
	}
	return 0;
}

void apilar(struct pila **p, int x){
	struct pila *t = new struct pila;
	t->valor = x;
	t->prox = (*p);
	(*p) = t;
}

void desapilar(struct pila **p){
	struct pila *t = *p;
	*p = (*p)->prox;
	delete(t);
}

void imprime(pila **p){
	int x;
	if(!(vacio(*p))){
		x = tope(*p);
		printf("| %i ", x);
		desapilar(p);
		imprime(p);
		apilar(p,x);
	}
}

void mostrar(struct pila **p, char c){
	struct pila *t = NULL;
	printf("\n\n\t  Pila %c \n\n\t(tope)", c);
	imprime(p);
	printf("| (fondo)\n\n");
}

void eliminar(lista **p, int x){
	if(*p)
		if((*p)->valor == x){
			lista *aux = (*p);
			(*p) = (*p)->prox;
			delete(aux);
		}else{
			eliminar(&(*p)->prox, x);
		}
}

/*///////////////////////////////////////////////////
///////////////////Mis Algoritmos.///////////////////
///////////////////////////////////////////////////*/

void insertarCola(struct pila **p, int x){
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		insertarCola(p, x);
		apilar(p, num);	
	}else{
		apilar(&(*p), x);	
	}
}

void voltearLista(struct pila **p){
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		voltearLista(p);
		insertarCola(p, num);
	}
}

int devolverSiSonIguales(struct pila **q, int x){
	int aux = 0;
	if(!vacio(*q)){
		int num = tope(*q);
		desapilar(q);
		aux = devolverSiSonIguales(q,x);
		apilar(q, num);
		if(x == num){
			return aux + 1;
		}
		return aux;
	}
}

int contarIgualesEnAmbasPilas(struct pila **p, struct pila **q){
	int aux = 0; int count = 0;
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		aux = devolverSiSonIguales(q, num);
		count = contarIgualesEnAmbasPilas(p,q);
		apilar(p, num);
		return count + aux;
	}
}

int insertarIgualesEnPilaAux(struct pila **p, struct pila **q, struct pila **r){
	pila *aux = NULL; int auxN = 0; int count = 0;
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		auxN = devolverSiSonIguales(q,num);
		count = insertarIgualesEnPilaAux(p,q,r);
		if(auxN){
			apilar(r, num);
		}
		apilar(p,num);
		return auxN;
	}
	return 0;
}

int eliminarIgualesMenosUltimaOcurrencia(struct pila **p, int x){
	int aux = 0;
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		aux = eliminarIgualesMenosUltimaOcurrencia(p,x);
		apilar(p, num);
		if(num == x && aux == 0){
			return aux + 1;
		}
		if(aux>=1&&num==x){
			desapilar(p);
		}
		return aux;
	}
}

void eliminarIgualesMenosPrimeraOcurrencia(struct pila **p, int x){
	if(!vacio(*p)){
		voltearLista(p);
		eliminarIgualesMenosUltimaOcurrencia(p,x);
		voltearLista(p);	
	}
}

int contarIgualesConAux(struct pila **p, struct pila **q, struct pila **r){
	int count = 0;
	if(!vacio(*r)){
		int num = tope(*r);
		desapilar(r);
		contarIgualesConAux(p,q,r);
		apilar(r, num);
		eliminarIgualesMenosPrimeraOcurrencia(r, num);
	}
}


int chequearCuantosElementosEnPilas(struct pila **p){
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		int elementos = chequearCuantosElementosEnPilas(p);
		apilar(p, num);
		return elementos + 1;
	}
	return 0;
}




int main() {
	
	int op = -1, x = 0,y=0;
	int cont = 0;
	pila *p = NULL; 
	pila *q = NULL;
	pila *r = NULL;
	while (op) {
		system("cls");
		printf("\t*************************\n");
		printf("\t|    * TDA: Pilas *     | \n");
		printf("\t*************************\n");
		printf("\n\t 1.-Insertar Pila A \n");
		printf("\n\t 2.-Insertar Pila B \n");
		printf("\n\t 3.-Mostrar Pila\n");
		
		scanf("%i", &op);
		
		switch (op) {
			
		case 1:{
			printf("\n\tNuevo elemento de la Pila A: ");
			scanf("%i", &x);
			system("cls");
			apilar(&p,x);
		break;
		}
		case 2:{
			printf("\n\tNuevo elemento de la Pila B: ");
			scanf("%i", &x);
			system("cls");
			apilar(&q,x);
		break;
		}
		case 3: mostrar(&p, 'A');
			mostrar(&q, 'B');
			system("pause");
		break;
		case 4: y = contarIgualesEnAmbasPilas(&p,&q);
			printf("Resultado: %i", y);
			system("pause");
		break;
		case 5:insertarIgualesEnPilaAux(&p,&q,&r);
			contarIgualesConAux(&p,&q,&r);
			y = chequearCuantosElementosEnPilas(&r);
			printf("Existen %i, elementos comunes", y);
			system("pause");
		break;
	}
}
return 0;
}
