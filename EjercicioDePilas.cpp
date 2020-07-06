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

void mostrar(struct pila **p){
	struct pila *t = NULL;
	printf("\n\n\t 2. Mostrar Pila \n\n\t(tope)");
	imprime(p);
	printf("| (fondo)\n\n");
}

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

void insertarOrdenadamente(struct pila **p, int x){
	if(!vacio(*p)){
		int num = tope(*p);
		if(x<=num){
			apilar(p,x);
		}else{
			desapilar(p);
			insertarOrdenadamente(p,x);
			apilar(p, num);
		}
	}else{
		apilar(&(*p), x);
	}
}

void insertarValorLuegoDeUnoDado(struct pila **p, int x, int y){
	if(!vacio(*p)){
		int num = tope(*p);
		if(y == num){
			desapilar(p);
			apilar(p, x);
			apilar(p,num);
		}else{
			desapilar(p);
			insertarValorLuegoDeUnoDado(p, x, y);
			apilar(p, num);
		}
	}
}

void eliminarValorPrimeraVezEncontrado(struct pila **p, int x){
	if(!vacio(*p)){
		int num = tope(*p);
		if(num == x){
			desapilar(p);
		}else{
			desapilar(p);
			eliminarValorPrimeraVezEncontrado(p, x);
			apilar(p, num);
		}
	}
}

void eliminarValorUltimaVezEncontrado(struct pila **p, int x, int el){
	voltearLista(p);
	eliminarValorPrimeraVezEncontrado(p,x);
	voltearLista(p);
}

int devolverChequeo(int a){
	if(a){
		return 1;
	}else{
		return 0;
	}
}

int buscarNroEnPila(struct pila **p, int x){
	int a = 0;
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		buscarNroEnPila(&(*p), x);	
		apilar(p, num);
		if(num == x){
			a++;
		}
	}
	printf("%i",a);
}
int nprime(int x){
	int n = x, i, prime = 1;
	if(x == 1)return 0;
	for(i = 2; i < n && prime==1; i++){
		if(n % i == 0){prime = 0;}
	}
	return prime;
}

void eliminarPrimosEnPilas(struct pila **p){
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		eliminarPrimosEnPilas(p);
		if(!nprime(num)){
			apilar(p, num);
		}
	}
}

int esImpar(int x){
	if(x%2 == 0){
		return 0;
	}else{
		return 1;
	}
}

void eliminarImparesEnPilas(struct pila **p){
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		eliminarImparesEnPilas(p);
		if(!esImpar(num)){
			apilar(p,num);
		}
	}
}

void eliminarValorTodasLasVecesEncontradas(struct pila **p, int x){
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);;
		eliminarValorTodasLasVecesEncontradas(p, x);
		if(num == x){
			return;
		}else{
			apilar(p, num);	
		}
	}
}

int voltearNroRecursivo(int x, int z){
	int y = x%10;
	z = (z*10)+y;
	if(x>10){
		voltearNroRecursivo(x/10,z);		
	}
}

int factorial(int x){
	if(x!=1) return x*factorial(x-1);
}

int voltearNro(int x){
	int invertido = 0;
	while(x>0){
		invertido = invertido * 10 + (x%10);
		x = x/10;
	}
	return invertido;
}

int nrosEnSecuenciaCreciente(int x){
	int nro = voltearNro(x);
	int sig = 0;
	int mayor = 1;
	int actual = 0;
	while(nro>0){
		actual = sig;
		sig = nro%10;
		if(!(sig>=actual)){
			mayor = 0;
			break;
		}
		nro = nro/10;
	}
	return mayor;
}

void eliminarNrosConSecuenciaCreciente(struct pila **p){
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		eliminarNrosConSecuenciaCreciente(p);
		if(!nrosEnSecuenciaCreciente(num)){
			apilar(p,num);
		}
	}
}

int checkDigPar(int x){
	int count = 0;
	while(x>0){
		if(x%2 == 0){
			count++;
		}
		x = x/10;
	}
	if(count>=2){
		return 1;
	}else{
		return 0;
	}
}

