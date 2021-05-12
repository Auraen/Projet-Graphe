#include "CGraphe.h"

CGraphe::CGraphe() {
	iGRANb_sommets = 0;
	pGRASommets = new CSommet[iGRANb_sommets];
}

CGraphe::~CGraphe() {
	delete[] pGRASommets;
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
	CGraphe::GRAsupprimer_sommet(SOMsommet);

}

void CGraphe::GRAmodifier_sommet(int iNumero, CSommet SOMsommet)
{
	int iDiffrence = pGRASommets[iNumero].iSOMNb_entrant + pGRASommets[iNumero].iSOMNb_sortant - SOMsommet.iSOMNb_entrant - SOMsommet.SOMlire_nb_sortant;
	iGRANb_arcs = iGRANb_arcs - iDifference;
	pGRASommets[iNumero] = SOMsommet;
}