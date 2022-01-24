#include "Gate.hpp"
#include "oneInputGate.hpp"
#include "InputGate.hpp"

#include <fstream>

#ifndef OUTPUTGATE_HPP
#define OUTPUTGATE_HPP

class OutputGate : public oneInputGate {
	private :

		Gate *g;
		vector<vector<Gate*>> g_stock;
		static int compt;
		static char output_name;
	
	public :
	
		OutputGate(Gate*);
		virtual ~OutputGate();

		vector<vector<Gate*>> getGSTOCK();

		void saveInFile() const;

		void afficher_circuit() const;
};

#endif