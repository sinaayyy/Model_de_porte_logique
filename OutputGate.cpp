#include "OutputGate.hpp"

char OutputGate::output_name = '@';

OutputGate::OutputGate(Gate* g) : oneInputGate()
{
	output_name = output_name + 1;
	
	this->g = g;
	this->g_stock = g->empiler();

	val = g->eval();
	expr = g->getexpr();
	expr_wvalues = g->getexpr_wvalues();
}

OutputGate::~OutputGate(){delete this;}

int OutputGate::compt = 0;

vector<vector<Gate*>> OutputGate::getGSTOCK() {return g_stock;}

void OutputGate::saveInFile() const
{    
	string outputDirectoryName = "circuits_sauv";
	string fileName = "circuit" + string(1,output_name);
	fileName += ".txt";
	ofstream out("circuits_sauv/" + fileName);
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
	cout << "Circuit " << string(1,output_name) << endl << endl;

	int c_input = 1;
	for(InputGate *i : InputGate::InputVector)
	{cout << "Input n° " << c_input << " : " << i->getexpr() << " = " << i->eval() << " --- "; c_input++;}
	cout << endl;
		
	this->afficher_circuit();
	
	cout << "Expression : " << this->getexpr() << endl;
	cout << "Expression valuée : " << this->getexpr_wvalues() << endl;
	cout << "Result : " << this->eval() << endl << endl;

	cout.rdbuf(coutbuf);
	out.close();

	compt++;
}

void OutputGate::afficher_circuit() const
{
    if (g != nullptr)
	{
        int dl=0, mid=1;
        for (int i=0; i< (int (g_stock.size()) ); i++) // on parcoure g_stock pour afficher chaque Gate
		{
            cout << string(dl, ' '); // espaces depuis la gauche

			// affichage pour les Gates d'un même étage de leur attribut calcul ('nom : val' pour les InputGate et 'OPERATEUR' sinon)
            for (auto gate: g_stock[i])
			{
                cout << gate->getcalcul();
                cout << string(mid, ' ');
            }

            cout << endl; // passage à la ligne...
            cout << string(dl, ' ');

			// ... puis affichage des | qui continuent le circuit
			int _ = g_stock[i].size();
            while (_--)
			{
                cout << " | ";
                cout << string(mid, ' ');
            }

            cout << endl;

            // Ajout des ++
            if (i != (int (g_stock.size()) )-1)
			{
                cout << string(dl + 1, ' ');
                
                if (g_stock[i].size() == 1)
				{
                    cout << string((mid/2)+3, '+') << endl;
                    cout << string(dl+2*i+3, ' ');
                    cout << '|';
                } // -> si Gate unique à cet étage

                else
				{
                    for (int j=0; j < (int (g_stock[i].size())) / 2; j++) {
                        cout << string((mid/2)+2, '+');
                        cout << string(1, ' ');
                        cout << string((mid/2)+2, '+');
                        cout << string(mid+2, ' ');
                    }

                    cout << endl;

                    for (int j=0; j < (int (g_stock[i].size()) )/2; j++)
					{
                        cout << string(dl+(mid/2)+3, ' ');
                        cout << "|";
                        cout << string(mid+3, ' ');
                    }
                }
                cout << endl;
                dl += (mid/2) + 2; mid = dl+3;
            }
        }

        cout << string(dl+1, ' ') << output_name << endl;
    }
	else {cout << "Pointeur renvoyant vers le Gate dans OutputGate est null";}

    cout << endl;
}