/**
 * \file acm.h
 * \brief Calcul et représentation d'arbres couvrant minimaux (en-tête)
 * \version 1
 * \date lundi 14 octobre 2019
 * \authors Pierre Rousselin, Antoine Rozenknop, Sophie Toulouse
 */

#ifndef ACM_H
#define ACM_H

#include "graphe-3.h"

/**
 * \brief Calcule l'arbre couvrant minimal de g par l'algorithme de Prim partant
 * du sommet \a depart
 * \param g adresse de la variable graphe à lire
 * \param acm adresse de l'arbre couvrant minimal à écrire
 * \return 0 si tout s'est bien passé, -1 en cas de problème d'allocation
 * mémoire
 *
 * On suppose qu'aucun poids d'une arête présente dans \a g n'est égal à DBL_MAX et
 * que g est connexe.
 * De la mémoire est allouée pour \a acm. Il faut la libérer avec la
 * fonction \a graphe_detruire.
 */
int graphe_acm_prim(graphe *g, int depart,graphe * acm);

/**
 * \brief Calcule l'arbre couvrant minimal de g par l'algorithme de Kruskal
 * \param g adresse de la variable graphe à lire
 * \param acm adresse de l'arbre couvrant minimal à écrire
 * \return 0 si tout s'est bien passé, -1 en cas de problème d'allocation
 * mémoire
 *
 * On suppose que \a g est connexe.
 * De la mémoire est allouée pour \a acm. Il faut la libérer avec la
 * fonction \a graphe_detruire.
 */
int graphe_acm_kruskal(graphe *g, graphe *acm);

/**
 * \brief Écrit dans le fichier nommé \a nom_fichier une description au format
 * dot du graphe \a g avec son arbre couvrant minimal \a acm
 * \param g adresse de la variable graphe à lire
 * \param acm adresse de l'arbre couvrant minimal à lire
 * \return 0 si tout s'est bien passé, -1 en cas de problème d'entrée sortie
 *
 * Les arêtes de l'arbre couvrant minimal sont tracées en rouge. Celles qui
 * n'appartiennent pas à cet arbre couvrant sont tracées en noir.
 */
int graphe_ecrire_dot_avec_acm(graphe *g, graphe *acm, char *nom_fichier);

#endif /* ACM_H */
