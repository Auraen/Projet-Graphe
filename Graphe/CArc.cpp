#include "CArc.h"

/**
 * @brief Constructeur par d�faut
 * @author Youssef
 */
CArc::CArc()
{
	iARCDestination = 0;
}

/**
 * @brief Constructeur de confort.
 * 
 * \param iDestination Destination de l'arc a cr�er
 * @author Youssef
 */
CArc::CArc(int iDestination)
{
	iARCDestination = iDestination;
}

/**
 * @brief Destructeur de la classe CArc.
 * @author Youssef
 */
CArc::~CArc()
{

}

/**
 * @brief Getter de la destination de l'arc.
 * 
 * \return destination de l'arc
 * @author Youssef
 */
int CArc::ARClire_destination()
{
	return iARCDestination;
}

