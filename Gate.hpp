#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef GATE_HPP
#define GATE_HPP

class InputGate;

class Gate {
	protected :

		bool val;
		string expr;
		string expr_wvalues;
		string type;
		
		int profondeur;
		string calcul; // AND, OR, XNOR...

	public :

		Gate();
		virtual ~Gate();
		
		bool eval() const;
		string getcalcul() const;
		string getexpr() const;
		string getexpr_wvalues() const;

		string getType();
		virtual int getProf() const = 0;

		virtual vector<vector<Gate*>> empiler() = 0;

		//Surcharge de <<
		friend ostream& operator<<(ostream &out, const Gate &);
};

#endif