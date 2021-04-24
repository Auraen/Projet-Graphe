#ifndef C_ACTIONS_H
#define C_ACTIONS_H

#include <iostream>
#include <assert.h>

#include "CArc.h"
#include "CGraphe.h"

class CActions
{
public:
	static void ACTmodifier_arc(CArc ARCarc);
	static void ACTsupprimer_arc(CArc ARCarc);
	static void ACTafficher_graphe(CGraphe GRAgraphe);
	static CGraphe ACTinverser(CGraphe GRAgraphe);
};
#endif
