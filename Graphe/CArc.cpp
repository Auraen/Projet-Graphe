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

