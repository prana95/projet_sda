








#include<stdio.h>
#include<stdlib.h>

int main(){
	int tab[4]={1,2,3,4};
	int i=0;
	printf("%d\n",i);  //i=0
	printf("%d\n",tab[i++]);  //tab[i=i+1]=1 il regarde d'abord tab[i] =1 ensuite il fais i=i+1 (il incremente de 1) donc on a un
	printf("%d\n",i);  //i=1
	printf("\n\n");
	
	i=0;
	printf("%d\n",i);  //i=0
	printf("%d\n",tab[++i]);  //tab[i+1=i]=2 il incremente ensuite il regarde  tab[i]
	printf("%d\n",i);  //i=1n
	
	printf("\n\n");
	i=0;
	for(i=0;i<4;i++){
		printf("i=%d  ",i);
	}
	printf("\n%d \n",i);
	return 0;
}











































/*
test
int minkey(int key[],bool mstset,graphe * g){
	int min=INT_MAX,min_index;
	int i;
	for(i=0;i<g->n;i++){
		if(mstset== false && key[v]<min){
			min=key[i];
			min_index=v;
		}
	}
	return min_index;
}

void primMst(graphe * g,int depart){
	int parent[g->n];
	int key[g->n];
	bool mstset[g->n];
	int i;
	
	for(i=o;i<g->n;i++){
		key[i]=INT_MAX;
		mstset[i]=false;
	}
	
	key[0]=depart;
	parent[0]=-1;
	
	
	for(i=0;g->n-1;i++){
		int u=minkey(key,mstset,g)
	}
	
	mstset[u]=true;
	
	for(i=0;i<g->n;i++){
		if(graphe_get_multiplicite_arete(g,u,i) && mstset==false && graphe_get_cout(g,u,i)<key[i]){
			paretn[i]=u;
			key[i]=graphe_get_cout(g,u,i);
		}
	}
	
	for(i=0;i<g->n;i++){
		printf("%d ",parent[i]);
	}
	
	
} */
