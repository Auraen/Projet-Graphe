/*****************************************************************//**
 * \file   CFichier.cpp
 * \brief  Contient la definition des methodes de la classe CFichier
 *
 * \author Aurane
 * \date   April 2021
 *********************************************************************/

#include "CFichier.h"

 /**
  * @brief Supprimes les caracteres ' ' d'une chaine de caractere.
  *
  * @param pcStr chaine dont il faut retirer les espaces
  */
void CFichier::FICsupprime_espace(char * pcStr)
{
	size_t iBoucle;
	int iRepere = 0;
	size_t iLength = strlen(pcStr);

	if (pcStr[0] == '\t') {
		for (iBoucle = 0; iBoucle < iLength; iBoucle++)
			if (pcStr[iBoucle] != '\t') {
				pcStr[iRepere++] = pcStr[iBoucle];
			}
	}
	else {
		for (iBoucle = 0; iBoucle < iLength; iBoucle++)
			if (pcStr[iBoucle] != ' ') {
				pcStr[iRepere++] = pcStr[iBoucle];
			}
	}

	pcStr[iRepere] = '\0';
}

/**
 * @brief Genere une matrice extraite d'un fichier texte.
 *
 * @param pcNom Nom du fichier dont il faut extraire une matrice
 * @return la matrice extraite du fichier
 */
CGraphe* CFichier::FIClire_graphe(char * pcNom)
{
	ifstream fichier(pcNom);
	CGraphe* GRAResult = new CGraphe();
	if (fichier.is_open()) {
		
		char* cLine = new char[2048];

		//Nb de Sommets
		do
		{
			fichier.getline(cLine, 2048);
			FICsupprime_espace(cLine);
		} while (cLine[0] == '\n' || cLine[0] == '\r' || cLine[0] == '\0');
		char * cBuffer = strtok(cLine, "=");
		cBuffer = strtok(NULL, "=");

		if (cBuffer == NULL) {
			throw CExceptions(EXCParse);
		}
		int iNbSommets = atoi(cBuffer);

		//Nb d'arcs
		do
		{
			fichier.getline(cLine, 2048);
			FICsupprime_espace(cLine);
		} while (cLine[0] == '\n' || cLine[0] == '\r' || cLine[0] == '\0');
		cBuffer = strtok(cLine, "=");
		cBuffer = strtok(NULL, "=");

		if (cBuffer == NULL) {
			throw CExceptions(EXCParse);
		}
		int iNbArcs = atoi(cBuffer);
		
		//Numéro du sommet
		do
		{
			fichier.getline(cLine, 2048);  // Ligne avec ecrit Sommets = [
			FICsupprime_espace(cLine);
		} while (cLine[0] == '\n' || cLine[0] == '\r' || cLine[0] == '\0');

		int iBoucle;
		for (iBoucle = 0; iBoucle < iNbSommets; iBoucle++) {
			fichier.getline(cLine, 2048); //Ligne avec le numéro du sommet
			cBuffer = strtok(cLine, "=");
			cBuffer = strtok(NULL, "=");
			GRAResult->GRAajouter_sommet(new CSommet(atoi(cBuffer)));
		}
		
		//Différents arcs
		do
		{
			fichier.getline(cLine, 2048);  // Ligne avec ecrit Arcs = [
			FICsupprime_espace(cLine);
		} while (cLine[0] == '\n' || cLine[0] == '\r' || cLine[0] == '\0' || cLine[0] == ']');
		
		int iDebut;
		int iFin;

		for (iBoucle = 0; iBoucle < iNbArcs; iBoucle++) {
			fichier.getline(cLine, 2048); // Premiere ligne avec un arc
			cBuffer = strtok(cLine, "="); //Début=
			cBuffer = strtok(NULL, "="); //n°debut
			
			iDebut = atoi(cBuffer);

			cBuffer = strtok(NULL, "="); //n° fin
			
			iFin = atoi(cBuffer);

			GRAResult->GRAajouter_arc(iDebut, iFin);
		}

		delete[] cLine;
	}
	else {
		throw CExceptions(EXCFic_nopen);
	}

	return GRAResult;
}
