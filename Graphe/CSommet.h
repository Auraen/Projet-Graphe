#ifndef C_SOMMET_H
#define C_SOMMET_H

#include <iostream>
#include <assert.h>

#include "CArc.h"

class CSommet
{
private:
	int iSOMNumero;
	static int iSOMincremente_numero;
	static int* piSOMstocke_numero;
	int iSOMNb_entrant;
	int iSOMNb_sortant;
	CArc** pSOMEntrant;
	CArc** pSOMSortant;

public:
	CSommet();
	CSommet(int iNumero);
	~CSommet();
	int SOMlire_numero_sommet();
	void SOMmodifier_numero_sommet(int iNumero);
	int SOMlire_nb_entrant();
	int SOMlire_nb_sortant();
	CArc** SOMlire_arc_entrant();
	void SOMajouter_arc_entrant(CArc* ARCarc);
	CArc** SOMlire_arc_sortant();
	void SOMajouter_arc_sortant(CArc* ARCarc);
	void SOMsupprimer_arc_entrant(int iDestination);
	void SOMsupprimer_arc_sortant(int iDestination);
};
#endif
