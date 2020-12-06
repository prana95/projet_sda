/**
 * \file acm.h
 * \brief Calcul et représentation d'arbres couvrant minimaux (implémentation)
 * \version 1
 * \date lundi 14 octobre 2019
 * \authors Pierre Rousselin, Antoine Rozenknop, Sophie Toulouse
 */
#include "acm.h"

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <limits.h> 
#include <stdbool.h> 
/*************** Prim */

int minkey(double key[],bool mstset[],graphe * g){
	double min=DBL_MAX;
	int min_index=0;
	int i;
	for(i=0;i<g->n;i++){
		if(mstset[i]== false && key[i]<min){
			min=key[i];
			min_index=i;
		}
	}
	return min_index;
}

int graphe_acm_prim(graphe * g,int depart,graphe * acm){
	int parent[g->n];
	double key[g->n];
	bool mstset[g->n];
	int i,j,u;
	
	for(i=0;i<g->n;i++){
		key[i]=DBL_MAX;
		mstset[i]=false;
		//parent[i]=0;
	}
	
	key[0]=depart;
	parent[0]=-1;
	
	
	for(j=0;j<g->n-1;j++){
		u=minkey(key,mstset,g);
		mstset[u]=true;
		
		for(i=0;i<g->n;i++){
		//	printf("%d %f   %f \n\n",graphe_get_multiplicite_arete(g,u,i),graphe_get_cout(g,u,i),key[i]);
			if(graphe_get_multiplicite_arete(g,u,i)!=0 && mstset[i]==false && graphe_get_cout(g,u,i)<key[i]){
			
				parent[i]=u;
				key[i]=graphe_get_cout(g,u,i);
			}
		}
	}
	for(i=1;i<g->n;i++){
		graphe_ajouter_arete(acm,parent[i],i,key[i]);
	}
	//graphe_ajouter_arete(graphe* g, int v, int w, double cout)
	
	//graphe_ajouter_arete(acm,parent[i],i,)
	return 0;
	
	
} 



/*************** Kruskal */

/* ne modifier que la fonction graphe_acm_kruskal */

/**
 * \brief Type \a arete avec cout
 *
 * Une arête est représentée par ses deux extrémités :
 * \a v et \a w et son coût \a cout
 * Pour l'unicité de la représentation, on supposera que
 * \f$ v \leq w \f$.
 * On accèdera directement aux champs de cette structure.
 */
typedef struct arete_t {
	int v; /**<plus petite extrémité de l'arête */
	int w; /**<plus grande extrémité de l'arête */
	double cout; /**<coût de l'arête */
} arete;

/**
 * \brief Trie les arêtes du graphe par coût croissant
 * \param g adresse du graphe à lire
 * \return un pointeur vers un tableau des arêtes de g triées par coût
 * croissant. Les boucles sont supprimées et en cas d'arêtes multiples, seule
 * l'arête de plus petit coût est présente dans le tableau. Si l'allocation du
 * tableau a échoué, la valeur de retour est \a NULL.
 * La taille du tableau est graphe_get_m(g) ; les arêtes supprimées donnent
 * lieu à des entrées {v:0,w:0,cout:0.0} à la fin du tableau.
 *
 * La fonction appelante devra libérer la mémoire allouée au tableau avec la
 * fonction \a free.
 */
static struct arete_t *graphe_tri_aretes(graphe * g);


int graphe_acm_kruskal(graphe *g, graphe *acm)
{
	/* TODO */
	return -1;
}





/*********************************************/
/*  fonctions utilitaires à ne pas modifier  */
/*********************************************/

/**
 * \brief Compare les arêtes par coût
 * \param e1 adresse de la première arête
 * \param e2 adresse de la deuxième arête
 * \return -1, 0 ou 1 selon que le coût de e1 est respectivement inférieur,
 * égal ou supérieur au coût de e2.
 *
 * Cette fonction n'est utilisée que par \a graphe_tri_arete et ne doit pas être
 * modifiée.
 */
static int cmp_arete(const void *e1, const void *e2)
{
	const arete *f1 = e1;
	const arete *f2 = e2;
	if (f1->cout == f2->cout)
		return 0;
	if (f1->cout < f2->cout)
		return -1;
	return 1;
}

#pragma GCC diagnostic ignored "-Wunused-function"
static arete *graphe_tri_aretes(graphe *g)
{
	int v, w, i = 0;
	arete *tab = calloc(graphe_get_m(g), sizeof(arete));
	if (!tab)
		return NULL;
	for (v = 0; v < graphe_get_n(g); ++v)
		for (w = v + 1; w < graphe_get_n(g); ++w)
			if (graphe_get_multiplicite_arete(g, v, w)) {
				tab[i].v = v;
				tab[i].w = w;
				tab[i].cout = graphe_get_cout(g, v, w);
				++i;
			}
	qsort(tab, i, sizeof(arete), cmp_arete);
	return tab;
}
#pragma GCC diagnostic pop


int graphe_ecrire_dot_avec_acm(graphe *g, graphe *acm, char *nom_fichier)
{
	int u, v;
	FILE *f = fopen(nom_fichier, "w");
	if (!f) { perror("fopen"); return -1; }
	fputs("graph {\n", f);
	for (u = 0; u < graphe_get_n(g); ++u)
		fprintf(f, "\t%d;\n", u);
	fputs("\n", f);
	fputs("\tsubgraph g {\n", f);
	for (u = 0; u < graphe_get_n(g); ++u)
		for (v = u; v < graphe_get_n(g); ++v)
			if (graphe_get_multiplicite_arete(g, u, v) &&
				( u == v || !graphe_get_multiplicite_arete(acm, u, v)))
					fprintf(f, "\t\t%d -- %d [label = %.2f];\n",
						u, v, graphe_get_cout(g, u, v));
	fputs("\t}\n", f);
	fputs("\tsubgraph acm {\n\t\tedge [color = red]\n", f);
	for (u = 0; u < graphe_get_n(acm); ++u)
		for (v = u; v < graphe_get_n(acm); ++v)
			if (graphe_get_multiplicite_arete(acm, u, v))
				fprintf(f, "\t\t %d -- %d [fontcolor = red, label = %.2f];\n",
					u, v, graphe_get_cout(acm, u, v));
	fputs("\t}\n}\n", f);
	fclose(f);
	return 0;
}
