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

	pGRASommets = (CSommet**)realloc(pGRASommets, sizeof(CSommet**)*iGRANb_sommets);

	for (iBoucle = 0; iBoucle < iGRANb_sommets; iBoucle++) {
		pGRASommets[iBoucle] = new CSommet(*pSommet[iBoucle]);
	}
}

/**
 * @brief Destructeur de la classe CGraphe.
 * @author Youssef
 */
CGraphe::~CGraphe() {

	if (pGRASommets != nullptr) {
		int iBoucle;
		for (iBoucle = 0; iBoucle < iGRANb_sommets; iBoucle++)
			delete pGRASommets[iBoucle];

		free(pGRASommets);
		pGRASommets = nullptr;
	}
}

/**
 * @brief Ajoute un sommet au graphe
 *
 * \param pSommet Sommet a ajouter
 * @author Aurane
 */
void CGraphe::GRAajouter_sommet(CSommet* pSommet)
{
	pGRASommets = (CSommet**)realloc(pGRASommets, sizeof(CSommet**)*(iGRANb_sommets + 1));

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

	for (iBoucle = iPos; iBoucle < iGRANb_sommets - 1; iBoucle++) {
		pGRASommets[iBoucle] = pGRASommets[iBoucle + 1];
	}

	iGRANb_sommets--;

	pGRASommets = (CSommet**)realloc(pGRASommets, sizeof(CSommet**)*iGRANb_sommets);

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
		throw CExceptions(EXCNumTab);
	}

	return iPosSom;
}

/**
 * @brief Affiche le graphe.
 * @author Youssef
 */
void CGraphe::GRAafficher_graphe()const
{
	int iBoucleSommet;
	int iBoucleArc;

	cout << "Il y a " << iGRANb_sommets << " sommets" << endl;
	//Affichage de chaque sommet
	for (iBoucleSommet = 0; iBoucleSommet < iGRANb_sommets; iBoucleSommet++)
	{
		int iNumSommet = pGRASommets[iBoucleSommet]->SOMlire_numero_sommet();
		int iNbsortant = pGRASommets[iBoucleSommet]->SOMlire_nb_sortant();
		cout << "Sommet Numero " << iNumSommet << endl;
		cout << "Ce sommet contient " << iNbsortant << " arcs aux destinations suivantes:" << endl;

		//Affichage de chaque sommet sortant
		CArc** ARCSortant = pGRASommets[iBoucleSommet]->SOMlire_arc_sortant();
		for (iBoucleArc = 0; iBoucleArc < iNbsortant; iBoucleArc++) {
			cout << iNumSommet << " --> " << ARCSortant[iBoucleArc]->ARClire_destination() << " de poids "<< ARCSortant[iBoucleArc]->ARClire_poids() << endl;
		}
	}
}

/**
 * @brief Inverse le graphe.
 *
 * \return un nouveau graphe, l'inverse du premier
 * @author Aurane
 */
CGraphe* CGraphe::GRAinverser() const
{
	int iSommet = 0;
	int iArc = 0;
	CGraphe* GRAResult = new CGraphe();

	if (iGRANb_sommets > 0)
	{
		for (iSommet = 0; iSommet < iGRANb_sommets; iSommet++)
		{
			int iEntrant = pGRASommets[iSommet]->SOMlire_nb_entrant();
			int iSortant = pGRASommets[iSommet]->SOMlire_nb_sortant();
			CArc** ARCEntrant = pGRASommets[iSommet]->SOMlire_arc_entrant();
			CArc** ARCSortant = pGRASommets[iSommet]->SOMlire_arc_sortant();

			//Ajoute le sommet au graph inverse
			int iNumero = pGRASommets[iSommet]->SOMlire_numero_sommet();
			GRAResult->GRAajouter_sommet(new CSommet(iNumero));

			//Ajoute les arcs dans le graph inverse
			for (iArc = 0; iArc < iSortant; iArc++) {
				GRAResult->pGRASommets[iSommet]->SOMajouter_arc_entrant(ARCSortant[iArc]);
			}

			for (iArc = 0; iArc < iEntrant; iArc++) {
				GRAResult->pGRASommets[iSommet]->SOMajouter_arc_sortant(ARCEntrant[iArc]);
			}
		}
	}
	else
	{
		throw CExceptions(EXCGrapheVide);
	}

	return GRAResult;

}

/**
 * @brief Modifie le poids d'un arc.
 *
 * \param iDepart sommet de depart de l'arc
 * \param iArrivee sommet d'arrivee de l'arc
 * \param iNewPoids nouveau poids de l'arc
 * @author Aurane
 */
void CGraphe::GRAmodifierPoids(int iDepart, int iArrivee, int iNewPoids)
{
	int iposDepart = GRAposition_sommet(iDepart);
	int iposFin = GRAposition_sommet(iArrivee);

	int iNbsommet = pGRASommets[iposDepart]->SOMlire_nb_sortant();
	int iNbSortant = pGRASommets[iposDepart]->SOMlire_nb_sortant();
	CArc** ARCtabSortant = pGRASommets[iposDepart]->SOMlire_arc_sortant();

	int iBoucle = 0;
	int iPos = -1;

	while (iPos == -1 && iBoucle < iNbSortant) {
		if (iArrivee == ARCtabSortant[iBoucle]->ARClire_destination())
			iPos = iBoucle;
		iBoucle++;
	}

	if (iPos == -1) {
		void();
		//Throw cexception il n'existe pas d'arc ayant cette destination
	}
	
	ARCtabSortant[iPos]->ARCmodifier_poids(iNewPoids);
}

