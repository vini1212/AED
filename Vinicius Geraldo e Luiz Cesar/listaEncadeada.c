#include "listaEncadeada.h"

Lista* cria_lista(){
	Lista *L;
	//faz um malloc para criar a lista encadeada a partir de um teste
	if((L = malloc(sizeof(Lista))) == NULL){
			return NULL;
		}
	
	L->qtd = 0;
	L->first = NULL; //primeiro elemento (cabeça aponta para nulo)
	
	return L;
}


int lista_cheia(Lista *L){
 //verifica o tamanho da lista se é maior que o MAX
 if(L->qtd >= MAX){
	return 1;
	}
 //verfica se o ponteiro L aponta para NULL
 if(L == NULL){
	return -1;
	}
 
 else{
	 return 0;
	}
	
}

int lista_vazia(Lista *L){
	//verifica se a lista está vazia a partir da quantidade = 0
	if(L->qtd == 0){
		return 1;
	}
	//verifica se o ponteiro L aponta para NULL
	if(L == NULL){
		return 0;
	}
	
	else {
		return 0;
	}
}

void imprimeLista(Lista *L){
	
	Nodo *p;
	
	//percorre toda a lista desde o primeiro elemento até o último que aponta para NULL
	for (p = L->first; p != NULL; p = p->prox) {
		
		printf("%d ", p->val); //printa todos os valores que estão nas listas
	}
}

int insere(Lista *L, int pos, int valor){
	
	int i = 0;
	Nodo *novo, *p, *aux;		
		
	if ((pos > MAX) || (L->qtd == MAX)){ //retorna 0 se a posição for maior que o MAX ou se a posição for igual ao MAX
		return 0;
		
	}

	novo = malloc(sizeof(Nodo));
	novo->val = valor;
	L->qtd++;

	if (L->first == NULL){
		
		L->first = novo;
		novo->prox = NULL;
		
		return 1;
	}

	p = L->first;
	
	//insere na primeira posição da lista
	if (pos == 0) {
		
		L->first = novo;
		novo->prox = p;

		return 1;
	}

	//insere na última posição da lista
	if ((pos+1) == L->qtd) {

		while (p->prox != NULL) {
		
			p = p->prox;	
		}

		p->prox = novo;
		novo->prox = NULL;
	
		return 1;
	}
	
	//insere em alguma posição no meio da lista
	while (p->prox != NULL) {
		
		if (i == pos) {
			
			aux->prox = novo;
			novo->prox = p;			

			return 1;
		}
		i++;
		aux = p;		
		p = p->prox;
	}
	
	return 0;
}

int deleta(Lista *L, int pos){
	
	Nodo *p, *aux;
	int i = 0;

	p = L->first;
	
	if (L->qtd > 0) {
			
		//remove o primeiro elemento
		if (pos == 0) {
			
			L->first = p->prox;
			p->prox = NULL;
			free(p);
			L->qtd--;
			return 1;
		}
		
		//remove o último elemento da lista
		if ((pos+1) == L->qtd) {	
			while (p->prox != NULL) {
			
				aux = p;		
				p = p->prox;
			}
			
			aux->prox = p->prox;		
			p->prox = NULL;
			free(p);
			L->qtd--;
			return 1;
			
		}

		//remove um elemento no meio da lista
		while (p->prox != NULL) {
		
			if (i == pos) {
				
				aux->prox = p->prox;		
				
				p->prox = NULL;
				free(p);
				L->qtd--;
				return 1;
			}
			i++;
			aux = p;		
			p = p->prox;
		}			
		
	} 
		
		return 0;		
}

void destroi_Lista(Lista *L){
	
	int i = 0;
	//libera memoria de cada elemento da lista
	for (i = 0; i < MAX; i++) {
		
		deleta(L, 0);
	}

	L->first = NULL;
	free(L);
}


int get(Lista *L, int pos){
	
	Nodo *p;
	int i = 0;
	
	p = L->first; //p recebe a primeira posição da lista

	if (pos > MAX)	
		return 0;

	while (p->prox != NULL) { //percorre a lista até NULL
		
		if (i == pos) {
			
			return p->val; //retorna o valor caso encontre na lista 
		}
		i++;		
		p = p->prox; //aponta para o proximo
	}
	
	return 0;
}


int set(Lista *L, int pos, int valor){
	
	Nodo *p;
	int i = 0;

    	p = L->first;//p recebe a primeira posição da lista

    	while(p != NULL){

        	if(i == pos){ //se a posição for igual a que foi inserida
			
			p->val = valor; //procura a posição que deseja trocar pelo novo valor 
            		return 1;
        	}
		i++;
		p = p->prox;

    	}

    	return 0;

}

int locate(Lista *L, int numero){
	
	Nodo *p;
	int pos = 0;

    	p = L->first;//p recebe a primeira posição da lista

    	while(p != NULL){
			
        	if(p->val == numero){
            		return pos; //retornar a posição do numero procurado
        	}
		pos++;
		p = p->prox;

    	}

    	return -1; //caso nao encontre retorna -1
}


int length(Lista *L){
	//retornar a quantidade da lista
   return L->qtd;

}
