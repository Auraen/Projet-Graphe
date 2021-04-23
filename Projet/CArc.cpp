#include "CArc.h"

CArc::CArc()
{
	iARCDestination = 0;
}

CArc::CArc(int iDestination)
{
	iARCDestination = iDestination;
}

CArc::~CArc()
{

}

int CArc::ARClire_destination()
{
	return iARCDestination;
}

void CArc::ARCmodifier_destination(int iDestination)
{
	iARCDestination = iDestination;
}

