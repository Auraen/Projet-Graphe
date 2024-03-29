/*****************************************************************//**
 * \file   CFichier.h
 * \brief  Contient la declaration de la classe CFichier
 * CFichier contient des m�thodes statiques qui permettent de generer
 * une matrice a partir de la lecture d'un fichier.
 *
 * \author Aurane
 * \date   April 2021
 *********************************************************************/

#ifndef C_FICHIER_H
#define C_FICHIER_H

#define EXCFic_nopen 2
#define EXCParse 1

#include <iostream>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cctype>

#include "CGraphe.h"

#pragma warning(disable : 4996)

class CFichier
{
public:

	/**
	 * @brief Supprimes les caracteres ' ' d'une chaine de caractere.
	 *
	 * @param pcStr chaine dont il faut retirer les espaces
	 */
	static void FICsupprime_espace(char* pcStr);

	/**
	 * @brief Genere une matrice extraite d'un fichier texte.
	 *
	 * @param pcNom Nom du fichier dont il faut extraire une matrice
	 * @return la matrice extraite du fichier
	 */
	static CGraphe* FIClire_graphe(char* pcNom);
};

#endif
