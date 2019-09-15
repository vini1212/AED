#include "listaSequencial.h"

Lista* cria_lista(){
	Lista *L;
	
	//cria a lista a partir de um malloc
	if((L = malloc(sizeof(Lista))) == NULL){
		return NULL;
	}
	
	L->qtd = 0;
	
	return L;
	

}

int lista_cheia(Lista *L){
	//verifica se a lista está cheia
	if (L->qtd >= MAX){
		return 1;
	}
	
	//verifica se o ponteiro da lista está apontando para NULO
	else if(L == NULL){
		return -1;
		
	}
	
	else {
		return 0;
	}
}

int lista_vazia(Lista *L){
	//verifica se a lista está vazia
	if(L->qtd == 0){
		return 1;
	}
	
	//verifica se o ponteiro da lista está apontando para NULO
	else if(L == NULL){
		return -1;
		
	}
	
	else {
		return 0;
	}
	

}

void destroi_Lista(Lista *L){
		//libera memória da lista
		free(L);
}

int insere(Lista *L, int pos, int valor){
	int i;
	
	//insere posições novas na lista de dados aumentando quantidade 
	if ((pos < L->qtd) || (pos == L->qtd)){
		
		for (i = L->qtd - 1; i >= pos; i--){
			L->dados[i+1] = L->dados[i];
		}
		
		//faz a troca do valor na posição desejada
		L->dados[pos] = valor;
		L->qtd = L->qtd + 1 ;
		
		return 1;
	}
	
	else{
		return 0;
	}
		
}

int deleta(Lista *L, int pos){
	int i;
	
	//deleta a posição que está presente na lista diminuindo a quantidade de posiçoes
	if((pos < L->qtd) && (pos >= 0) && (L->qtd > 0)){
		
		for (i = pos; i < L->qtd; i++){
			L->dados[i] = L->dados[i+1];
		}
		
		L->qtd = L->qtd - 1;
		return 1;
		
	}
	
	else {
		return 0;
	}

}

int get(Lista *L, int pos){
	//retorna o valor do elemento na posição desejada
	if ((pos < L->qtd) && (pos >= 0) && (L->qtd > 0)){
		return L->dados[pos];
	}
	
	else {
		return 0;
	}
}

int set(Lista *L, int pos, int valor){
	//muda o valor do elemento na posição inserida
	if ((pos < L->qtd) && (pos >= 0) && (L->qtd > 0)){
		L->dados[pos] = valor;
		
		return 1;
		
	}
	
	else {
		return 0;
	}
}

int locate(Lista *L, int numero){
	int i;
	
	//buscar o numero desejado na lista 
	for(i = 0; i < L->qtd; i++){
		
		if(L->dados[i] == numero){
			return i;
		
		}
	}
	
	return -1;
	
}


int length(Lista *L){
	//retorna a quantidade da lista
	return L->qtd;
	
}
