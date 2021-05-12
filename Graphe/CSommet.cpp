#include "CSommet.h"

int CSommet::iSOMincremente_numero = 0;
int* CSommet::piSOMstocke_numero = (int*) realloc(CSommet::piSOMstocke_numero, 1);

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
		CSommet::piSOMstocke_numero = (int*) realloc(CSommet::piSOMstocke_numero, iSize + 1);
		CSommet::piSOMstocke_numero[iSize + 1] = iNumero;
	}

	iSOMNb_entrant = 0;
	iSOMNb_sortant = 0;

	pSOMEntrant = (CArc**)realloc(pSOMEntrant, sizeof(CArc)*iSOMNb_entrant);
	pSOMSortant = (CArc**)realloc(pSOMSortant, sizeof(CArc)*iSOMNb_sortant);
}

CSommet::~CSommet()
{
	int iBoucle;
	for (iBoucle = 0; iBoucle < iSOMNb_entrant; iBoucle++)
	{
		delete pSOMEntrant[iBoucle];
	}
	for (iBoucle = 0; iBoucle < iSOMNb_sortant; iBoucle++)
	{
		delete pSOMSortant[iBoucle];
	}

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
	for (iBoucle = 0; iBoucle < iSize; iBoucle++) {		//Si le num a déjà été donné par l'utilisateur
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

CArc* CSommet::SOMlire_arc_entrant(int iDestination)
{
	int iBoucle;
	int iPosSomArv = -1;

	//Cherche la position dans le tableau du sommet en parametre
	while (iPosSomArv != -1 || iBoucle > iSOMNb_entrant) {
		if (iDestination == pSOMEntrant[iBoucle]->ARClire_destination())
			iPosSomArv = iBoucle;

		iBoucle++;
	}

	//ajoute l'arc dans les sommets concernes
	if (iPosSomArv != -1) {
		return pSOMEntrant[iPosSomArv];
	}
	else {
		void();
		//throw exception: un des deux sommets n'existe pas
	}
}

void CSommet::SOMajouter_arc_entrant(CArc* ARCarc)
{
	iSOMNb_entrant++;
	pSOMEntrant = (CArc**)realloc(pSOMEntrant, sizeof(CArc)*iSOMNb_entrant);

	pSOMEntrant[iSOMNb_entrant] = ARCarc;
}

CArc* CSommet::SOMlire_arc_sortant(int iDestination)
{
	int iBoucle;
	int iPosSomDep = -1;

	//Cherche la position dans le tableau du sommet en parametre
	while (iPosSomDep != -1 || iBoucle > iSOMNb_sortant) {
		if (iDestination == pSOMSortant[iBoucle]->ARClire_destination())
			iPosSomDep = iBoucle;

		iBoucle++;
	}

	//ajoute l'arc dans les sommets concernes
	if (iPosSomDep != -1) {
		return pSOMSortant[iPosSomDep];
	}
	else {
		void();
		//throw exception: un des deux sommets n'existe pas
	}
}

void CSommet::SOMajouter_arc_sortant(CArc* ARCarc)
{
	iSOMNb_sortant++;
	pSOMSortant = (CArc**)realloc(pSOMSortant, sizeof(CArc)*iSOMNb_sortant);

	pSOMSortant[iSOMNb_sortant] = ARCarc;
}