void eliminarNrosQueTienenAlMenos2par(struct pila **p){
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		eliminarNrosQueTienenAlMenos2par(p);
		if(!checkDigPar(num)){
			apilar(p,num);
		}
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

int nroConMenosDigitos(int x, int y){
	int a = 0; int b = 0; int mayor = 0;
	int auxA = x; int auxB = y;
	while(auxA>0){
		a++;
		auxA = auxA/10;
	}
	while(auxB>0){
		b++;
		auxB = auxB/10;
	}
	if(a>=b){
		return b;
	}else{
		return a;
	}
}

int checkDigitosInternosIguales(int x, int y){
	int count = 0; int nroMenosDigitos = nroConMenosDigitos(x,y);
	int aux = 0; int aux2 = 0; int auxX = x; int auxY = y;
	while(x>0){
		aux = x%10;
		y = auxY;
		while(y>0){
			aux2 = y%10;
			if(aux == aux2){
				count++;
				printf("count: %i", count);
				system("pause");
				break;
			}
			y = y/10;
		}
		x = x/10;
	}
	if(count == nroMenosDigitos){
		return 1;
	}else{
		return 0;
	}
}

int digitos_iguales(struct pila **p, int x){
    int n, aux=0, total = 0;
    if(!(vacio(*p))){
        n = tope(*p);
        desapilar(p);
        total = digitos_iguales(p,x);
        apilar(p,n);
        if(checkDigitosInternosIguales(x,n)==1){
            desapilar(p);
            return total + 1;
        }
        return total;
    }
    return total;
}

void eliminar_iguales(struct pila **p){
    int x, aux;
    if(!(vacio(*p))){
        x = tope(*p);
        desapilar(p);
        aux = digitos_iguales(p,x);
        printf("%i", aux);
        system("pause");
        eliminar_iguales(p);
        apilar(p,x);
        if(aux!=0){
            desapilar(p);
        }
    }
}


int eliminarIgualesMenosUltimaOcurrencia(struct pila **p, int x){
	int aux = 0;
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		aux = eliminarIgualesMenosUltimaOcurrencia(p,num);
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
		int num = tope(*p);
		voltearLista(p);
		eliminarIgualesMenosUltimaOcurrencia(p,num);
		voltearLista(p);	
	}
}

int devolverSiSonIguales(struct pila **p, int x){
	int aux = 0;
	if(!vacio(*p)){
		int num = tope(*p);
		desapilar(p);
		aux = devolverSiSonIguales(p,x);
		if(x == num){
			return aux + 1;
		}
		apilar(p, num);
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

void eliminarO(pila** ppPila, int t) {
    if (!vacio(*ppPila)) {
        int k = tope(*ppPila);
        desapilar(ppPila);
        eliminarO(ppPila, t);
        //printf(" t=%i k=%i   retorna=%i    ",t,k, ev_dig(t, k)); system("pause");
         if(t != k)
            apilar(ppPila, k);
    }
}

void repetidosP(pila** ppPila) {
    int cont = 0;
    if (!vacio(*ppPila)) {
        int t = tope(*ppPila);
        desapilar(ppPila);
        repetidosP(ppPila);
        eliminarO(ppPila, t);
        apilar(ppPila, t);
    }
}

int main(){
	int x = 0;
	int y = 0;
	int a = 0;
	int b = 10;
	pila *p = NULL; 
	pila *q = NULL;
	int op = -1;
	while(op!=0){
		system("cls");
		printf("Menu Lista\n");
		printf("1.-Insertar un valor A\n");
		printf("2.-mostrar\n");
		printf("3.-Insertar por cola\n");
		printf("4.-Insertar De manera Ordenada\n");
		printf("5.-Insertar Valor luego de uno Dado\n");
		printf("6.-Eliminar Primero de los elementos repetidos de la pila\n");
		printf("7.-Eliminar el ultimo elemento repetido de la lista\n");
		printf("8.-Eliminar tpdps los elementos repetidos de la lista\n");
		scanf("%i", &op);
		switch(op){
			case 1:
				printf("\nEscriba el numero que desee Insertar en la lista 1\n");
				scanf("%i",&x);
				apilar(&p, x);
			break;
			case 2: mostrar(&p);
				system("pause");
			break;
			case 3:
				printf("\nEscriba el numero que desee Insertar en la lista 1\n");
				scanf("%i",&x);
				insertarCola(&p, x);
			break;
			case 4:
				printf("\nEscriba el numero que desee Insertar en la lista 1\n");
				scanf("%i",&x);
				insertarOrdenadamente(&p, x);
			break;
			case 5:
				printf("\nEscriba el numero que desee Insertar en la lista 1\n");
				scanf("%i",&x);
				printf("\nEscriba el numero guia del elemento al insertar\n");
				scanf("%i", &y);
				insertarValorLuegoDeUnoDado(&p, x, y);
			break;
			case 6:
				printf("\nEscriba el numero que desee Eliminar en la pila 1\n");
				scanf("%i",&x);
				eliminarValorPrimeraVezEncontrado(&p, x);
			break;
			case 7:
				printf("\nEscriba el numero que desee Eliminar en la pila 1\n");
				scanf("%i",&x);
				eliminarValorUltimaVezEncontrado(&p, x, 0);
			break;
			case 8: voltearLista(&p);
			break;
			case 9:
				printf("Que nro quieres chequear?\n");
				scanf("%i", &x); 
				y = buscarNroEnPila(&p,x);
				printf("resultado: %i\n", y);
				system("pause");
			case 10:eliminarPrimosEnPilas(&p);
			break;
			case 11:eliminarImparesEnPilas(&p);
			break;
			case 12:eliminarNrosConSecuenciaCreciente(&p);
			break;
			case 13:eliminarNrosQueTienenAlMenos2par(&p);
			break;
			case 14:eliminar_iguales(&p);
			break;
			case 15:repetidosP(&p);
			break;
			case 16:eliminarIgualesMenosUltimaOcurrencia(&p, 0);
			break;
			case 17: y = devolverSiSonIguales(&p, 5);
				printf("resultado: %i\n", y);
				system("pause");
			break;
		}
	}
}
