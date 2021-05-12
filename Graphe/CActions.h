#ifndef C_ACTIONS_H
#define C_ACTIONS_H

#include <iostream>
#include <assert.h>

#include "CArc.h"
#include "CGraphe.h"

class CActions
{
public:
	static void ACTmodifier_arc(CArc ARCarc,int iNouvelle_Dest);
	static void ACTafficher_graphe(CGraphe GRAgraphe);
	static CGraphe ACTinverser(CGraphe GRAgraphe);
};
#endif
