#include "CSommet.h"

int CSommet::iSOMincremente_numero = 0;
int* CSommet::piSOMstocke_numero = new int[1];

CSommet::CSommet()
{
	iSOMNumero = CSommet::iSOMincremente_numero;

	int iBoucle;
	int iSize = sizeof(CSommet::piSOMstocke_numero) / sizeof(int);

	//Vérifie que le numéro n'est pas déjà attribué à un sommet
	for (iBoucle = 0; iBoucle < iSize; iBoucle++) {
		if (CSommet::piSOMstocke_numero[iBoucle] == iSOMNumero) {
			iSOMNumero++;
			CSommet::iSOMincremente_numero++;
		}
	}

	CSommet::iSOMincremente_numero++;

	iSOMNb_entrant = 0;
	iSOMNb_sortant = 0;

	pSOMEntrant = (CArc**)realloc(pSOMEntrant, sizeof(CArc)*iSOMNb_entrant);
	pSOMSortant = (CArc**)realloc(pSOMSortant, sizeof(CArc)*iSOMNb_sortant);
}

CSommet::CSommet(int iNumero)
{
	int iBoucle;
	int iSize = sizeof(CSommet::piSOMstocke_numero) / sizeof(int);

	//Vérifie que le numéro n'est pas déjà attribué à un sommet
	if (iNumero < iSize-1) {							//Si le num a déjà été donné automatiquement
		void();
		//throw CException truc
	}
	for (iBoucle = 0 ; iBoucle < iSize ; iBoucle++) {	//Si le num a déjà été donné par l'utilisateur
		if (CSommet::piSOMstocke_numero[iBoucle] == iNumero)
			void();
			//throw CException truc
	}

	iSOMNumero = iNumero;

	//Stocke le numéro donné par l'utilisateur
	if (iSize = 1) {
		CSommet::piSOMstocke_numero[0] = iNumero;
	}
	else {
		int* piTemp = new int[iSize + 1];
		for (iBoucle = 0; iBoucle < iSize; iBoucle++) {
			piTemp[iBoucle] = CSommet::piSOMstocke_numero[iBoucle];
		}
		piTemp[iSize + 1] = iNumero;
		delete[] CSommet::piSOMstocke_numero;
		CSommet::piSOMstocke_numero = piTemp;
	}

	iSOMNb_entrant = 0;
	iSOMNb_sortant = 0;

	pSOMEntrant = (CArc**)realloc(pSOMEntrant, sizeof(CArc)*iSOMNb_entrant);
	pSOMSortant = (CArc**)realloc(pSOMSortant, sizeof(CArc)*iSOMNb_sortant);
}

CSommet::~CSommet()
{
	free(pSOMEntrant);
	free(pSOMSortant);
}

int CSommet::SOMlire_numero_sommet()
{
	return iSOMNumero;
}

void CSommet::SOMmodifier_numero_sommet(int iNumero)
{
	int iBoucle;
	int iSize = sizeof(CSommet::piSOMstocke_numero) / sizeof(int);

	//Vérifie que le numéro n'est pas déjà attribué à un sommet
	if (iNumero < iSize - 1) {							//Si le num a déjà été donné automatiquement
		void();
		//throw CException truc
	}
	for (iBoucle = 0; iBoucle < iSize; iBoucle++) {	//Si le num a déjà été donné par l'utilisateur
		if (CSommet::piSOMstocke_numero[iBoucle] == iNumero)
			void();
		//throw CException truc
	}

	iSOMNumero = iNumero;
}

int CSommet::SOMlire_nb_entrant()
{
	return iSOMNb_entrant;
}


int CSommet::SOMlire_nb_sortant()
{
	return iSOMNb_sortant;
}

void CSommet::SOMajouter_arc_entrant(CArc ARCarc)
{
	iSOMNb_entrant++;
	pSOMEntrant = (CArc**)realloc(pSOMEntrant, sizeof(CArc)*iSOMNb_entrant);

	pSOMEntrant[iSOMNb_entrant] = &ARCarc;
}

void CSommet::SOMajouter_arc_sortant(CArc ARCarc)
{
	iSOMNb_sortant++;
	pSOMSortant = (CArc**)realloc(pSOMSortant, sizeof(CArc)*iSOMNb_sortant);

	pSOMSortant[iSOMNb_sortant] = &ARCarc;
}
