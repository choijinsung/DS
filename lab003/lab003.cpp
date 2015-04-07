// Lab 303
// Name :
// Student ID :

#include "lab003.h"

// constructor
Polynomial::Polynomial(int cap) : capacity(cap)
{

}


void Polynomial::NewTerm(const float theCoeff, const int theExp)
{	// Add a new term to the end of termArray

}

// init the polynomial
void Polynomial::InitPolynomial(const char *msg)
{
	cerr << endl << "Init Polynomial " << msg << endl;

}




// evaluate the polynomial at x=f
float Polynomial::Eval(float f)
{
	float e = 0.0;





	return e;
}

// check whether the two polynomials are the same
bool Polynomial::operator== (Polynomial &p)
{
	if(this == &p)
		return true;






	return true;
}


Polynomial Polynomial::Add(Polynomial &b)
{// Return the sum, c,  of the polynomials *this and b
	Polynomial c;






	return c;
}		



