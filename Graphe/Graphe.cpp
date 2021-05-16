/*****************************************************************//**
 * \file   Graphe.cpp
 * \brief  Ce fichier contient le main du programme.
 *
 * \author Aurane
 * \date   May 2021
 *********************************************************************/

#include <iostream>
#include <assert.h>

#include "CFichier.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc > 1) {
		CGraphe *GRAListe_Graphes = new CGraphe[argc - 1];
		int iBoucle;

		//Extraction des matrices en lisant les fichiers
		for (iBoucle = 0; iBoucle < argc - 1; iBoucle++)
		{
			GRAListe_Graphes[iBoucle] = CFichier::FIClire_graphe(argv[iBoucle + 1]);
		}

		delete[] GRAListe_Graphes;

		cout << endl << "Fin du programme";

	}
	else {
		cout << "Veuillez donner le nom d'un fichier en parametre lors de l'appel du programme" << endl;
		return 1;
	}
}