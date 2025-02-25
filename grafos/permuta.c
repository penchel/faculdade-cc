#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool** instanciamatriz(int n){
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
    return vetor;
}

void printmatriz(bool** vetor,int n){
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",vetor[i][j]);
        }
        printf("\n");
        
    }

}

bool edigit(char c){
    if(c >= '0' && c <= '9') return true;
    else return false;
}

void reconhece2num(int* v1, int* v2, char* str){
    *v1 = -1;
    *v2 = -1;
    int aux;
    for (int i = 0; i < strlen(str); i++)
    {
        
        if(edigit(str[i])){
            *v1 = 0;
            aux = 0;
            do
            {
                *v1 = *v1 *pow(10,aux) +( (int) str[i] - '0' );
                aux++;
                i++;
            } while (edigit(str[i]));
            aux = i + 1;
            break;
        }
        
    }

    for (int i = aux; i < strlen(str); i++)
    {
        if(edigit(str[i])){
            *v2 = 0;
            aux = 0;
            do
            {
                *v2 = *v2 *pow(10,aux) +( (int) str[i] - '0' );
                aux++;
                i++;
            } while (edigit(str[i]));
    
            break;
        }
    }
    
    
}
void inserearesta(int a, int b, bool **vetor){
    vetor[a][b] = true;
    vetor[b][a] = true;

}
void incluiarestas(bool **vetor){
    char input[100];
    printf("Digite as arestas (0 para sair):\n");
    while (1)
    {
        fgets(input, sizeof(input),stdin);
        input[strcspn(input,"\n")] = '\0';
        if(strcmp(input,"0") == 0) break;
        else{
            int v1,v2;
            reconhece2num(&v1, &v2, input);
            if(v1 == -1 || v2 == -1){
                printf("FORMATO INCORRETO");
            }
            
            
        }
    }
}

void reconhececiclo(bool **vetor){
    
}


void main(){
    int n = 6;
    //scanf("%d",&n);
    bool **vetor = instanciamatriz(n);
    inserearesta(0,1,vetor);
    inserearesta(0,3,vetor);
    inserearesta(0,4,vetor);
    inserearesta(1,3,vetor);
    inserearesta(1,2,vetor);
    inserearesta(1,4,vetor);
    inserearesta(4,5,vetor);
    inserearesta(4,2,vetor);
    inserearesta(3,5,vetor);
    inserearesta(3,2,vetor);
    inserearesta(2,5,vetor);
    printmatriz(vetor,6);


    
    
    
}




