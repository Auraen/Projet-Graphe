/*****************************************************************//**
 * \file   CGraphe.cpp
 * \brief  Ce fichier contient la definition des methodes de la classe
 * CGraphe.
 * 
 * \author Indique dans les commentaires de chaque methode
 * \date   May 2021
 *********************************************************************/
#include "CGraphe.h"

/**
 * @brief Constructeur par defaut
 * @return un objet CGraphe
 * @author Aurane
 */
CGraphe::CGraphe() {
	iGRANb_sommets = 0;
	pGRASommets = NULL;
}


/**
 * @brief Constructeur de confort: permet de creer un graphe avec un certain nombre de sommets
 * 
 * \param iNbSommets nombre de sommets du graphe
 * \param pSommet Tableau contenant les sommets du graphe
 * @author Aurane
 */
CGraphe::CGraphe(int iNbSommets, CSommet** pSommet) {
	int iBoucle;
	iGRANb_sommets = iNbSommets;
	pGRASommets = (CSommet**)realloc(pGRASommets, sizeof(CSommet)*iGRANb_sommets);

	for (iBoucle = 0; iBoucle < iGRANb_sommets; iBoucle++) {
		pGRASommets[iBoucle] = new CSommet(*pSommet[iBoucle]);
	}
}

/**
 * @brief Destructeur de la classe CGraphe.
 * @author Youssef
 */
CGraphe::~CGraphe() {
	int iBoucle;
	for (iBoucle = 0; iBoucle < iGRANb_sommets; iBoucle++)
		delete pGRASommets[iBoucle];

	free(pGRASommets);
}

/**
 * @brief Ajoute un sommet au graphe
 * 
 * \param pSommet Sommet a ajouter
 * @author Aurane
 */
void CGraphe::GRAajouter_sommet(CSommet* pSommet)
{
	pGRASommets = (CSommet**)realloc(pGRASommets, sizeof(CSommet*)*(iGRANb_sommets+1));

	pGRASommets[iGRANb_sommets] = pSommet;
	iGRANb_sommets++;
}

/**
 * @brief Supprime un sommet du graphe, designe par son numero
 * 
 * \param iNumSommet numero du sommet a supprimer
 * @author Aurane
 */
void CGraphe::GRAsupprimer_sommet(int iNumSommet)
{
	int iPos = GRAposition_sommet(iNumSommet);
	int iNbEntrant = pGRASommets[iPos]->SOMlire_nb_entrant();
	int iNbSortant = pGRASommets[iPos]->SOMlire_nb_sortant();
	CArc** ARCEntrant = pGRASommets[iPos]->SOMlire_arc_entrant();
	CArc** ARCSortant = pGRASommets[iPos]->SOMlire_arc_sortant();

	int iBoucle;
	int dest;

	//Suppression des arcs entrants du sommet
	for (iBoucle = 0; iBoucle < iNbEntrant; iBoucle++) {
		dest = ARCEntrant[iBoucle]->ARClire_destination();
		pGRASommets[dest]->SOMsupprimer_arc_sortant(iNumSommet);	//On supprime l'arc dans l'autre sommet
		pGRASommets[iPos]->SOMsupprimer_arc_entrant(dest);			//On supprime l'arc dans le sommet à suppr
	}
	
	//Suppression des arcs sortants du sommet
	for (iBoucle = 0; iBoucle < iNbSortant; iBoucle++) {
		dest = ARCSortant[iBoucle]->ARClire_destination();
		pGRASommets[dest]->SOMsupprimer_arc_entrant(iNumSommet);	//On supprime l'arc dans l'autre sommet
		pGRASommets[iPos]->SOMsupprimer_arc_sortant(dest);			//On supprime l'arc dans le sommet à suppr
	}

	for (iBoucle = iPos; iBoucle < iGRANb_sommets-1; iBoucle++) {
		pGRASommets[iBoucle] = pGRASommets[iBoucle + 1];
	}

	iGRANb_sommets--;

	pGRASommets = (CSommet**)realloc(pGRASommets, sizeof(CSommet)*iGRANb_sommets);

	/*Code Youssef
	
	int iNombreArcs = SOMsommet.iSOMNb_entrant + SOMsommet.iSOMNb_sortant;
	iGRANb_arcs = iGRANb_arcs - iNombreArcs;
	iGRANb_sommets = iGRANb_sommets - 1;
	CGraphe::GRAsupprimer_sommet(SOMsommet);
	*/
}

/**
 * @brief Getter pour le nombre de sommets du graphe.
 * 
 * \return un entier, le nombre de sommets du graphe
 * @author Aurane
 */
int CGraphe::GRAlire_nb_sommet()
{
	return iGRANb_sommets;
}

/**
 * @brief Ajoute un arc entre deux sommets.
 * 
 * \param iSommet_depart le numero du sommet duquel doit partir l'arc
 * \param iSommet_arrivee le numero du sommet auquel doit aller l'arc
 * @author Aurane
 */
