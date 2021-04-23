#include "CSommet.h"

int CSommet::iSOMincremente_numero = 0;

CSommet::CSommet()
{
	iSOMNumero = CSommet::iSOMincremente_numero;
	CSommet::iSOMincremente_numero++;

	iSOMNb_entrant = 0;
	iSOMNb_sortant = 0;

	pSOMEntrant = new CArc*[iSOMNb_entrant];
	pSOMSortant = new CArc *[iSOMNb_sortant];

}

CSommet::CSommet(int iNumero)
{
	iSOMNumero = iNumero;
	CSommet::iSOMincremente_numero++;
	//DEMANDER COMMENT GERER LE CAS DU SOMMET 367 MAIS ON VEUT DES SOMMETS DE 1 A 366

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