// Origem da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1110

// Autor: Paulo Henrique Diniz de Lima Alencar
// Disciplina: Estrutura de dados
// Assuntos utilizados: ponteiros, conceito de No, Lista Encadeada.

#include <stdio.h>
#include <stdlib.h>

// Estrutura do tipo: No, com valor: número e prox como mecanismo para unir os Nos / cartas. 
typedef struct no{
    int numero;  
    struct no *prox;
} No; 
// Obs: cada Nó em minha lista, representa de forma abstrata uma carta.

No* inicio = NULL;
No* fim    = NULL;
int tamanho = 0;
    
// Procedimento: responsável por criar uma lista com 'n' cartas, [1 - n] cartas no total 
// Ex1. se n = 7, teremos 1, 2, 3, 4, 5, 6, 7
// Ex2. se n = 5, teremos 1, 2, 3, 4, 5
void criando_lista (int n)
{  
	int i;
   	for (i = 1; i <= n; i++) {
		No* cartao = (No *) malloc (sizeof(No));
		cartao -> numero = i;
		cartao -> prox   = NULL;

		if (inicio == NULL) {
		    inicio = cartao;
		    fim    = cartao;
		}
		else {
		    fim -> prox = cartao;
		    fim = fim -> prox;
		}
    tamanho += 1;
    }
}

// Procedimento: Responsável por fazer a seguinte parte da questão: "Jogue fora a carta do topo e mova a próxima carta (a carta que 
// ficou no topo) para a base", encontrando a sequência de cartas descartadas e a última carta remanescente.
void operacao ()
{ 
    No* aux = inicio;
    No* lixo;
    int i = 0;
    
    printf("Discarded cards: ");
    
    while (tamanho > 1) {
        if (i % 2 == 0) { // i é par
            printf("%d", aux -> numero);
            if (tamanho > 2) printf(", "); // somente para imprimir a vírgula da forma correta
        }
        else {            // i é impar
            lixo = aux;
            aux = aux -> prox;
            inicio = aux -> prox;
            free(lixo);
            fim -> prox = aux;
            aux -> prox = NULL;
            fim = aux;
        tamanho--;
        }        
        aux = inicio;
        i++;
    }
    
    printf("\nRemaining card: %d\n", fim -> numero);
    
    tamanho = 0;
    free(fim);
}

// Função principal
int main (void) {
    // Dicionário de dados:
    int n; 

    while (1) {
        
        scanf("%d",&n);     // Entrada de dados:
        
        if (n == 0) break;
        
        criando_lista (n);  // Criando lista com números/cartas [1 - n]
        operacao();         // Responsável por encontrar a sequência de cartas descartadas e a última carta remanescente.
    }     
    
    return 0;
}
