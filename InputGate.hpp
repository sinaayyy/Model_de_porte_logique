#include "Gate.hpp"

#ifndef INPUTGATE_HPP
#define INPUTGATE_HPP

class InputGate : public Gate {
	private :

		int const profondeur = 0;
	
	public :

		static vector<InputGate*> InputVector; // stocke les InputGate
	
		InputGate(string);
		virtual ~InputGate();
		
		void change();

		int getProf() const override;
		vector<vector<Gate*>> empiler() override;
};

#endif