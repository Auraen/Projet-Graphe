#ifndef C_ARC_H
#define C_ARC_H

#include <iostream>
#include <assert.h>

class CArc
{
private:
	int iARCDestination;


public:
	CArc();
	CArc(int iDestination);
	~CArc();
	int ARClire_destination();
	void ARCmodifier_destination(int iDestination);
};
#endif
