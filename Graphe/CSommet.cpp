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

	pSOMEntrant = new CArc*[iSOMNb_entrant];
	pSOMSortant = new CArc *[iSOMNb_sortant];

}

CSommet::CSommet(int iNumero)
{
	int iBoucle;
	int iSize = sizeof(CSommet::piSOMstocke_numero) / sizeof(int);

	//Vérifie que le numéro n'est pas déjà attribué à un sommet
	for (iBoucle = 0 ; iBoucle < iSize ; iBoucle++) {
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

	pSOMEntrant = new CArc*[iSOMNb_entrant];
	pSOMSortant = new CArc *[iSOMNb_sortant];
}

CSommet::~CSommet()
{
	delete[] pSOMEntrant;
	delete[] pSOMSortant;
}

int CSommet::SOMlire_numero_sommet()
{
	return iSOMNumero;
}

void CSommet::SOMmodifier_numero_sommet(int iNumero)
{
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