void CGraphe::GRAajouter_arc(int iSommet_depart, int iSommet_arrivee)
{
	int iPosSomDep = GRAposition_sommet(iSommet_depart);
	int iPosSomArv = GRAposition_sommet(iSommet_arrivee);

	pGRASommets[iPosSomDep]->SOMajouter_arc_sortant(new CArc(iSommet_arrivee));
	pGRASommets[iPosSomArv]->SOMajouter_arc_entrant(new CArc(iSommet_depart));
}

/**
 * @brief Supprime un arc entre deux sommets.
 * 
 * \param iDepart le numero du sommet de depart de l'arc
 * \param iArrivee le numero du sommet d'arrivee de l'arc
 * @author Aurane
 */
void CGraphe::GRAsupprimer_arc(int iDepart, int iArrivee)
{
	int iPosDebut = GRAposition_sommet(iDepart);
	int iPosFin = GRAposition_sommet(iArrivee);

	pGRASommets[iPosDebut]->SOMsupprimer_arc_sortant(iArrivee);
	pGRASommets[iPosFin]->SOMsupprimer_arc_entrant(iDepart);

	iGRANb_arcs--;
}

/**
 * @brief Getter du nombre d'arcs du graphe.
 * 
 * \return un entier, le nombre d'arcs du graphe
 * @author Aurane
 */
int CGraphe::GRAlire_nb_arcs()
{
	return iGRANb_arcs;
}

/**
 * @brief Donne la position d'un sommet specifique dans le tableau de sommets.
 * 
 * \param iNum_sommet le numero du sommet a rechercher
 * \return la position du sommet dans pGRASommets
 * @author Aurane
 */
int CGraphe::GRAposition_sommet(int iNum_sommet)
{
	int iBoucle = 0;
	int iPosSom = -1;

	//Cherche la position dans le tableau des sommets en parametre
	while (iPosSom == -1 && iBoucle < iGRANb_sommets) {
		if (iNum_sommet == pGRASommets[iBoucle]->SOMlire_numero_sommet())
			iPosSom = iBoucle;
		iBoucle++;
	}
	
	if (iPosSom == -1) {
		void();
		//throw exception: le num de sommet n'appartient pas au tab
	}

	return iPosSom;
}



	void CGraphe::GRAafficher_graphe()
{

	   int iBoucle, jBoucle;
	   cout << "Affichage de grahe"<<endl;
	   for (iBoucle = 0; iBoucle < iGRANb_sommets ; iBoucle++)
	   {
		  cout << "sommet numéro:" << iBoucle<<endl;
		  cout <<pGRASommets[iBoucle] << endl;
		  cout << "les prochains sommets  sont"<<endl;

		  CArc **ArcSortant = pGRASommets[iBoucle]->SOMlire_arc_sortant();
		  for (jBoucle = 0; jBoucle < pGRASommets[iBoucle]->SOMlire_nb_sortant(); jBoucle++)
		  {
			  if (ArcSortant[jBoucle] != NULL) {
				  cout <<ArcSortant[jBoucle]->ARClire_destination() << endl;
			  }
			  else {
				  cout << "pas d'arc sortant";
			  }
		  }
	   }

}

	CGraphe CGraphe::GRAinverser() 
	{
		CGraphe *GrapheInverse = new CGraphe(iGRANb_sommets, pGRASommets);
		GrapheInverse->iGRANb_arcs = iGRANb_arcs;
		int iBoucle = 0;
		int jBoucle = 0;
		int kBoucle = 0;
		if (iGRANb_sommets > 0)
		{
			for (iBoucle = 0; iBoucle < iGRANb_sommets; iBoucle++)
			{
				CArc** TempArc1 = GrapheInverse->pGRASommets[iBoucle]->SOMlire_arc_entrant();
				CArc** TempArc2 = GrapheInverse->pGRASommets[iBoucle]->SOMlire_arc_sortant();
				for (jBoucle = 0; jBoucle <GrapheInverse-> pGRASommets[iBoucle]->SOMlire_nb_entrant(); jBoucle++) 
				{
					GrapheInverse->pGRASommets[iBoucle]->SOMsupprimer_arc_entrant(TempArc1[jBoucle]->ARClire_destination());
					GrapheInverse->pGRASommets[iBoucle]->SOMajouter_arc_entrant(TempArc2[jBoucle]);
				}
				for (kBoucle = 0; kBoucle < pGRASommets[iBoucle]->SOMlire_nb_entrant(); kBoucle++) 
				{
					GrapheInverse->pGRASommets[iBoucle]->SOMsupprimer_arc_sortant(TempArc2[kBoucle]->ARClire_destination());
					GrapheInverse->pGRASommets[iBoucle]->SOMajouter_arc_sortant(TempArc1[kBoucle]);
				}

			}

		}
		//throw exception:: le graphe est vide
		return *GrapheInverse;
		
	}