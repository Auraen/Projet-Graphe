#include "CGraphe.h"

CGraphe::CGraphe() {
	iGRANb_sommets = 0;
	pGRASommets = (CSommet**)malloc(sizeof(CSommet)*iGRANb_sommets);
}

CGraphe::CGraphe(int iNbSommets, CSommet** pSommet) {
	int iBoucle;
	iGRANb_sommets = iNbSommets;
	pGRASommets = (CSommet**)realloc(pGRASommets, sizeof(CSommet)*iGRANb_sommets);

	for (iBoucle = 0; iBoucle < iGRANb_sommets; iBoucle++) {
		pGRASommets[iBoucle] = new CSommet(*pSommet[iBoucle]);
	}
}

CGraphe::~CGraphe() {
	int iBoucle;
	for (iBoucle = 0; iBoucle < iGRANb_sommets; iBoucle++)
		delete(pGRASommets[iBoucle]);

	free(pGRASommets);
}

void CGraphe::GRAajouter_sommet(CSommet* pSommet)
{
	iGRANb_sommets++;
	pGRASommets = (CSommet**)realloc(pGRASommets, sizeof(CSommet)*iGRANb_sommets);

	pGRASommets[iGRANb_sommets] = pSommet;
}


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

int CGraphe::GRAlire_nb_sommet()
{
	return iGRANb_sommets;
}

void CGraphe::GRAajouter_arc(int iSommet_depart, int iSommet_arrivee)
{
	int iPosSomDep = GRAposition_sommet(iSommet_depart);
	int iPosSomArv = GRAposition_sommet(iSommet_arrivee);

	pGRASommets[iPosSomDep]->SOMajouter_arc_sortant(new CArc(iSommet_depart));
	pGRASommets[iPosSomArv]->SOMajouter_arc_entrant(new CArc(iSommet_arrivee));
}

/*void CGraphe::GRAsupprimer_sommet(CSommet SOMsommet)
{
	int iNombreArcs = SOMsommet.iSOMNb_entrant + SOMsommet.iSOMNb_sortant;
	iGRANb_arcs =iGRANb_arcs - iNombreArcs;
	iGRANb_sommets = iGRANb_sommets - 1;
	int iBoucle1,iBoucle2;
	int iSize = sizeof(CGraphe::pGRASommets) / sizeof(CSommet);
	for (iBoucle1 = 0; iBoucle1 < iSize; iBoucle1++)
	{
		if (pGRASommets[iBoucle1].SOMlire_numero_sommet() == SOMsommet.SOMlire_numero_sommet())
		{
			for (iBoucle2 = iBoucle1; iBoucle2 < iSize; iBoucle2++)
			{
				pGRASommets[iBoucle2] = pGRASommets[iBoucle2 + 1];
			}
			delete[] pGRASommets[iSize];
		}
	}



}

DANS LA MAUVAISE CLASSE ->> A DEPLACER*/


int CGraphe::GRAlire_nb_arcs()
{
	return iGRANb_arcs;
}

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
