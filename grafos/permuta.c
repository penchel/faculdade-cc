#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void main(){
    int n = 0;
    scanf("%d",&n);
    bool **vetor = (bool**) malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++)
    {
        vetor[i] =  (bool*) malloc(n * sizeof(bool));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vetor[i][j] = false;
        }
        
    }

    //vetor[1][1] = false;
    //vetor[0][3] = false;
    
    char input[100];
    while (1)
    {
        printf("Digite as arestas (0 para sair):")
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",vetor[i][j]);
        }
        printf("\n");
        
    }
    
    
}