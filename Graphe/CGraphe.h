/*****************************************************************//**
 * \file   CGraphe.h
 * \brief  Ce fichier contient la declaration de la classe CGraphe
 * qui contient un ensemble de methodes permettant de modifier et
 * afficher un graphe
 * 
 * \author Aurane
 * \date   May 2021
 *********************************************************************/
#ifndef C_GRAPHE_H
#define C_GRAPHE_H

#include <iostream>
#include <assert.h>
#include "CSommet.h"

class CGraphe
{
private:
	CSommet** pGRASommets;
	int iGRANb_sommets;
	int iGRANb_arcs;

public:
	/**
	 * @brief Constructeur par defaut
	 * @return un objet CGraphe
	 * @author Aurane
	 */
	CGraphe();

	/**
	 * @brief Constructeur de confort: permet de creer un graphe avec un certain nombre de sommets
	 *
	 * \param iNbSommets nombre de sommets du graphe
	 * \param pSommet Tableau contenant les sommets du graphe
	 * @author Aurane
	 */
	CGraphe(int iNbSommets, CSommet** pSommet);

	/**
	 * @brief Destructeur de la classe CGraphe.
	 * @author Youssef
	 */
	~CGraphe();

	/**
	 * @brief Ajoute un sommet au graphe
	 *
	 * \param pSommet Sommet a ajouter
	 * @author Aurane
	 */
	void GRAajouter_sommet(CSommet* pSommet);

	/**
	 * @brief Supprime un sommet du graphe, designe par son numero
	 *
	 * \param iNumSommet numero du sommet a supprimer
	 * @author Aurane
	 */
	void GRAsupprimer_sommet(int iNumSommet);

	/**
	 * @brief Getter pour le nombre de sommets du graphe.
	 *
	 * \return un entier, le nombre de sommets du graphe
	 * @author Aurane
	 */
	int GRAlire_nb_sommet();

	/**
	 * @brief Ajoute un arc entre deux sommets.
	 *
	 * \param iSommet_depart le numero du sommet duquel doit partir l'arc
	 * \param iSommet_arrivee le numero du sommet auquel doit aller l'arc
	 * @author Aurane
	 */
	void GRAajouter_arc(int iSommet_depart, int iSommet_arrivee);

	/**
	 * @brief Supprime un arc entre deux sommets.
	 *
	 * \param iDepart le numero du sommet de depart de l'arc
	 * \param iArrivee le numero du sommet d'arrivee de l'arc
	 * @author Aurane
	 */
	void GRAsupprimer_arc(int iDepart, int iArrivee);

	/**
	 * @brief Getter du nombre d'arcs du graphe.
	 *
	 * \return un entier, le nombre d'arcs du graphe
	 * @author Aurane
	 */
	int GRAlire_nb_arcs();

	/**
	 * @brief Donne la position d'un sommet specifique dans le tableau de sommets.
	 *
	 * \param iNum_sommet le numero du sommet a rechercher
	 * \return la position du sommet dans pGRASommets
	 * @author Aurane
	 */
	int GRAposition_sommet(int iNum_sommet);

	/**
	 * @brief Affiche le graphe.
	 * @author Youssef
	 */
	static void GRAafficher_graphe();

	/**
	 * @brief Inverse le graphe.
	 * 
	 * \return un nouvel objet Cgraphe contenant le graphe inversé
	 * @author Youssef
	 */
	static CGraphe GRAinverser();
};
#endif
