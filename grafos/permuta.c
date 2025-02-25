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
            if(v1 == -1 || v2 == -1)
            
            
        }
    }
}




void main(){
    int n = 4;
    //scanf("%d",&n);
    //bool **vetor = instanciamatriz(n);
    //printmatriz(vetor,n);
    char input[] = "1 pl";
    int v1, v2;
    reconhece2num(&v1, &v2,input);
    printf("%d, %d\n",v1,v2);
    
    
}




