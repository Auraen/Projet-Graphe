#ifndef C_GRAPHE_H
#define C_GRAPHE_H

#include <iostream>
#include <assert.h>

#include "CSommet.h"

class CGraphe
{
private:
	CSommet* pGRASommets;
	int iGRANb_sommets;
	int iGRANb_arcs;

public:
	CGraphe();
	~CGraphe();
	void GRAajouter_sommet();
	void GRAmodifier_sommet(int iNumero, CSommet SOMsommet);
	void GRAsupprimer_sommet(CSommet SOMsommet);
	int GRAlire_nb_sommet();
	void GRAmodifier_nb_sommet(int iNombre);
	void GRAajouter_arc(int iSommet_depart, int iSommet_arrivee);
	void GRAsupprimer_arc(int iSommet_depart, int iSommet_arrivee);
	int GRAlire_nb_arcs();
	void GRAmodifier_nb_arcs(int iNombre);
};
#endif
