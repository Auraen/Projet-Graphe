/*****************************************************************//**
 * \file   CExceptions.cpp
 * \brief  Ce fichier contient la definition des methodes de la classe CExceptions
 *
 * \author Aurane
 * \date   April 2021
 *********************************************************************/

#include "CExceptions.h"

 /**
  * @brief Constructeur par defaut: initalise une exception.
  *
  */
CExceptions::CExceptions()
{
	iEXCCode = 0;
}

/**
 * @brief Constructeur de confort: initalise une exception de code iCode.
 *
 * \param iCode code de l'exception
 */
CExceptions::CExceptions(int iCode)
{
	iEXCCode = iCode;
}

/**
 * @brief Destructeur.
 *
 */
CExceptions::~CExceptions()
{

}

/**
 * @brief Getter pour le code de l'exception.
 *
 * \return un entier, le code de l'exception
 */
int CExceptions::EXClire_code()
{
	return iEXCCode;
}

/**
 * @brief Setter pour le code de l'exception.
 *
 * \param iCode nouveau code de l'exception
 */
void CExceptions::EXCmodifier_code(int iCode)
{
	iEXCCode = iCode;
}

