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
	void SOMmodifier_nb_entrant(int iNombre);
	int SOMlire_nb_sortant();
	void SOMmodifier_nb_sortant(int iNombre);
	void SOMlire_arc_entrant(CArc ARCarc);
	void SOMajouter_arc_entrant(CArc ARCarc);
	void SOMlire_arc_sortant(CArc ARCarc);
	void SOMajouter_arc_sortant(CArc ARCarc);
};
#endif