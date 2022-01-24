#include "Gate.hpp"

bool Gate::eval() const {return val;}
string Gate::getcalcul() const {return calcul;}
string Gate::getexpr() const {return expr;}
string Gate::getexpr_wvalues() const {return expr_wvalues;}

Gate::Gate(){}
Gate::~Gate(){delete this;}

string Gate::getType(){return type;}

ostream &operator<<(ostream &out, const Gate &g)
{
    out << "Expression : " << g.getexpr() << endl;
	out << "Expression valuée : " << g.getexpr_wvalues() << endl;
	out << "Result : " << g.eval() << endl << endl;
    return out;
}