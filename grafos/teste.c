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

void inserearesta(int a, int b, bool **vetor){
    vetor[a][b] = true;
    vetor[b][a] = true;

}
// Estrutura do nó da lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da lista encadeada
typedef struct {
    Node* head;
    int size;
} LinkedList;

// Função para inicializar a lista
void initList(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um novo elemento no final da lista
void insert(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++; // Atualiza o tamanho da lista
}

// Função para buscar o índice de um valor na lista
int searchByValue(LinkedList* list, int value) {
    Node* temp = list->head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

// Função para buscar um valor pelo índice na lista
int searchByIndex(LinkedList* list, int index) {
    Node* temp = list->head;
    int count = 0;
    while (temp != NULL) {
        if (count == index) {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }
    return -1;
}

// Função para exibir a lista
void printList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void clearList(LinkedList* list) {
    Node* current = list->head;
    Node* next;

    while (current != NULL) {
        next = current->next; // Guarda o próximo nó
        free(current); // Libera o nó atual
        current = next; // Move para o próximo nó
    }

    // Reseta a lista
    list->head = NULL;
    list->size = 0;
}





int aux = 0;
int fatorial(int n) {
    return (n <= 1) ? 1 : n * fatorial(n - 1);
}
bool isin(int *array, int pos, int a){
    int tam = sizeof(array)/sizeof(int);
    for (int i = 0; i < pos; i++)
    {
        if(a == array[i]) return true;
    }
    
    return false;
    
}
void permuta(int** lista, int*array, int tam, int pos){

    
    for (int i = 0; i < tam; i++)
    {
        while (isin(array, pos, i))
        {
            i++;
        }
        
        if(!(i<tam)) break;
        array[pos] = i;
        if(pos == tam -1){
            //memcpy(lista[aux], array, tam * sizeof(int));
            for (int k = 0; k < tam; k++)
            {
                lista[aux][k] = array[k];
            }
            
            aux++;
        }else{
            permuta(lista, array, tam, pos+1);
        }
        
    }

    

    
}

int ** permutation(int *array, int tam, int linhas){
    int **lista = (int**) malloc(linhas*sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        lista[i] = (int*) malloc(tam * sizeof(int));  

        if (lista[i] == NULL) {
            printf("Erro ao alocar memória!\n");
        }
    }
    permuta(lista, array, tam, 0); 
    
    return lista;
}

void mostrar(int **permutacoes, int tam, int linhas){
    for(int i =0; i<linhas;i++){  
        for (int j = 0; j < tam; j++){
            printf("%d ",permutacoes[i][j]);
        }
        printf("\n");
    }
}



int** generateBinaryMatrix(int n) {
    int rows = (int)pow(2, n);
    
    // Aloca memória para a matriz
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Erro ao alocar memória para a linha %d.\n", i);
            return NULL;
        }

        // Preenche a matriz com os valores binários correspondentes
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (i >> (n - j - 1)) & 1;
        }
    }

    return matrix;
}
int *arraytransform(int np, int vertice){
    int *arrayex =(int*) malloc(np * sizeof(int));
    for (int i = 0; i < np; i++)
    {
     arrayex[i] = i+1;
    }
 
    for (int i = 0; i < vertice; i++)
    {
     arrayex[i] = i;
    }
    
    return arrayex;
   /* for (int i = 0; i < np; i++)
    {
     printf("%d ",arrayex[i]);
    }
    printf("\n");*/
 }
int main() {
    int n = 5; // Defina o valor de n
    bool **vetor = instanciamatriz(n+1);
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
    char letra[] = {'A','B','C','D','E','F'};
    

    LinkedList list;
    initList(&list);
    LinkedList filtro;
    initList(&filtro);
    for (int vertice = 0; vertice < 6; vertice++)
    {
        
        int *trans = arraytransform(n,vertice);
    
    
        for (int sub = 2; sub < 6; sub++)
        {
            
            
            
            int *array = (int*) malloc(sub * (sizeof(int)));
            int tam = sub;
            int linhas = fatorial(tam);
            int **permutacoes = permutation(array, tam, linhas);
            int **permutacoesreal = (int**) malloc(linhas*sizeof(int*));
            for (int i = 0; i < linhas; i++) {
                permutacoesreal[i] = (int*) malloc(tam * sizeof(int));  

                if (permutacoesreal[i] == NULL) {
                    printf("Erro ao alocar memória!\n");
                }
            }
            //int permutacoestrans[linhas][tam];
            int nsq = 0;
            //mostrar(permutacoes,tam, linhas);

            int *subconjunto = (int*) malloc(sub*sizeof(int));
            int rows = (int)pow(2, n);
            int** matrix = generateBinaryMatrix(n);
            for (int i = 0; i < rows; i++)
            {
                int soma = 0;
                for (int j = 0; j < n; j++)
                {
                    soma = soma + matrix[i][j];
                }
                if(soma == sub){
                    insert(&list,i);
                }
                
            }
            
            for (int i = 0; i < list.size; i++)
            {
                int auxiliar = 0;
                for (int j = 0; j < n; j++)
                {
                    //printf("%d ",matrix[searchByIndex(&list,i)][j]);
                    if(matrix[searchByIndex(&list,i)][j] == 1){
                        subconjunto[auxiliar] = j;
                        auxiliar++;
                    }
                    if (auxiliar == sub)break;  
                }
                /*for (int h = 0; h < sub; h++) {
                    printf("%d ",subconjunto[h]);
                }
                printf("\n");*/
                for (int h = 0; h < linhas; h++)
                {
                    for (int j = 0; j < tam; j++)
                    {
                        
                        
                        nsq = subconjunto[permutacoes[h][j]];
                        permutacoesreal[h][j] = nsq;
                        //printf("%d ",permutacoesreal[h][j]);
                    }
                    
                    
                }

                for (int h = 0; h < linhas; h++)
                {
                    for (int j = 0; j < tam; j++)
                    {
                        
                        insert(&filtro,trans[permutacoesreal[h][j]]);
                        
                    }
                    bool exis = true;
                    for (int index = 0; index < filtro.size -1; index++)
                    {
                        if(!vetor[searchByIndex(&filtro,index)][searchByIndex(&filtro, index + 1)]){
                            exis = false;
                        }
                    }
                    if(!vetor[searchByIndex(&filtro,0)][vertice]){
                        exis = false;
                    }
                    if(!vetor[searchByIndex(&filtro,filtro.size-1)][vertice]){
                        exis = false;
                    }

                    if (exis)
                    {
                        printf("%c ", letra[vertice]);
                        for (int j = 0; j < tam; j++)
                        {
                            
                            printf("%c ",letra[trans[permutacoesreal[h][j]]]);
                            
                        }
                        printf("%c ", letra[vertice]);
                        printf("\n");
                    }
                    clearList(&filtro);
                    
                }

                
                
            

                
            }
            clearList(&list);
            aux = 0;
        }

    }


    
    
    
    return 0;
}
