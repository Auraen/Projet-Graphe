#include "CSommet.h"








CGraphe::CGraphe(CGraphe graphe) {
	**pGRAsommets = &graphe.pGRAsommets;
}

CGraphe::CGraphe(CSommet** sommets) {
	**pGRAsommets = &sommets;
}


