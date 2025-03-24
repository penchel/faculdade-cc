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
    int n = 6;
    char letra[] = {'A','B','C','D','E','F'};
    int *ponteiros = (int*) malloc((n+1)*sizeof(int));
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
    tam_viz = adiciona(&vizinhos,tam_viz,0,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,2,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,3,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,4,tam_viz);
    ponteiros[2] = tam_viz;
    tam_viz = adiciona(&vizinhos,tam_viz,1,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,3,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,4,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,5,tam_viz);
    ponteiros[3] = tam_viz;
    tam_viz = adiciona(&vizinhos,tam_viz,0,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,1,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,2,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,5,tam_viz);
    ponteiros[4] = tam_viz;
    tam_viz = adiciona(&vizinhos,tam_viz,0,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,1,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,2,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,5,tam_viz);
    ponteiros[5] = tam_viz;
    tam_viz = adiciona(&vizinhos,tam_viz,3,tam_viz);
    tam_viz = adiciona(&vizinhos,tam_viz,4,tam_viz);
    ponteiros[6] = tam_viz;
    for (int i = 0; i < n+1; i++)
    {
        printf("%d ",ponteiros[i]);
    }
    printf("\n");
    for (int i = 0; i < tam_viz; i++)
    {
        printf("%d ", vizinhos[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%c --> ",letra[i]);
        for (int j = ponteiros[i]; j < ponteiros[i+1]; j++)
        {
            printf("%c ",letra[vizinhos[j]]);
        }
        printf("\n");
    }
    


    
    
    
}
