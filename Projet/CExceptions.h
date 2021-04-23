/*****************************************************************//**
 * \file   CExceptions.h
 * \brief  Ce fichier contient la declaration de la classe CExceptions.
 *
 * \author Aurane
 * \date   April 2021
 *********************************************************************/

#ifndef C_EXCEPTIONS_H
#define C_EXCEPTIONS_H

#include <iostream>
#include <assert.h>

class CExceptions
{
private:
	int iEXCCode;

public:
	/**
	 * @brief Constructeur par defaut: initalise une exception.
	 *
	 */
	CExceptions();

	/**
	 * @brief Constructeur de confort: initalise une exception de code iCode.
	 *
	 * \param iCode code de l'exception
	 */
	CExceptions(int iCode);

	/**
	 * @brief Destructeur.
	 *
	 */
	~CExceptions();

	/**
	 * @brief Getter pour le code de l'exception.
	 *
	 * \return un entier, le code de l'exception
	 */
	int EXClire_code();

	/**
	 * @brief Setter pour le code de l'exception.
	 *
	 * \param iCode nouveau code de l'exception
	 */
	void EXCmodifier_code(int iCode);
};
#endif