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
