// Lab 303
// Name :Jaeyoung Heo
// Student ID : 20123429

#include "lab003.h"

// constructor
Polynomial::Polynomial(int cap) : capacity(cap)
{
	termArray = new Term[capacity];
	terms = 0;
}


void Polynomial::NewTerm(const float theCoeff, const int theExp)
{	// Add a new term to the end of termArray
	if(terms==capacity)
	{
		capacity*=2;
		Term *temp = new Term[capacity];
		copy(termArray,termArray+terms,temp);
		delete[] termArray;
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}

// init the polynomial
void Polynomial::InitPolynomial(const char *msg)
{
	cerr << endl << "Init Polynomial " << msg << endl;
	float coef; int exp;
	while(1)
	{
		cerr << "Enter a term(coef,exp)"<< endl;
		cin>> coef >> exp;
		if(exp == -1)
			return;
		NewTerm(coef,exp);
	}
}




// evaluate the polynomial at x=f
float Polynomial::Eval(float f)
{
	float e = 0.0;

	for(int i=0;i<terms;i++)
	{
		float co = termArray[i].coef;
		int ex = termArray[i].exp;

		float copyf=1;
		for(int j=0;j<ex;j++)
		{
			copyf*=f;
		}
		e+=copyf*co;
	}

	return e;
}

// check whether the two polynomials are the same
bool Polynomial::operator== (Polynomial &p)
{
	if(this == &p)
		return true;

	for(int i=0;i<terms;i++)
	{
		float co = termArray[i].coef;
		int ex = termArray[i].exp;

		float co1 = p.termArray[i].coef;
		int ex1 = p.termArray[i].exp;
		
		if(!(co==co1&&ex==ex1))
			return false;
	}
	return true;
}


Polynomial Polynomial::Add(Polynomial &b)
{// Return the sum, c,  of the polynomials *this and b

	Polynomial c;
	int aPos = 0,bPos = 0;
	while((aPos<terms)&&(bPos<b.terms))
	{
		if((termArray[aPos].exp==b.termArray[bPos].exp))
		{
			float t = termArray[aPos].coef+b.termArray[bPos].coef;
			if(t)
				c.NewTerm(t,termArray[aPos].exp);
			aPos++;bPos++;
		}
		else if((termArray[aPos].exp<b.termArray[bPos].exp))
		{
			c.NewTerm(b.termArray[bPos].coef,b.termArray[bPos].exp);
			bPos++;
		}
		else
		{
			c.NewTerm(termArray[aPos].coef,termArray[aPos].exp);
			aPos++;
		}
	}
	for(;aPos<terms;aPos++)
		c.NewTerm(termArray[aPos].coef,termArray[aPos].exp);
	for(;bPos<b.terms;bPos++)
		c.NewTerm(b.termArray[bPos].coef,b.termArray[bPos].exp);
	return c;
}		



