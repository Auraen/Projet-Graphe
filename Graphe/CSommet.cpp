/*****************************************************************//**
 * \file   CSommet.cpp
 * \brief  Ce fichier contient la définition des methodes de la classe
 * CSommet.
 *
 * \author  Indique dans les commentaires de chaque methode
 * \date   May 2021
 *********************************************************************/

#include "CSommet.h"

int CSommet::iSOMincremente_numero = 0;
int* CSommet::piSOMstocke_numero = NULL;

/**
 * @brief Constructeur par défaut.
 * @author Aurane
 */
CSommet::CSommet()
{
	iSOMNumero = CSommet::iSOMincremente_numero;

	int iBoucle;
	int iSize = sizeof(CSommet::piSOMstocke_numero) / sizeof(int);

	//Verifie que le numero n'est pas deja attribue a un sommet
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

/**
 * @brief Constructeur de confort.
 * 
 * \param iNumero Numero a attribuer au sommet cree
 * @author Aurane
 */
CSommet::CSommet(int iNumero)
{
	int iBoucle;
	int iSize;
	if (CSommet::piSOMstocke_numero != NULL) {
		iSize = sizeof(CSommet::piSOMstocke_numero) / sizeof(int);
	}
	else
	{
		iSize = 0;
		CSommet::piSOMstocke_numero = (int*)realloc(CSommet::piSOMstocke_numero, iSize + 1);
	}

	//Verifie que le numero n'est pas deja attribue a un sommet
	if (iNumero < iSize-1) {							//Si le num a deja ete donne automatiquement
		void();
		//throw CException truc
	}
	for (iBoucle = 0 ; iBoucle < iSize ; iBoucle++) {	//Si le num a deja ete donne par l'utilisateur
		if (CSommet::piSOMstocke_numero[iBoucle] == iNumero)
			void();
			//throw CException truc
	}

	iSOMNumero = iNumero;
	iSize++;
	//Stocke le numero donne par l'utilisateur
	if (iSize == 1) {
		CSommet::piSOMstocke_numero[0] = iNumero;
	}
	else {
		CSommet::piSOMstocke_numero = (int*) realloc(CSommet::piSOMstocke_numero, iSize);
		CSommet::piSOMstocke_numero[iSize-1] = iNumero;
	}

	iSOMNb_entrant = 0;
	iSOMNb_sortant = 0;

	pSOMEntrant = (CArc**)realloc(pSOMEntrant, sizeof(CArc)*iSOMNb_entrant);
	pSOMSortant = (CArc**)realloc(pSOMSortant, sizeof(CArc)*iSOMNb_sortant);
}

/**
 * @brief Constructeur de recopie.
 *
 * \param SOMdup Sommet à recopier
 * @author Aurane
 */
CSommet::CSommet(CSommet &SOMdup)
{
	int iBoucle;

	iSOMNumero = SOMdup.iSOMNumero;
	iSOMNb_entrant = SOMdup.iSOMNb_entrant;
	iSOMNb_sortant = SOMdup.iSOMNb_sortant;

	pSOMEntrant = (CArc**)realloc(pSOMEntrant, sizeof(CArc)*iSOMNb_entrant);
	pSOMSortant = (CArc**)realloc(pSOMSortant, sizeof(CArc)*iSOMNb_sortant);

	
	for (iBoucle = 0; iBoucle < iSOMNb_entrant; iBoucle++)
	{
		pSOMEntrant[iBoucle] = new CArc(*SOMdup.pSOMEntrant[iBoucle]);
	}

	for (iBoucle = 0; iBoucle < iSOMNb_sortant; iBoucle++)
	{
		pSOMSortant[iBoucle] = new CArc(*SOMdup.pSOMSortant[iBoucle]);
	}
}

/**
 * @brief Destructeur de la classe CSommet.
 * @author Youssef
 */
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

/**
 * @brief Getter du numero de sommet
 * 
 * \return numero du sommet concerne
 * @author Aurane
 */
int CSommet::SOMlire_numero_sommet()
{
	return iSOMNumero;
}

/**
 * @brief Setter du numero de sommet.
 * 
 * \param iNumero numero a affecter au sommet
 * @author Aurane
 */
void CSommet::SOMmodifier_numero_sommet(int iNumero)
{
	int iBoucle;
	int iSize;
	if (CSommet::piSOMstocke_numero != NULL) {
		iSize = sizeof(CSommet::piSOMstocke_numero) / sizeof(int);
	}
	else
	{
		iSize = 0;
	}

	//Verifie que le numero n'est pas deja attribue a un sommet
	if (iNumero < iSize - 1) {							//Si le num a deja ete donne automatiquement
		void();
		//throw CException truc
	}
	for (iBoucle = 0; iBoucle < iSize; iBoucle++) {		//Si le num a deja ete donne par l'utilisateur
		if (CSommet::piSOMstocke_numero[iBoucle] == iNumero)
			void();
		//throw CException truc
	}

	iSOMNumero = iNumero;
}

/**
 * @brief Getter nombre d'arcs entrants.
 * 
 * \return nombre d'arcs entrants dans le sommet
 * @author Aurane
 */
int CSommet::SOMlire_nb_entrant()
{
	return iSOMNb_entrant;
}

/**
 * @brief Getter nombre d'arcs sortants.
 *
 * \return nombre d'arcs sortant du sommet
 * @author Aurane
 */
int CSommet::SOMlire_nb_sortant()
{
	return iSOMNb_sortant;
}

/**
 * @brief Getter des arcs entrants
 * 
 * \return le tableau contenant les arcs entrants
 * @author Aurane
 */
CArc** CSommet::SOMlire_arc_entrant()
{
	return pSOMEntrant;
}

/**
 * @brief Ajoute un arc entrant au sommet.
 * 
 * \param ARCarc Arc a ajouter
 * @author Aurane
 */
void CSommet::SOMajouter_arc_entrant(CArc* ARCarc)
{
	iSOMNb_entrant++;
	pSOMEntrant = (CArc**)realloc(pSOMEntrant, sizeof(CArc)*iSOMNb_entrant);

	pSOMEntrant[iSOMNb_entrant-1] = ARCarc;
}

/**
 * @brief Getter des arcs sortant
 *
 * \return le tableau contenant les arcs sortants
 * @author Aurane
 */
CArc** CSommet::SOMlire_arc_sortant()
{
	return pSOMSortant;
}

/**
 * @brief Ajoute un arc sortant au sommet.
 *
 * \param ARCarc Arc a ajouter
 * @author Aurane
 */
void CSommet::SOMajouter_arc_sortant(CArc* ARCarc)
{
	iSOMNb_sortant++;
	pSOMSortant = (CArc**)realloc(pSOMSortant, sizeof(CArc)*iSOMNb_sortant);

	pSOMSortant[iSOMNb_sortant-1] = ARCarc;
}

/**
 * @brief Supprime un arc entrant specifique.
 * 
 * \param iDestination Destination de l'arc a supprimer
 * @author Aurane
 */
void CSommet::SOMsupprimer_arc_entrant(int iDestination)
{
	int iBoucle = 0;
	int iPos = -1;

	while (iPos == -1 && iBoucle < iSOMNb_entrant) {
		if (iDestination == pSOMEntrant[iBoucle]->ARClire_destination())
			iPos = iBoucle;

		iBoucle++;
	}

	if (iPos == -1) {
		void();
		//Throw cexception il n'existe pas d'arc ayant cette destination
	}

	delete pSOMEntrant[iPos];
	iSOMNb_entrant--;

	for (iBoucle = iPos; iBoucle < iSOMNb_entrant; iBoucle++) {
		pSOMEntrant[iBoucle] = pSOMEntrant[iBoucle + 1];
	}
	
	if (iSOMNb_entrant == 0) {
		free(pSOMEntrant);
	}else
		pSOMEntrant = (CArc**)realloc(pSOMEntrant, sizeof(CArc*)*iSOMNb_entrant);
}

/**
 * @brief Supprime un arc sortant specifique.
 *
 * \param iDestination Destination de l'arc a supprimer
 * @author Aurane
 */
void CSommet::SOMsupprimer_arc_sortant(int iDestination)
{
	int iBoucle = 0;
	int iPos = -1;

	while (iPos == -1 && iBoucle < iSOMNb_sortant) {
		if (iDestination == pSOMSortant[iBoucle]->ARClire_destination())
			iPos = iBoucle;

		iBoucle++;
	}

	if (iPos == -1) {
		void();
		//Throw cexception il n'existe pas d'arc ayant cette destination
	}

	delete pSOMSortant[iPos];
	iSOMNb_sortant--;

	for (iBoucle = iPos; iBoucle < iSOMNb_sortant; iBoucle++) {
		pSOMSortant[iBoucle] = pSOMSortant[iBoucle + 1];
	}

	if (iSOMNb_sortant == 0) {
		free(pSOMSortant);
	}
	else
		pSOMSortant = (CArc**)realloc(pSOMSortant, sizeof(CArc*)*iSOMNb_sortant);
}

