#ifndef C_ARC_H
#define C_ARC_H

#include <iostream>
#include <assert.h>

#include "CExceptions.h"

using namespace std;

class CArc
{
private:
	int iARCDestination;
	int iARCPoids;

public:

	/**
	 * @brief Constructeur par défaut
	 * @author Youssef
	 */
	CArc();

	/**
	 * @brief Constructeur de confort.
	 *
	 * \param iDestination Destination de l'arc a créer
	 * @author Youssef
	 */
	CArc(int iDestination);

	/**
	* @brief Constructeur de confort.
	 *
	 * \param iDestination Destination de l'arc a créer
	 * \param iPoids Poids de l'arc
	 * @author Aurane
	 */
	CArc(int iDestination, int iPoids);

	/**
	 * @brief Destructeur de la classe CArc.
	 * @author Youssef
	 */
	~CArc();

	/**
	 * @brief Getter de la destination de l'arc.
	 *
	 * \return destination de l'arc
	 * @author Youssef
	 */
	int ARClire_destination();

	/**
	* @brief Getter du poids de l'arc.
	 *
	 * \return poids de l'arc
	 * @author Aurane
	 */
	int ARClire_poids();

	/**
	 * @brief Setter du poids de l'arc.
	 * 
	 * \param iPoids nouveau poids de l'arc
	 * @author Aurane
	 */
	void ARCmodifier_poids(int iPoids);
};
#endif
