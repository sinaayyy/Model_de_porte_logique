#include "twoInputGate.hpp"

twoInputGate::twoInputGate() {type = "twoInput";}
twoInputGate::~twoInputGate() {delete this;}

vector<Gate*> twoInputGate::getGates()
{
	vector<Gate*> v = {};
	v.push_back(g1);
	v.push_back(g2);
	return v;
}

int twoInputGate::getProf() const {return max(g1->getProf(), g2->getProf())+1;}

vector<vector<Gate*>> twoInputGate::empiler()
{
    vector<vector<Gate*>> g_stock;
	vector<vector<Gate*>> g_auxiliaire;

    vector<Gate*> g_etage;
    vector<Gate*> g_etage_recup;

    g_etage.push_back(this);
	g_etage_recup.push_back(g_etage[0]);

    int p = g_etage_recup[0]->getProf();
    g_auxiliaire.push_back(g_etage);
    g_etage.clear();

    Gate *GateCourant = g_etage_recup[0];
    while (p>0)
	{
        if (GateCourant->getType() == "twoInput")
		{
            if ((((twoInputGate*)(GateCourant))->getGates()[1]->getProf()) > (((twoInputGate*)(GateCourant))->getGates()[0]->getProf())) // prof(g2) > prof(g1) : ajout de g2 puis ajout de g1
			{
                g_etage_recup.push_back(((twoInputGate*)(GateCourant))->getGates()[1]);
                g_etage.push_back(g_etage_recup.back());
                g_etage_recup.push_back(((twoInputGate*)(GateCourant))->getGates()[0]);
                g_etage.push_back(g_etage_recup.back());
			}
				
			else
			{
                g_etage_recup.push_back(((twoInputGate*)(GateCourant))->getGates()[0]);
                g_etage.push_back(g_etage_recup.back());
                g_etage_recup.push_back(((twoInputGate*)(GateCourant))->getGates()[1]);
                g_etage.push_back(g_etage_recup.back());
			}
		}
		
		else
		{
            g_etage_recup.push_back(((oneInputGate*)(GateCourant))->getGate());
            g_etage.push_back(g_etage_recup.back());
        }

        do{g_etage_recup.erase(g_etage_recup.begin());
		GateCourant = g_etage_recup[0];}
		while ((g_etage_recup.size()>1) && GateCourant->getProf() == 0);

        if (p != GateCourant->getProf())
		{
            g_auxiliaire.push_back(g_etage);
            g_etage.clear();
			p = GateCourant->getProf();
        }
    }

    // Inversion des élts pour les prochains cycles de calculs
    for (int s = g_auxiliaire.size()-1; s>=0; s--) {g_stock.push_back(g_auxiliaire[s]);}
	
    return g_stock;
}