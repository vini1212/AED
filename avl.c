//VINÍCIUS RENATO ROCHA GERALDO e LUIZ CESAR MOREIRA DE CAMPOS NETO

#include "avl.h"

void print_tab(int level){
  int i;
  for (i = 0; i < level; i++ )
    printf("\t");
}

void print_tree( Nodo_AVL *current, int level ){
  if ( current == NULL ) {
    print_tab(level );
    printf("~\n");
  } else {
    print_tree( current->right, level + 1 );
    print_tab(level);
    printf ("%d\n", current->key );
    print_tree( current->left, level + 1 );
  }
}

int maior(int A, int B){ // retorna o maior dos inteiros
    if (A >= B){
    	return A;
    }

    else {
    	return B;
    }
}

int fatorbalan(Nodo_AVL *current){ // calcula o fator de balanciamento
    int left,right ;
    if(current == NULL)
        return(0);
    if(current->left == NULL)
        left = 0;
    else
        left = current->left->height + 1;
    if(current->right == NULL)
        right = 0;
    else
        right = current->right->height + 1;
    return(left - right);
}

Nodo_AVL *rotation_LL(Nodo_AVL *current){ // ROTAÇÃO A DIREITA
    Nodo_AVL *aux;
    aux = current->left; //faz uma raiz nova apontar para o filho da esquerda para fazer a rotação onde se torna raiz
    current->left = aux->right; 
    aux->right = current; //faz a raiz descer para direita da raiz aux nisso arrumando o balanceamento 
    current->height = avl_height(current); //retorna o tamanho da current atualizada
    aux->height = avl_height(aux); //retorna o tamanho da aux passando como parametro
    return aux;
}

Nodo_AVL *rotation_RR(Nodo_AVL *current){ // ROTAÇÃO A ESQUERDA
    Nodo_AVL *aux;
    aux = current->right;//faz uma raiz nova (aux) apontar para o filho da direita para ser a nova raiz e fazer a rotação
    current->right = aux->left;
    aux->left = current; //faz a raiz descer para esquerda da raiz aux nisso arrumando o balanceamento
    current->height = avl_height(current);//retorna o tamanho da current atualizada
    aux->height = avl_height(aux); //retorna o tamanho da aux passando como parametro
    return aux;
}

Nodo_AVL *rotation_LR(Nodo_AVL *current){ // ROTAÇÃO DUPLA A DIREITA
    current->left = rotation_RR(current->left); //faz primeiro uma rotação a esquerda
    return rotation_LL(current); //depois retorna uma rotação a direita com o balanceamento final
}

Nodo_AVL *rotation_RL(Nodo_AVL *current){ // ROTAÇÃO DUPLA A ESQUERDA
    current->right = rotation_LL(current->right); //faz primeiro uma rotação a direita  
    return rotation_RR(current); //depois retorna uma rotação a esquerda com o balanceamento arrumado
}

Nodo_AVL *avl_insert(Nodo_AVL *current, int key){
    if(current == NULL){ //se não existir uma raiz ele cria na função de alocar uma memoria 
        current = (Nodo_AVL *) malloc(sizeof(Nodo_AVL));
        current->key = key; //se não houver filhos a esquerda e a direita
        current->left = NULL;
        current->right = NULL;
    }
    //cada inserçao realiza o teste de balanceamento para saber se precisa ser feito simples ou dupla a rotação
    else if(key > current->key){ // se key maior que atual vai para direita
        current->right = avl_insert(current->right, key);
        if(fatorbalan(current) < -1){ // verifica o lado que está desbalanciado e qual rotação irá fazer
            if(key > current->right->key)
                current = rotation_RR(current);
            else
                current = rotation_RL(current);
        }
    }
    else if(key < current->key){ // se key for menor que a atual então desloca para esquerda da raiz
        current->left = avl_insert(current->left, key);
        if(fatorbalan(current) > 1){ // verifica o lado que está desbalanciado e qual rotação irá fazer
            if(key < current->left->key)
                current = rotation_LL(current);
            else
                current = rotation_LR(current);
        }
    }
    current->height = avl_height(current); // atualiza a altura
    return(current);
}

Nodo_AVL *avl_search(Nodo_AVL *current, int key){
    if(current != NULL){
        if(current->key == key) // Encontra o elemento desejado e retorna
            return current;
        else if(current->key < key){ // procura a direita
            current = avl_search(current->right, key);
            return current;
        }
        else{ // procura a esquerda
            current = avl_search(current->left, key);
            return current;
        }
    }
    else
        return 0;
}

Nodo_AVL *avl_delete(Nodo_AVL *current, int key){
    if(current == NULL){ // nodo null nao faz nada
        return NULL;
    }
    //No mesmo caso da inserção precisa verificar os casos se houve o desbalanceamento após a remoção do nodo desejado 
    else if(key < current->key){ // se key menor que atual
        current->left = avl_delete(current->left, key); // vai a esquerda do atual
        if(fatorbalan(current) < -1){ // verifica se precisa balanciar depois de realizada a remoção
            if(fatorbalan(current->right) <= 0)
                current = rotation_RR(current);
            else
                current = rotation_RL(current);
        }
    }
    else if(key > current->key){ // se key maior que atual
        current->right = avl_delete(current->right, key); // vai a direita do atual
        if(fatorbalan(current) > 1){ // verifica se precisa balanciar depois de realizada a remoção
            if(fatorbalan(current->left) >= 0)
                current = rotation_LL(current);
            else
                current = rotation_LR(current);
        }
    }
    else{ // caso para quando se remove a raiz
        Nodo_AVL *aux;
        if(current->right != NULL){ // verifica se ha elemento na direita
            aux = current->right;
            while(aux->left != NULL) // percorre a árvore pegando o mais a esquerda
                aux = aux->left;
            current->key = aux->key;
            current->right = avl_delete(current->right, aux->key); // verifica se possui elementos na direta
            if(fatorbalan(current) > 1){ // verifica se precisa balanciar apos a remocao
                if(fatorbalan(current->left) >= 0)
                    current = rotation_LL(current);
                else
                    current = rotation_LR(current);
            }
        }
        else // se não houver elemento a direta retorna a esquerda
            return(current->left);
    }
    current->height = avl_height(current); // atualiza a altura
    return(current);
}


void avl_destroy(Nodo_AVL *current){
	//destroi os nodos filhos para chegar até a raiz e concluir a destroy
    if(current != NULL ){
        avl_destroy(current->left);
        avl_destroy(current->right);
        free(current);
    }
}

int avl_height(Nodo_AVL *current) {
    if(current == NULL){
        return -1;
    }
    else{
        return maior(avl_height(current->left), avl_height(current->right)) + 1;
    }
}


void print_inOrder(Nodo_AVL *current){
    if(current != NULL){
        print_inOrder(current->left);
        printf("%d ", current->key);
        print_inOrder(current->right);
    }
}