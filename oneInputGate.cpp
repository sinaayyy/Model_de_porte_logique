#include "oneInputGate.hpp"

oneInputGate::oneInputGate() {type = "oneInput";}
oneInputGate::~oneInputGate() {delete this;}

Gate* oneInputGate::getGate(){return g;}

int oneInputGate::getProf() const {return g->getProf()+1;}

vector<vector<Gate*>> oneInputGate::empiler()
{
    vector<vector<Gate*>> g_stock; // à return
	vector<vector<Gate*>> g_auxiliaire; // servira pour le return car utilisée pour les calculs

    vector<Gate*> g_etage; // pour stock sur un étage
    vector<Gate*> g_etage_recup; // pour récupérer g_etage en cas de clear

    g_etage.push_back(this); // on ajoute le Gate actuel à g_etage
	g_etage_recup.push_back(g_etage[0]);
    int p = g_etage[0]->getProf()+1; // profondeur sup
    

    // Tant qu'on n'a pas atteint un InputGate, on calcule
	while (p>0)
	{
		Gate *GateCourant = g_etage_recup[0]; // on récup le 1er élt de g_etage_recup

        if (p>GateCourant->getProf())
		{
            g_auxiliaire.push_back(g_etage); // on ajoute g_etage à g_auxiliaire
            g_etage.clear(); // on va changer de prof donc on clear la g_etage
			p = GateCourant->getProf(); // changement de prof
        }

        // En cas de twoInputGate, on appelle la fonction respective
		if (GateCourant->getType() == "twoInput")
		{
            g_stock = GateCourant->empiler();
			g_stock.resize(g_stock.size()-1); // A METTRE SINON DEDOUBLEMENT AVEC NEGATEGATE LORSQU'ON AFFICHE LE CIRCUIT !!!
            break;
        }

		// Sinon, on ajoute le oneInputGate actuel
		else
		{
			g_etage_recup.push_back(((oneInputGate*)(GateCourant))->getGate());
            g_etage.push_back(g_etage_recup.back());
        }

        // Supprimer le 1er élt pour le recommencement de la boucle while (si on y retourne) avec le 2e élt de g_etage_recup (cf l.30)
		g_etage_recup.erase(g_etage_recup.begin());
    }

    // Inversion des élts pour les prochains cycles de calculs
    for (int s = g_auxiliaire.size()-1; s>=0; s--) {g_stock.push_back(g_auxiliaire[s]);}

    return g_stock;
}