CGraphe::BellmanFord CGraphe::GRABellmanFord(int iDepart)
{
	int iNbSommets = iGRANb_sommets;
	BellmanFord Result;
	Result.iSommetDepart = iDepart;
	int* P = new int[iNbSommets];
	Result.Ds = new int[iNbSommets];

	int iBoucleSommets;
	int iBoucleSommets2;
	int iBoucleArc;
	bool PoidsInchangé = false;
	int longueur;

	for (iBoucleSommets = 0; iBoucleSommets < iNbSommets; iBoucleSommets++) {
		P[iBoucleSommets] = -1;
		Result.Ds[iBoucleSommets] = CheminMax;
	}

	int iPosDepart = GRAposition_sommet(iDepart);
	Result.Ds[iPosDepart] = 0;
	P[iPosDepart] = 0;

	for (iBoucleSommets = 1; iBoucleSommets < iNbSommets - 1 && !PoidsInchangé; iBoucleSommets++) {
		PoidsInchangé = true;
		for (iBoucleSommets2 = 0; iBoucleSommets2 < iNbSommets; iBoucleSommets2++) {
			if (P[iBoucleSommets2] == iBoucleSommets - 1) {
				int nbSortant = pGRASommets[iBoucleSommets2]->SOMlire_nb_sortant();
				CArc** ARCSortant = pGRASommets[iBoucleSommets2]->SOMlire_arc_sortant();

				for (iBoucleArc = 0; iBoucleArc < nbSortant; iBoucleArc++) {
					longueur = Result.Ds[iBoucleSommets2] + ARCSortant[iBoucleArc]->ARClire_poids();

					int iPosDest = GRAposition_sommet(ARCSortant[iBoucleArc]->ARClire_destination());

					if (longueur < Result.Ds[iPosDest]) {
						Result.Ds[iPosDest] = longueur;
						P[iPosDest] = iBoucleSommets;
						PoidsInchangé = false;
					}
				}
			}
		}

		//Verifier pour le cycle absorbant
		for (iBoucleSommets2 = 0; iBoucleSommets2 < iNbSommets; iBoucleSommets2++) {

				int nbSortant = pGRASommets[iBoucleSommets2]->SOMlire_nb_sortant();
				CArc** ARCSortant = pGRASommets[iBoucleSommets2]->SOMlire_arc_sortant();


				for (iBoucleArc = 0; iBoucleArc < nbSortant; iBoucleArc++) {
					int iPosDest = GRAposition_sommet(ARCSortant[iBoucleArc]->ARClire_destination());

					if (Result.Ds[iPosDest] != CheminMax) {
						if (Result.Ds[iBoucleSommets2] + ARCSortant[iBoucleArc]->ARClire_poids() < Result.Ds[iPosDest]) {
							Result.chemin = false;
							return Result;
						}
					}

				}
		}
	}
	Result.chemin = true;
	return Result;

	/*
	Entrée: un graphe orienté G=[S,A], des poids w sur les arcs A (i.e w: A -> R+), un sommet source s € S
	Sortie: un tab Ds indexé par S tel de Ds[t] est la longueur du + courts chemin de s à t dans G
			un booléean qui vaut Vrai si les + courts chemins ont pu être calculés, Faux sinon
	function Bellman-Ford(G,w,s)
		Soit P un tab de taille |S| initialisé à -1
		Soit Ds un tab de taille |S| initialisé à +inf
		Ds[s]<- 0											//chemin le plus court vers le chemin de départ = 0
		P[s]<- 0											//predecesseur du chemin le plus court 
		Pour i=1 à |S|-1 faire
			PoidsInchangé <- Vrai
			Pour tout sommet u € S tel que P[u] = i-1 faire
				pour tout arc (u,v) du graphe faire
					longueur <- Ds[u] + w(u,v)
					Si longueur < Ds[v] alors
						Ds[v] <- longueur
						P[v] <- i
						PoidsInchangé <- Faux
			Pour tout arc (u,v) du graphe faire
				si Ds[u] + W(u,v) < Ds[v]
					retourner Ds et Faux (il existe un cycle absorbant => pas de solution
			retourner Ds et Vrai

	Vous devez implémenter la méthode Bellman-Ford au sein de la classe CGraphe. Le poids d'un arc sera stocké au niveau de la classe CArc
	*/
}

void CGraphe::GRAAfficherBellmanFord(BellmanFord val)
{
	if (!val.chemin) {
		cout << "Ce sommet n'est pas lié à tous les sommets du graphe, les plus courts chemins n'ont donc pas été calculés." << endl;
	}
	else {
		int iBoucle;

		for (iBoucle = 0; iBoucle < iGRANb_sommets; iBoucle++) {			
			std::cout << "Depuis le sommet n° " << val.iSommetDepart << ", le chemin le plus court vers le sommet n°"<< pGRASommets[iBoucle]->SOMlire_numero_sommet() << " est de " << val.Ds[iBoucle] << std::endl;
		}
	}
}
