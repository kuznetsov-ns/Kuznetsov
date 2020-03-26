#pragma once
#include <iostream>

using namespace std;

class Monom
{
protected:
	Monom* next;
	int* power;
	int n;
	double coeff;
public:
	Monom();
	Monom(int _n, int* _power, double _coeff);
	Monom(Monom& a);
	virtual ~Monom();

	void setPower(int* _power);
	void setNext(Monom* _next);
	void setCoeff(double _coeff);
	void setN(int _n);
	int* getPower();
	Monom* getNext();
	double getCoeff();
	int getN();

	Monom& operator=(Monom& a);
	Monom operator+(Monom& a);
	Monom operator+=(Monom& a);
	Monom operator-(Monom& a);
	Monom operator-=(Monom& a);
	Monom operator*(Monom& a);
	Monom operator*=(Monom& a);
	bool operator==(Monom& a);
	bool operator>(Monom& a);
	bool operator<(Monom& a);

	friend istream& operator>>(istream& istr, Monom& a)
	{
		istr >> a.coeff;
		for (int i = 0; i < a.n; i++)
			istr >> a.power[i];
		return istr;
	}
	friend ostream& operator<<(ostream& ostr, Monom& a)
	{
		ostr << a.coeff;
		if (a.coeff != 0)
		{
			for (int i = 0; i < a.n; i++)
				if (a.power[i] != 0)
				{
					ostr << "(x[" << i << "]^" << a.power[i] << ")";
				}
		}
		return ostr;
	}
};