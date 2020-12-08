#include "citiesReader.h"
#include "graphe-3.h"
#include "acm.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void saveGraph(ListOfCities * cities){
  FILE* fileOut = NULL;
  fileOut = fopen("resuGraph.dat", "w");
  //pour un graphe complet
  for(int i=0; i<cities->number; i++){
    for(int j=0; j<i; j++){
      fprintf(fileOut, "%i %i\n", i, j);
    }
  }
  fclose(fileOut);
}



int main(int argc, char ** argv) {
 
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
  
  
  
  
  //formul est faux mais il donne une double(distance entre deux ville on souppose)
  //calcule de longueur entre deux ville
  //double longueur=longueur_ville(cities->lon[0],cities->lat[0],cities->lon[1],cities->lat[1]);
  //printf("\n%f\n",longueur);
  
  
  
  
  
  
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
  saveGraph(cities);


  freeListOfCities(cities);

  return 0;
}

