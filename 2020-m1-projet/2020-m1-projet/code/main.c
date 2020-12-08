#include "citiesReader.h"
#include "graphe-3.h"
#include "acm.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void saveGraph(ListOfCities * cities,graphe* g){
  FILE* fileOut = NULL;
  fileOut = fopen("resuGraph.dat", "w");
  //pour un acm
  for(int i=0; i<cities->number; i++){
    for(int j=0; j<i; j++){
      if(graphe_get_multiplicite_arete(g,i,j)!=0)
        fprintf(fileOut, "%i %i\n", i, j);
    }
  }
  fclose(fileOut);
}



int main(int argc, char ** argv) {
  int statut;
  double cout=0;
  if( argc != 2 ){
    perror("Veuillez passer une population minimale en paramètre du programme");
    return EXIT_FAILURE;
  }
//-----------------------------------------------------------------
//--- READING cities
//-----------------------------------------------------------------

  int popMin = atoi(argv[1]);
  
  ListOfCities* cities;
  cities = citiesReader(popMin);

  // ... just to check! This line can be removed.
  for(int i=0; i<cities->number; i++){
    printf("%s %i %f %f\n", cities->name[i], cities->pop[i], cities->lat[i], cities->lon[i]);
  }
  
  
  /*****************************************************************/
  //il faut faire une graphe complet ensuite on appele la fonction kruscal pour donn une acm en sortie
  
  graphe g,acm;
  graphe_complet(&g,cities->number,cities);
  graphe_stable(&acm,cities->number);
  statut = graphe_acm_prim(&g,0,&acm);
  /*if (statut == 0) {
	graphe_ecrire_dot_avec_acm(&g, &acm,"acm_kruskal.dot");
	system("dot -Tx11 acm_kruskal.dot");
	system("dot -Tpdf acm_kruskal.dot -o acm_kruskal.pdf");
		
  }*/
	

  //formul est faux mais il donne une double(distance entre deux ville on souppose)
  //calcule de longueur entre deux ville
  double longueur=distance_ville(cities->lon[0],cities->lat[0],cities->lon[1],cities->lat[1]);
  printf("\n%f\n",longueur);
  
 /* for(int i=0;i<graphe_get_n(&acm);i++){
  	if(graphe_get_multiplicite_arete(&acm)!=0){
  		cout+=acm->cout;
  	}
  }
  */
  for(int i=0; i<cities->number; i++){
    for(int j=0; j<i; j++){
      if(graphe_get_multiplicite_arete(&acm,i,j)!=0)
        cout=cout+graphe_get_cout(&acm,i,j);
    }
  }
  printf("longueur=%f  %d\n",cout,statut);
  
  
  
  
  /******************************************************************/
  
  
  
  

//-----------------------------------------------------------------
//--- COMPUTING complete graph
//-----------------------------------------------------------------


  /* 
   Écriture du graphe (chaque ligne correspond à une arête)
   !!! Ci-dessous, on écrit le graphe complet pour l'exemple.
   Dans votre rendu, cette fonction prendra un graphe en argument,
   pas une liste de villes.
  */
  saveGraph(cities,&acm);

  graphe_detruire(&g);
  graphe_detruire(&acm);
  freeListOfCities(cities);

  return 0;
}

