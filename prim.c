#include <stdio.h>

#define maxV 8
#define INF 1000

 int matriz[maxV][maxV] = {
						{0,2,0,6,5,0,0,0},
						{2,0,7,7,0,0,0,0},
						{0,7,0,0,6,2,0,0},
						{6,7,0,0,0,0,0,0},
						{5,0,6,0,0,0,4,5},
						{0,0,2,0,0,0,4,6},
						{0,0,0,0,4,4,0,1},
						{0,0,0,0,5,6,1,0}
						};
 
char inTree[maxV]; //1 se i já estiver na árvore geradora mínima
 
int d[maxV]; //vetor de distancias de i para a árvore, se i estiver na árvore já, d[i] não existe (para complexidade menor do algorítimo)
 
int whoTo[maxV]; //indice do próximo nó

void atualizaDistancias(int target) {//atualiza as distancias toda vez que um nó é adicionado à árvore
    int i;
	
    for (i = 0; i < maxV; ++i){//percorre as colunas da linha destino
        if ((matriz[target][i] != 0) && (d[i] > matriz[target][i])) {
            d[i] = matriz[target][i];//atualiza para manter o valor correto de d
            whoTo[i] = target;//define qual o pai
        }
	}
}
 
int main() {
	int i;
 
    for (i = 0; i < maxV; ++i) d[i] = INF; //Inicia o vetor de distancias
 
    for (i = 0; i < maxV; ++i) inTree[i] = 0; //inicia o vetor da árvore
 
    printf("Arestas da árvore geradora:\n");
    inTree[0] = 1; //adiciona o primeiro vetor à arvore
    atualizaDistancias(0);
 
    int total = 0;
    int j;
    for (j = 1; j < maxV; ++j) {
        //Procura o nó com a menor distância da árvore
        int min = -1;
        for (i = 0; i < maxV; ++i)
            if (!inTree[i])
                if ((min == -1) || (d[min] > d[i]))
                    min = i;
 
        //Adiciona o nó na árvore
        printf("\nAresta (%d,%d) = %d", whoTo[min], min, matriz[whoTo[min]][min]);
        inTree[min] = 1;
        total += d[min];
 
        atualizaDistancias(min);
    }
 
    printf("\n\nCusto mínimo: %d\n", total);
 
    return 0;
}