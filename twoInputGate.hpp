#include "Gate.hpp"
#include "oneInputGate.hpp"

#ifndef TWOINPUTGATE_HPP
#define TWOINPUTGATE_HPP

class twoInputGate : public Gate {
	protected:

		Gate *g1, *g2;
	
	public:

		twoInputGate();
    	virtual ~twoInputGate();

		vector<Gate*> getGates();

		int getProf() const override; // pareil que pour Inputgate
		vector<vector<Gate*>> empiler() override;
};

#endif