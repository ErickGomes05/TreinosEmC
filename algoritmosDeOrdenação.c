#include <stdio.h>
#include <string.h>


typedef struct tipoAlunos
{
    char nome[32];
    unsigned idade;
    int id;

}tipoAlunos;


void MeuSelectionSort (tipoAlunos v[],unsigned tamV){
    unsigned x, y,posMenor;
    tipoAlunos temp;

    for(x = 0; x < tamV-1; x++){
        posMenor = x;
        for(y = x+1; y < tamV; y++){
            if(strcmp(v[posMenor].nome,v[y].nome)>0){
                posMenor = y;
            }
        }

        temp = v[x];
        v[x] = v[posMenor];
        v[posMenor] = temp;
    }
}

void MeuInsertSort (tipoAlunos vet[], int tamV){
    int i,j;
    tipoAlunos pivot;

    for(i = 1; i < tamV; i++){
        pivot = vet[i];
        j = i-1;

        while((j>=0)&&(strcmp(pivot.nome,vet[j].nome)<0)){
            vet[j+1] = vet[j];
            j--;
        }

        vet[j+1] = pivot;
    }
}

void preencherVetor (tipoAlunos v[], unsigned tamV){
    unsigned x;
    for(x=0; x < tamV;x++){
        printf("\n_______________________\n");
        printf("digite o nome: ");
        scanf("%[^\n]%*c",v[x].nome);
        printf("\ndigite a idade: ");
        scanf("%u%*c",&v[x].idade);
        printf("\ndigite o id: ");
        scanf("%d%*c",&v[x].id);
        printf("\n______________________\n");
      
    }
}

void Mostrar (tipoAlunos v[], unsigned tamV){
    unsigned x;
    for(x=0; x < tamV;x++){
        printf("\n--------------------\n");
        printf("nome: %s\n",v[x].nome);
        printf("idade: %u\n",v[x].idade);
        printf("id: %d\n",v[x].id);
        printf("\n--------------------\n");
      
    }
}









int main(){
    tipoAlunos vetor[3];
    unsigned tamV = 3;

    preencherVetor(vetor,tamV);

    Mostrar(vetor,tamV);
    
    //MeuSelectionSort(vetor,tamV);
    MeuInsertSort(vetor,tamV);
    printf("Vetor Ordenado:\n");

    
    Mostrar(vetor,tamV);

    return 0;
}
