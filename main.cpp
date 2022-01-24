#include "oneInputGate.hpp"
#include "twoInputGate.hpp"

#include "twoInputGates/AndGate.hpp"
#include "twoInputGates/OrGate.hpp"
#include "twoInputGates/XorGate.hpp"
#include "oneInputGates/NegateGate.hpp"

#include "twoInputGates/NAndGate.hpp"
#include "twoInputGates/NOrGate.hpp"
#include "twoInputGates/XNorGate.hpp"

#include "OutputGate.hpp"

int main()
{
	cout << "----------" << endl;

	// ########## 1. Exemple du sujet de l'énoncé avec possibilité de garder le même circuit en changeant les valeurs (uniquement pour 2 InputGate)
    cout << "########## 1. Exemple du sujet de l'énoncé avec possibilité de garder le même circuit en changeant les valeurs (uniquement pour 2 InputGate) ##########"  << endl << endl;

	InputGate *a = new InputGate("a");
	InputGate *b = new InputGate("b");

	int c_ = 1;

	for(InputGate *i : InputGate::InputVector)
	{cout << "Input n° " << c_ << " : " << i->getexpr() << " = " << i->eval() << " --- "; c_++;}

	cout << endl << endl;

	string answer = "y";
	while (answer == "y")
	{
		Gate *or_ = new OrGate(a,b);
		Gate *and1 = new AndGate(a,b) ;
		Gate *and2 = new XorGate(or_,and1) ;
		OutputGate *A = new OutputGate(and2);

		A->afficher_circuit(); // affichage du circuit
		cout << *A; // surcharge : affichage de expr, expr_wvalues, result
		A->saveInFile(); // sauvegarde

		cout << "Garder le même circuit en changeant les valeurs ? ('y' ou 'n') : ";

		cin >> answer;

		bool correct = (answer == "y")||(answer == "n");
		while (correct == 0)
		{cout << "Entrez 'y' ou 'n' svp : ";
		cin >> answer;
		correct = (answer == "y")||(answer == "n");}

		if (answer == "y")
		{
			cout << endl;
			int n;
			cout << "Voulez-vous changer a (1), b (2), ou les 2 (3) ? : ";

			cin >> n;

			correct = (n==1)||(n==2)||(n==3);
			while (correct == 0)
			{cout << "Entrez 1,2 ou 3 svp : ";
			cin >> n;
			correct = (n==1)||(n==2)||(n==3);}

			switch(n)
			{
				case(1) : cout << "a sera changé"  << endl; a->change();break;
				case(2) : cout << "b sera changé" << endl; b->change();break;
				case(3) : cout << "a et b seront changés" << endl; a->change(); b->change();break;
			}

			cout << endl << "####################" << endl << endl;
		}
	}
	cout << endl << "Arrêt réalisé avec succès" << endl << "----------" << endl;

	// ########## 2. Test avec un circuit décalé [du type (InputGate, Operateur(X,Y))]
	cout << "########## 2. Test avec un circuit décalé [du type (InputGate, Operateur(X,Y))] ##########" << endl << endl;

	InputGate *c = new InputGate("c");
	InputGate *d = new InputGate("d");
	Gate *nor_ = new NOrGate(a,b);
	Gate *or_ = new OrGate(nor_,c);
	Gate *nand_ = new NAndGate(or_,d);
	OutputGate *B = new OutputGate(nand_);
	
	B->afficher_circuit();
	cout << *B;
	B->saveInFile();

	//########## 3. Recupération des éléments du vecteur de vecteur de Gate* stocké dans l'OutputGate B
	cout << " ########## 3. Recupération des éléments du vecteur de vecteur de Gate* stocké dans l'OutputGate B ##########"<< endl << endl; 

	cout << "Affichage des éléments du vector<vector<Gate*>> g_stock de B : " << endl;
	
	for (vector<Gate*> vv : B->getGSTOCK())
	{
		for (Gate* v : vv)
		{cout << v->getexpr() << "   ";}
		cout << endl;
	}

	cout << "----------" << endl;

	// ########## 4. oneInput suivi de twoInput
    cout << "########## 4. oneInput suivi de twoInput ##########" << endl << endl;

	c->change();
	d->change();
	Gate *not_ = new NegateGate(c);
	Gate *or_2 = new OrGate(not_,d);
	Gate *not__ = new NegateGate(or_2);
	OutputGate *C = new OutputGate(not__);

	C->afficher_circuit();
	cout << *C;
	C->saveInFile();

	// ########## 5. Exemple de problème 2-SAT avec 4 variables u1,u2 avec la formule CNF suivante : f = (u1 ∧ ¬u3) ∨ (¬u2 ∧ u4) ; val(u1) = 1, val(u2) = 1, val(u3) = 0, val(u4) = 0
	cout << " ########## 5. Exemple de problème 2-SAT avec 4 variables u1,u2,u3,u4 avec la formule CNF suivante : " << endl << "f = (u1 ∧ ¬u2) ∨ (¬u3 ∧ u4) ; val(u1) = 1, val(u2) = 1, val(u3) = 0, val(u4) = 0 ##########" << endl << endl;
 
	InputGate *u1,*u2,*u3,*u4;
	u1 = new InputGate("u1"); u1->change();
	u2 = new InputGate("u2");
	u3 = new InputGate("u3"); u3->change();
	u4 = new InputGate("u4");

    //Clause 1
	Gate* and_clause1 = new AndGate(u1,u3);

	//Clause 2
	Gate *and_clause2 = new AndGate(u2,u4);

	//OR(clause1,clause 2) + OutputGate
	Gate *or_clause = new OrGate(and_clause1,and_clause2);
	OutputGate *SAT_2 = new OutputGate(or_clause);

	SAT_2->afficher_circuit();
	cout << *SAT_2;
	SAT_2->saveInFile();

	return 0;
}
