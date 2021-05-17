#include "CActions.h"
#include "CGraphe.h"
#include "CArc.h"



void CActions::ACTmodifier_arc(CArc ARCarc, int iNouvelle_dest)
{
	ARCarc.ARCmodifier_destination(iNouvelle_dest);
}

/*CGraphe CActions::ACTafficher_graphe(CGraphe GRAgraphe)
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

void CActions::ACTsupprimer_arc(CGraphe GRAgraphe, int iDepart, int iArrivee)
{
	int iBoucle,jBoucle;
	//supprimer arc du sommet de depart
	for (iBoucle = 0; iBoucle < GRAgraphe->iGRANb_sommets; iBoucle++) {
		if (iDepart == GRAgraphe->pGRASommets[iBoucle]->iSOMNumero) {
			for (jBoucle = 0; jBoucle < GRAgraphe->pGRASommets[iBoucle]->iSOMNb_sortant; jBoucle++) {
				if (iArrivee == GRAgraphe->pGRASommets->pGRASommets[iBoucle]->pSOMSortant[jBoucle]->iARCDestination)
				{
					GRAgraphe->pGRASommets[iBoucle]->SOMsupprimer_arc_sortant(iArrivee);

				}
			}
		}
	}
	

	//supprimer arc du sommet de arrivee
	for (iBoucle = 0; iBoucle < GRAgraphe->iGRANb_sommets; iBoucle++) {
		if (iArrivee == GRAgraphe->pGRASommets[iBoucle]->iSOMNumero) {
			for (jBoucle = 0; jBoucle < GRAgraphe->pGRASommets[iBoucle]->iSOMNb_entrant; jBoucle++) {
				if (iArrivee == GRAgraphe->pGRASommets[iBoucle]->pSOMSortant[jBoucle]->iARCDestination)
				{
					GRAgraphe->pGRASommets->pGRASommets[iBoucle]->SOMsupprimer_arc_sortant(iArrivee);
				}
			}
		}
	}
	
}

void CActions::ACTmodifier_arc(CGraphe GRAgraphe, CArc ARCarc, int iNouvelle_Dest)
{

}



