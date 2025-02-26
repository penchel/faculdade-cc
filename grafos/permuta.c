#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} Lista;

// Função para criar uma lista automaticamente
Lista criarLista() {
    Lista lista;
    lista.capacidade = 5;
    lista.tamanho = 0;
    lista.dados = (int*) malloc(lista.capacidade * sizeof(int));

    if (lista.dados == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    return lista;
}

// Função para aumentar a capacidade automaticamente quando necessário
void aumentaCapacidade(Lista *lista) {
    lista->capacidade *= 2;
    lista->dados = (int*) realloc(lista->dados, lista->capacidade * sizeof(int));

    if (lista->dados == NULL) {
        printf("Erro ao realocar memória!\n");
        exit(1);
    }
}

// Função para inserir um elemento (crescendo automaticamente)
void inserir(Lista *lista, int valor) {
    if (lista->tamanho == lista->capacidade) {
        aumentaCapacidade(lista);
    }
    lista->dados[lista->tamanho] = valor;
    lista->tamanho++;
}

// Função para remover um elemento da lista
void remover(Lista *lista, int valor) {
    int i, encontrado = 0;

    for (i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == valor) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Valor %d não encontrado!\n", valor);
        return;
    }

    for (int j = i; j < lista->tamanho - 1; j++) {
        lista->dados[j] = lista->dados[j + 1];
    }

    lista->tamanho--;
}

void removerInicio(Lista *lista) {
    if (lista->tamanho == 0) {
        printf("Erro: A lista está vazia, não há elementos para remover!\n");
        return;
    }

    // Desloca todos os elementos para a esquerda
    for (int i = 0; i < lista->tamanho - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }

    lista->tamanho--; // Diminui o tamanho da lista
}

// Função para exibir a lista
void exibirLista(const Lista *lista) {
    printf("Lista (%d elementos): ", lista->tamanho);
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

// Função para liberar memória
void liberarLista(Lista *lista) {
    free(lista->dados);
    lista->dados = NULL;
    lista->tamanho = 0;
    lista->capacidade = 0;
}


int ** initmatrizpos(int n){
    int linhas = pow(2,n);
    int ** matriz = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int*) malloc(n * sizeof(int));
    }
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (i >> (n - j - 1)) & 1;  // Obtém o bit correspondente
        }
    }
    
    return matriz;
}

void imprimeMatriz(int **matriz, int n) {
    int linhas = pow(2, n);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}


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

bool soma3(int* linha, int colunas){
    int soma = 0;
    for (int i = 0; i < colunas; i++)
    {
        soma += linha[i];
    }
    if(soma >=3) return true;
    else return false;   
}

bool existeciclo(int *linha, bool **vetor, int n){
    Lista uns = criarLista();
    

    for (int i = 0; i < n; i++)
    {
        if(linha[i] == 1) inserir(&uns,i);
    }

    for (int i = 0; i < uns.tamanho-1; i++)
    {
        int a = uns.dados[i];
        int b = uns.dados[i+1];
        if(!vetor[a][b]) return false;
    }
    if(!vetor[0][uns.tamanho-1]) return false;
    return true;
    
}
int num;
    
int** reconhececiclo(bool **vetor, int n){
    
    int **matriz = initmatrizpos(n);
    int linhas = pow(2,n);
    Lista list = criarLista();
    for (int i = 0; i < linhas; i++)
    {
        if(soma3(matriz[i],n) && existeciclo(matriz[i],vetor,n)){
            inserir(&list,i);
        }
    }

    int **matrizretorno = (int**) malloc(list.tamanho * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        matrizretorno[i] = (int*) malloc(n * sizeof(int));
    }
    int aux = 0;
    num = list.tamanho;
    for (int i = 0; i < linhas; i++)
    {
        if(i == list.dados[0]){
            matrizretorno[aux] = matriz[i];
            removerInicio(&list);
            aux++;
        }   
    }
    
    
    return matrizretorno;

}

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

void addproib(int n, int*proib){
    int tam = sizeof(proib)/sizeof(int);
    int x = 0;
    for (int i = 0; i < tam; i++)
    {
        if(proib[i] == -1){
            x = i;
            break;
        }
    }
    
    proib[x] = n;
    
}
int aux = 0;
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

bool esta(int a,int *array, int tam){
    for (int i = 0; i < tam; i++)
    {
        if(a == array[i]){
            return true;
        }
    }
    return false;
}

void filtrar(int **permutacoes, int tam, int linhas, int *filtro){
    for(int i =0; i<linhas;i++){ 
        if(esta(i,filtro,linhas)){ 
            for (int j = 0; j < tam; j++){
                printf("%d ",permutacoes[i][j]);
            }
            printf("\n");
        }
    }
}

int *arraytransform(int n, int vertice){
    int np = n -1;
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
bool existelig(int* array){

}
void main(){
    
    
    int n = 6;
    num = 0;
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
    printmatriz(vetor,n);
    printf("\n//////////////\n");
    
   
   int vertice = 0;
    int np = n - 1;
   int* trans = arraytransform(n,vertice);
     
   


   int *array = (int*) malloc(np * (sizeof(int)));
   int tam = np;
   int linhas = fatorial(tam);
   int **permutacoes = permutation(array, tam, linhas);
   for (int i = 0; i < linhas; i++)
   {
    for (int j = 0; j < tam; j++)
    {
        permutacoes[i][j] = trans[permutacoes[i][j]];
    }
    
   }
   
   //mostrar(permutacoes, tam, linhas);

   int *filtro = (int*) malloc(linhas*sizeof(int));
   int aju = 0;
   bool exis = true;
   for (int i = 0; i < linhas; i++)
   {
        if(!(vetor[vertice][permutacoes[i][0]])){
            exis =false;
        }
        for (int j = 0; j < tam-1; j++)
        {
            if(!(vetor[permutacoes[i][j]][permutacoes[i][j+1]])){
                exis = false;
            }
        }
        if(!(vetor[permutacoes[i][tam-1]][vertice])){
            exis =false;
        }
        if(exis){
            filtro[aju] = i;
            aju++;
        }else{
            exis = true;
        } 
   }
   filtrar(permutacoes, tam, linhas, filtro);
    
}




