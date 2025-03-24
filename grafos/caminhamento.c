#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX_TAM 100

int adiciona(int **vizinhos, int tam, int num, int pos){
    int *temp = (int*) realloc(*vizinhos, (tam+1) * sizeof(int));
    if (temp == NULL) {
        // se realloc falhar, vizinhos ainda é válido e não deve ser perdido
        free(vizinhos);
        perror("realloc falhou");
        return 1;
    } 
    *vizinhos = temp;
    for (int i = tam; i > pos; i--)
    {
       (*vizinhos)[i] = (*vizinhos)[i-1];
    }
    
    (*vizinhos)[pos] = num;
    tam = tam +1;
    return tam;

}

void main(){
    int n = 3;
    int *ponteiros = (int*) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        ponteiros[i] = -1;
    }
    int *vizinhos = (int*) malloc(sizeof(int));
    int tam_viz = 0;

    ponteiros[0] = tam_viz;
    tam_viz = adiciona(&vizinhos,tam_viz,1,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,3,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,4,tam_viz);
    ponteiros[1] = tam_viz;
    for (int i = 0; i < n; i++)
    {
        printf("%d ",ponteiros[i]);
    }
    printf("\n");
    for (int i = 0; i < tam_viz; i++)
    {
        printf("%d ", vizinhos[i]);
    }
    printf("\n");


    
    
    
}
