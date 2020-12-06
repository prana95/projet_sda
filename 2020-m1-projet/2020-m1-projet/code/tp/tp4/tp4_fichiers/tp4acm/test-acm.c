#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>

#include "graphe-3.h"
#include "acm.h"

int main()
{
	int statut;
	graphe g,acm;
	graphe_stable(&g, 7);
	graphe_stable(&acm,7);
	graphe_ajouter_arete(&g, 0, 1, 7.);
	graphe_ajouter_arete(&g, 0, 3, 5.);
	graphe_ajouter_arete(&g, 1, 3, 9.);
	graphe_ajouter_arete(&g, 1, 2, 8.);
	graphe_ajouter_arete(&g, 1, 4, 7.);
	graphe_ajouter_arete(&g, 2, 4, 5.);
	graphe_ajouter_arete(&g, 3, 4, 15.);
	graphe_ajouter_arete(&g, 3, 5, 6.);
	graphe_ajouter_arete(&g, 4, 5, 8.);
	graphe_ajouter_arete(&g, 4, 6, 9.);
	graphe_ajouter_arete(&g, 5, 6, 11.);
	
	//affichage de grpahe initial
	//il faut fermer apres pour voir acm
	graphe_afficher(&g);
	graphe_ecrire_dot(&g,"graphe_initial.dot");
	system("dot -Tx11 graphe_initial.dot");
	system("dot -Tpdf graphe_initial.dot -o graphe_initial.pdf");
	
	/*for(i=0 ;i<graphe_get_n(&g);i++){
		for(j=0;j<graphe_get_n(&g);j++){
			printf("%f \n",graphe_get_cout(&g,i,j));
			
			if(graphe_get_multiplicite_arete(&g,i,j)!=0){
				printf("i=%d j=%d couts=%f \n",i,j,graphe_get_cout(&g,i,j));
			}
			
		}
		
	}*/
	/*printf("\n%d  %f\n",graphe_get_n(&g),DBL_MAX);*/
	//partie Prim 
	
	statut = graphe_acm_prim(&g, 0,&acm);
	if (statut == 0) {
		graphe_ecrire_dot_avec_acm(&g, &acm,"acm_prim.dot");
		system("dot -Tx11 acm_prim.dot");
		system("dot -Tpdf acm_prim.dot -o acm_prim.pdf");
		graphe_detruire(&acm);
	}
	graphe_detruire(&g);
	graphe_detruire(&acm);
	return EXIT_SUCCESS;
}
