def selection_Sort(vetor):
        i = 0

        while i < len(vetor) - 1:  #percorre o vetor
            menor = i
            j = i + 1

            # em busca do menor elemento

            while j < len(vetor):
                if vetor[j] < vetor[menor]:
                    menor = j #procura o menor elemento e troca para a posição certa

                j += 1

            if menor != i:  #se a posição for diferente do que ela está inicialmente onde deveria
                temp = vetor[i]
                vetor[i] = vetor[menor] #faz toda ordenação nesses passos
                vetor[menor] = temp

            i += 1 #passa para o proximo elemento de teste

def main():
    import random
    import time
    n = 1000
    vetor = []
    soma = 0


    while n <= 50000: #condição para fazer os 50000 casos de testes de elementos
        print(n)

        for k in range (10):
            for i in range (0, n - 1):
                vetor = list(range(0, n)) #gera o vetor com valores random
                random.shuffle(vetor)

            inicio = time.process_time() #descrição da realização dos tempos antes da função
            selection_Sort(vetor) #ordenação
            fim = time.process_time() #descrição da realização dos tempos depois da função
            duracao = (fim - inicio) #variação

            soma = duracao + soma

            print(duracao)

        soma = soma / 10
        print('\n')

        print('Media: {}'.format(soma))
        print('\n')

        if n == 1000:
            n = n + 4000

        else:
            n = n + 5000

main()

