#ifndef C_FICHIER_H
#define C_FICHIER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "CGraphe.h"


class CFichier
{
public:
	static CGraphe FIClire_graphe(char* pcNom);
	static void FICsupprime_espace(char* pcStr);

};
#endif
