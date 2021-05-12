#include "CGraphe.h"

CGraphe::CGraphe() {
	iGRANb_sommets = 0;
	pGRASommets = (CSommet*) realloc(pGRASommets, sizeof(CSommet)*iGRANb_sommets);
}

CGraphe::~CGraphe() {
	free(pGRASommets);
}

int CGraphe::GRAlire_nb_sommet()
{
	return iGRANb_sommets;
}

void CGraphe::GRAmodifier_nb_sommet(int iNombre)
{
	iGRANb_sommets = iNombre;
}

int CGraphe::GRAlire_nb_arcs()
{
	return iGRANb_arcs;
}

void CGraphe::GRAmodifier_nb_arcs(int iNombre)
{
	iGRANb_arcs = iNombre;
}

void CGraphe::GRAsupprimer_sommet(CSommet SOMsommet)
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

void CGraphe::GRAmodifier_sommet(int iNumero, CSommet SOMsommet)
{
	int iDiffrence = pGRASommets[iNumero].iSOMNb_entrant + pGRASommets[iNumero].iSOMNb_sortant - SOMsommet.iSOMNb_entrant - SOMsommet.SOMlire_nb_sortant;
	iGRANb_arcs = iGRANb_arcs - iDifference;
	pGRASommets[iNumero] = SOMsommet;
}