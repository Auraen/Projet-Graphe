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
	int iBoucle;
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

CMatrice<double> CFichier::FIClire_matrice(char * pcNom)
{
	ifstream fichier(pcNom);
	CMatrice<double> MATResult;
	if (fichier.is_open()) {

		char* cLine = new char[2048];

		//Type des elements de la matrice
		do
		{
			fichier.getline(cLine, 2048);
			FICsupprime_espace(cLine);
		} while (cLine[0] == '\n' || cLine[0] == '\r' || cLine[0] == '\0');
		char * cBuffer = strtok(cLine, "=");
		cBuffer = strtok(NULL, "=");

		if (cBuffer[0] != 'd' && cBuffer[0] != 'D') {
			throw CExceptions(EXCType_Mat);
		}


		//Nb de Lignes
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

		MATResult.MATmodifier_nb_line(atoi(cBuffer));

		//Nb de colonnes
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

		MATResult.MATmodifier_nb_column(atoi(cBuffer));

		//Elements de la matrice
		do
		{
			fichier.getline(cLine, 2048);  // Ligne avec ecrit Matrice = [
			FICsupprime_espace(cLine);
		} while (cLine[0] == '\n' || cLine[0] == '\r' || cLine[0] == '\0');
		fichier.getline(cLine, 2048); // Premiere ligne avec les valeurs

		int iLine, iColumn;
		double dElement;
		int iNb_Line = MATResult.MATlire_nb_line();
		int iNb_Column = MATResult.MATlire_nb_column();

		for (iLine = 0; iLine < iNb_Line; iLine++)
		{
			if (cLine[0] == '\t') {
				FICsupprime_espace(cLine);
			}

			cBuffer = strtok(cLine, " ");

			while (cLine[0] == '\n' || cLine[0] == '\r' || cLine[0] == '\0')
			{
				fichier.getline(cLine, 2048);
				cBuffer = strtok(NULL, " ");
			}

			for (iColumn = 0; iColumn < iNb_Column; iColumn++) {

				if (cBuffer == nullptr) {
					throw CExceptions(EXCNenough_Val);
				}

				dElement = atof(cBuffer);
				MATResult.MATmodifier_element(iLine, iColumn, dElement);
				cBuffer = strtok(NULL, " ");
			}

			if (cBuffer != nullptr) {
				throw CExceptions(EXCToo_much_Val);
			}

			do
			{
				fichier.getline(cLine, 2048);
			} while (cLine[0] == '\n' || cLine[0] == '\r' || cLine[0] == '\0');
		}

		delete[] cLine;
	}
	else {
		throw CExceptions(EXCFic_nopen);
	}

	return MATResult;
}
*/