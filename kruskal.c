#include<stdio.h>
#include<stdlib.h>

#define maxV 8

int min,custmin=0,pai[maxV];
int matriz[maxV][maxV] = {
						{999,3,4,3,999,999,999,999},
						{3,999,999,999,999,999,999,999},
						{4,999,999,999,8,8,999,999},
						{3,999,999,999,999,999,999,999},
						{999,999,8,999,999,999,7,7},
						{999,999,8,999,999,999,4,7},
						{999,999,999,999,7,4,999,2},
						{999,999,999,999,7,7,2,999}
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
	
	while(aresta<maxV){
		min=999;
		for(i=0;i<maxV;i++){
			for(j=0;j<maxV;j++){
				if(matriz[i][j]<min){
					min=matriz[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=busca(u);
		v=busca(v);
		if(verif(u,v)){
			printf("\nAresta (%d,%d) =%d",a,b,min);
			aresta++;
			custmin +=min;
		}
		matriz[a][b]=matriz[b][a]=999;
	}
	
	printf("\n\nCusto mínimo = %d\n",custmin);
}

int main(){
	kruskal();
	return 0;
}