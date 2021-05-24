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
};
#endif
