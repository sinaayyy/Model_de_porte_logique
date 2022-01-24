#include "InputGate.hpp"

vector<InputGate*> InputGate::InputVector = {};

void InputGate::change()
{
	if (val == true)
	{
		val = false;
		expr_wvalues = to_string(0);
	}
	else
	{
		val = true;
		expr_wvalues = to_string(1);
	}
	
	calcul = expr + ":" + expr_wvalues;
}

InputGate::InputGate(string n) : Gate()
{
	val = 0;
	expr = n;
	expr_wvalues = to_string(val);
	calcul = expr + ":" + expr_wvalues ;
	type = "Input";
	InputVector.push_back(this);
}

int InputGate::getProf() const {return profondeur;}

vector<vector<Gate*>> InputGate::empiler()
{
    //empiler renvoie un vector de vector de Gate*
	//ici, on va simplement renvoyer {{InputGate*}}
	vector<vector<Gate*>> vect_de_vect = {{}};
    vector<Gate*> vect = {};
    vect.push_back(this);
    vect_de_vect.push_back(vect);
    return vect_de_vect;
}

InputGate::~InputGate(){delete this;}