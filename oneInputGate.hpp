#include "Gate.hpp"

#ifndef ONEINPUTGATE_HPP
#define ONEINPUTGATE_HPP

class oneInputGate : public Gate {
	protected:

		Gate *g;
	
	public:

		oneInputGate();
    	virtual ~oneInputGate();

		Gate* getGate();

		int getProf() const override; // pareil que pour Inputgate
		vector<vector<Gate*>> empiler() override;
};

#endif