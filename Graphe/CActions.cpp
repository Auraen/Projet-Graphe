#include "CActions.h"
#include "CGraphe.h"
#include "CArc.h"



void CActions::ACTmodifier_arc(CArc ARCarc, int iNouvelle_dest)
{
	ARCarc.ARCmodifier_destination(iNouvelle_dest);
}

/*CGraphe ACTafficher_graphe(CGraphe GRAgraphe)
{
	
	int iBoucle, jBoucle;
	cout << "Affige de grahe"<<endl;
	for (iBoucle = 0; iBoucle < GRAgraphe.iGRANb_sommets ; iBoucle++)
	{
		cout << "sommet numéro:" << iBoucle;
		cout << GRAgraphe.pGRASommets[iBoucle] << endl;
		cout << "les prochains sommets  sont";
		for (jBoucle = 0; jBoucle < GRAgraphe.pGRASommets[iBoucle].pSOMSortant->iSOMNb_sortant ; jBoucle++)
		{
			if (GRAgraphe.pGRASommets[iBoucle].pSOMSortant[jBoucle] != NULL) {

				cout << GRAgraphe.pGRASommets[iBoucle].pSOMSortant[jBoucle]->iARCDestination << endl;
			}
			else {
				cout << "pas d'arc sortant";
			}
		}
	}
	
}*/

