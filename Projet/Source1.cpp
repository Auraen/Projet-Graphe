CArc::CArc() {
	iARCDestination = 0;
}

CArc::CArc(CArc arc) {
	iARCDestination = arc.iARCDestination;
}


CArc::CArc(int dest) {
	iARCDestination = dest;
}

CSommet::CSommet() {
	iSOMNombre_arc_arrivant = 0;
	iSOMNumero_arc_partant = 0;

	pSOMArc_arrivant = new CArc * [iSNombre_arc];
	pSOMArc_partant = new CArc * [iSNombre_arc];

}

CSommet::CSommet(int numero, CArc** arrivant, CArc** partant) {
	iSOMNumero = numero;
	**pSOMArc_arrivant = &arrivant;
	**pSOMArc_partant = &partant;
}

CSommet::~CSommet() {
	delete[] pSOMARC_arrivant;
	delete[] pSOMArc_partant;

}

CGraphe::CGraphe() {
	iGRANombre_de_sommets = 0
		pGRAsommets = new CSommet * [iGRANombre_de_sommets];

}

CGraphe::CGraphe(CGraphe graphe) {
	**pGRAsommets = &graphe.pGRAsommets;
}

CGraphe::CGraphe(CSommet** sommets) {
	**pGRAsommets = &sommets;
}

CGraphe::~CGraphe() {
	delete[] pGRAsommets;
}
