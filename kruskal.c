#include<stdio.h>
#include<stdlib.h>

#define INF 1000
#define maxV 8

int min,custmin=0,pai[maxV];
int matriz[maxV][maxV] = {
						{INF,3,4,3,INF,INF,INF,INF},
						{3,INF,INF,INF,INF,INF,INF,INF},
						{4,INF,INF,INF,8,8,INF,INF},
						{3,INF,INF,INF,INF,INF,INF,INF},
						{INF,INF,8,INF,INF,INF,7,7},
						{INF,INF,8,INF,INF,INF,4,7},
						{INF,INF,INF,INF,7,4,INF,2},
						{INF,INF,INF,INF,7,7,2,INF}
						};

int busca(int i){
	while(pai[i]) i=pai[i];
	return i;
}

int verif(int i,int j){
	if(i!=j){
		pai[j]=i;
		return 1;
	}
	return 0;
}

void kruskal(){
	int i,j,a,b,u,v,aresta=1;
	
	printf("\nArestas da árvore geradora:\n");
	
	while(aresta<maxV){ //enquanto o número de arestas for menor que o número de vértices
		min=INF; //define a distancia atual em infinito
		for(i=0;i<maxV;i++){
			for(j=0;j<maxV;j++){
				if(matriz[i][j]<min){//achou uma aresta com valor mais baixo do que o atual
					min=matriz[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=busca(u);
		v=busca(v);
		if(verif(u,v)){//Verifica se conecta 2 árvores diferentes
			printf("\nAresta (%d,%d) = %d",a,b,min);
			aresta++;
			custmin +=min;//incrementa o custo total da árvore
		}//caso contrário
		matriz[a][b]=matriz[b][a]=INF;//remove a aresta
	}
	
	printf("\n\nCusto mínimo = %d\n",custmin);
}

int main(){
	kruskal();
	return 0;
}