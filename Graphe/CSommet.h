#ifndef C_SOMMET_H
#define C_SOMMET_H

#include <iostream>
#include <assert.h>

#include "CArc.h"

class CSommet
{
private:
	int iSOMNumero;
	static int iSOMincremente_numero;
	static int* piSOMstocke_numero;
	int iSOMNb_entrant;
	int iSOMNb_sortant;
	CArc** pSOMEntrant;
	CArc** pSOMSortant;

public:
	/**
	 * @brief Constructeur par défaut.
	 * @author Aurane
	 */
	CSommet();

	/**
	 * @brief Constructeur de confort.
	 *
	 * \param iNumero Numero a attribuer au sommet cree
	 * @author Aurane
	 */
	CSommet(int iNumero);

	/**
	 * @brief Destructeur de la classe CSommet.
	 * @author Youssef
	 */
	~CSommet();

	/**
	 * @brief Getter du numero de sommet
	 *
	 * \return numero du sommet concerne
	 * @author Aurane
	 */
	int SOMlire_numero_sommet();

	/**
	 * @brief Setter du numero de sommet.
	 *
	 * \param iNumero numero a affecter au sommet
	 * @author Aurane
	 */
	void SOMmodifier_numero_sommet(int iNumero);

	/**
	 * @brief Getter nombre d'arcs entrants.
	 *
	 * \return nombre d'arcs entrants dans le sommet
	 * @author Aurane
	 */
	int SOMlire_nb_entrant();

	/**
	 * @brief Getter nombre d'arcs sortants.
	 *
	 * \return nombre d'arcs sortant du sommet
	 * @author Aurane
	 */
	int SOMlire_nb_sortant();

	/**
	 * @brief Getter des arcs entrants
	 *
	 * \return le tableau contenant les arcs entrants
	 * @author Aurane
	 */
	CArc** SOMlire_arc_entrant();

	/**
	 * @brief Getter des arcs sortant
	 *
	 * \return le tableau contenant les arcs sortants
	 * @author Aurane
	 */
	CArc** SOMlire_arc_sortant();

	/**
	 * @brief Ajoute un arc entrant au sommet.
	 *
	 * \param ARCarc Arc a ajouter
	 * @author Aurane
	 */
	void SOMajouter_arc_entrant(CArc* ARCarc);

	/**
	 * @brief Ajoute un arc sortant au sommet.
	 *
	 * \param ARCarc Arc a ajouter
	 * @author Aurane
	 */
	void SOMajouter_arc_sortant(CArc* ARCarc);

	/**
	 * @brief Supprime un arc entrant specifique.
	 *
	 * \param iDestination Destination de l'arc a supprimer
	 * @author Aurane
	 */
	void SOMsupprimer_arc_entrant(int iDestination);

	/**
	 * @brief Supprime un arc sortant specifique.
	 *
	 * \param iDestination Destination de l'arc a supprimer
	 * @author Aurane
	 */
	void SOMsupprimer_arc_sortant(int iDestination);
};
#endif
