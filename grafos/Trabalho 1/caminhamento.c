#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_TAM 100

// --- VARIÁVEIS GLOBAIS ---
int n = 6;
char letra[] = {'A','B','C','D','E','F'};
int *ponteiros;
int *vizinhos;
int tam_viz = 0;

// --- FUNÇÃO PARA ADICIONAR VIZINHOS ---
int adiciona(int **vizinhos, int tam, int num, int pos){
    int *temp = (int*) realloc(*vizinhos, (tam+1) * sizeof(int));
    if (temp == NULL) {
        perror("realloc falhou");
        free(*vizinhos);
        exit(1);
    } 
    *vizinhos = temp;
    for (int i = tam; i > pos; i--) {
        (*vizinhos)[i] = (*vizinhos)[i-1];
    }
    (*vizinhos)[pos] = num;
    return tam + 1;
}

// --- FUNÇÃO PARA CRIAR O GRAFO ---
void criaGrafo() {
    ponteiros = (int*) malloc((n+1)*sizeof(int));
    for (int i = 0; i <= n; i++) {
        ponteiros[i] = -1;
    }

    vizinhos = (int*) malloc(sizeof(int)); // inicializa com espaço mínimo

    ponteiros[0] = tam_viz;
    tam_viz = adiciona(&vizinhos, tam_viz, 1, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 3, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 4, tam_viz);
    ponteiros[1] = tam_viz;
    tam_viz = adiciona(&vizinhos, tam_viz, 0, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 2, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 3, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 4, tam_viz);
    ponteiros[2] = tam_viz;
    tam_viz = adiciona(&vizinhos, tam_viz, 1, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 3, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 4, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 5, tam_viz);
    ponteiros[3] = tam_viz;
    tam_viz = adiciona(&vizinhos, tam_viz, 0, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 1, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 2, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 5, tam_viz);
    ponteiros[4] = tam_viz;
    tam_viz = adiciona(&vizinhos, tam_viz, 0, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 1, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 2, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 5, tam_viz);
    ponteiros[5] = tam_viz;
    tam_viz = adiciona(&vizinhos, tam_viz, 2, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 3, tam_viz);
    tam_viz = adiciona(&vizinhos, tam_viz, 4, tam_viz);
    ponteiros[6] = tam_viz;
}

// --- FUNÇÃO PARA IMPRIMIR O GRAFO ---
void imprimeGrafo() {
    for (int i = 0; i <= n; i++) {
        printf("%d ", ponteiros[i]);
    }
    printf("\n");

    for (int i = 0; i < tam_viz; i++) {
        printf("%d ", vizinhos[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%c --> ", letra[i]);
        for (int j = ponteiros[i]; j < ponteiros[i+1]; j++) {
            printf("%c ", letra[vizinhos[j]]);
        }
        printf("\n");
    }
}

// --- MAIN ---



// Insere um valor no fim da lista
bool inserirFim(int valor, int* lista, int tamanho) {
 
    if (tamanho >= MAX_TAM) {
        return false; // lista cheia
    }
    lista[tamanho] = valor;
    tamanho++;
    return true;
}

// Insere um valor no início da lista
bool inserirInicio(int valor, int* lista, int tamanho) {
    if (tamanho >= MAX_TAM) {
        return false; // lista cheia
    }
    for (int i = tamanho; i > 0; i--) {
        lista[i] = lista[i - 1]; // desloca para a direita
    }
    lista[0] = valor;
    tamanho++;
    return true;
}

// Imprime a lista
void imprimirLista(int* lista, int tamanho) {
    //printf("Lista: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%c ", letra[lista[i]]);
    }
    printf("%c ",letra[lista[0]]);
    printf("\n");
}

bool vertice_repetido(int vert, int *list, int tamanho){
    for (int i = 1; i < tamanho; i++)
    {
        if(list[i] == vert) return true;
    }
    return false;
}

void buscar(int vertice, int *list, int tamanho,int alvo){
    if(vertice == alvo){
        imprimirLista(list,tamanho);
    }else{
        int lista[MAX_TAM];
        for (int i = 0; i < tamanho; i++) {
            lista[i] = list[i];
        }    
        inserirFim(vertice,lista,tamanho);
        tamanho++;
        for (int i = ponteiros[vertice]; i < ponteiros[vertice+1]; i++)
        {
            if(!vertice_repetido(vizinhos[i],lista, tamanho)){
                if(lista[tamanho-2]!=vizinhos[i]){
                    buscar(vizinhos[i],lista,tamanho, alvo);
                }
            }
            
        }
    }
    
}
int main() {
    criaGrafo();
    imprimeGrafo();
    int list[MAX_TAM];
    

    for(int vertice = 0; vertice < 6; vertice++){
        int alvo = vertice;
        int lista[MAX_TAM];
        int tamanho = 0;
        for (int i = 0; i < tamanho; i++) {
            lista[i] = list[i];
        }    
        inserirFim(vertice,lista,tamanho);
        tamanho++;
        for (int i = ponteiros[vertice]; i < ponteiros[vertice+1]; i++)
        {
            buscar(vizinhos[i],lista,tamanho, alvo);
        }
        //printf("%d\n",vertice);
    }
    return 0;
}
