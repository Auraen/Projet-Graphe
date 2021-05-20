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
	CGraphe();
	CGraphe(int iNbSommets, CSommet** pSommet);
	~CGraphe();
	void GRAajouter_sommet(CSommet* pSommet);
	void GRAsupprimer_sommet(int iNumSommet);
	int GRAlire_nb_sommet();
	void GRAajouter_arc(int iSommet_depart, int iSommet_arrivee);
	void GRAsupprimer_arc(int iDepart, int iArrivee);
	int GRAlire_nb_arcs();
	int GRAposition_sommet(int iNum_sommet);
	static void GRAafficher_graphe();
	static CGraphe GRAinverser();
};
#endif
