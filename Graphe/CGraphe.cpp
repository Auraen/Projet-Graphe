#include "CGraphe.h"

CGraphe::CGraphe() {
	iGRANb_sommets = 0;
	pGRASommets = (CSommet**)realloc(pGRASommets, sizeof(CSommet)*iGRANb_sommets);
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


void CGraphe::GRAsupprimer_sommet(CSommet SOMsommet)
{
	int iNombreArcs = SOMsommet.iSOMNb_entrant + SOMsommet.iSOMNb_sortant;
	iGRANb_arcs = iGRANb_arcs - iNombreArcs;
	iGRANb_sommets = iGRANb_sommets - 1;
	CGraphe::GRAsupprimer_sommet(SOMsommet);

}

int CGraphe::GRAlire_nb_sommet()
{
	return iGRANb_sommets;
}

void CGraphe::GRAajouter_arc(int iSommet_depart, int iSommet_arrivee)
{
	int iBoucle;
	int iPosSomDep = -1;
	int iPosSomArv = -1;

	while ((iPosSomDep != -1 && iPosSomArv != -1) || iBoucle > iGRANb_sommets) {
		if (iSommet_depart == pGRASommets[iBoucle]->SOMlire_numero_sommet)
			iPosSomDep = iBoucle;

		if (iSommet_arrivee == pGRASommets[iBoucle]->SOMlire_numero_sommet)
			iPosSomArv = iBoucle;

		iBoucle++;
	}

	if (iPosSomArv != -1 && iPosSomDep != -1) {
		pGRASommets[iPosSomDep]->SOMajouter_arc_sortant(new CArc(iSommet_depart));
		pGRASommets[iPosSomArv]->SOMajouter_arc_entrant(new CArc(iSommet_arrivee));
	}
	else {
		void();
		//throw exception: un des deux sommets n'existe pas
	}
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