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
	if (argc == 2) {

		CGraphe* GRAGraphe_extrait = new CGraphe();
		CGraphe* GRAGraphe_inverse = new CGraphe();
		
		try
		{
			GRAGraphe_extrait = CFichier::FIClire_graphe(argv[1]);
		}
		catch (CExceptions EXCexception)
		{
			int iCode_Exception = EXCexception.EXClire_code();

			cout << "Erreur lors de la lecture du fichier: " << endl << endl;

			switch (iCode_Exception) {
			case 1:
				cout << "ERREUR: Le nombre de sommets et/ou d'arcs n'a pas ete renseigne correctement" << endl << "Veuillez verifier votre fichier" << endl;
				cout << "Interruption du programme" << endl;
				return 1;

			case 2:
				cout << "ERREUR: Le fichier n'a pas pu etre ouvert" << endl << "Veuillez verifier le nom et/ou le chemin du fichier saisi" << endl;
				cout << "Interruption du programme" << endl;
				return 1;

			case 3:
				cout << "ERREUR: Le sommet mentionne n'appartient pas au tableau" << "Veuille verifier son numero de sommet" << endl;
				cout << "Interruption du programme" << endl;
				return 1;

			case 4:
				cout << "ERREUR: Le graphe est vide, impossible de l'inverser" << endl;
			}
		}
		
		cout << "Le graphe extrait du fichier est:" << endl;
		GRAGraphe_extrait->GRAafficher_graphe();

		GRAGraphe_inverse = GRAGraphe_extrait->GRAinverser();
		cout << endl << endl << "L'inverse de ce graphe est:" << endl;
		GRAGraphe_inverse->GRAafficher_graphe();

		cout << endl << endl << "Fin du programme";
	}
	else {
		cout << "Veuillez donner le nom d'un seul fichier en parametre lors de l'appel du programme" << endl;
		return 1;
	}
}