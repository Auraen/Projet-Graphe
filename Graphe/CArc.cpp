#include "CArc.h"

/**
 * @brief Constructeur par défaut
 * @author Youssef
 */
CArc::CArc()
{
	iARCDestination = 0;
	iARCPoids = 1;
}

/**
 * @brief Constructeur de confort.
 * 
 * \param iDestination Destination de l'arc a créer
 * @author Youssef
 */
CArc::CArc(int iDestination)
{
	iARCDestination = iDestination;
	iARCPoids = 1;
}

/**
 * @brief Constructeur de confort.
 *
 * \param iDestination Destination de l'arc a créer
 * @author Youssef
 */
CArc::CArc(int iDestination, int iPoids)
{
	iARCDestination = iDestination;
	iARCPoids = iPoids;
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

/**
* @brief Getter du poids de l'arc.
 *
 * \return poids de l'arc
 * @author Aurane
 */
int CArc::ARClire_poids()
{
	return iARCPoids;
}

/**
 * @brief Setter du poids de l'arc.
 *
 * \param iPoids nouveau poids de l'arc4
 * @author Aurane
 */
void CArc::ARCmodifier_poids(int iPoids)
{
	iARCPoids = iPoids;
}

