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
	Monom& operator+(Monom& a);
	Monom& operator+=(Monom& a);
	Monom& operator-(Monom& a);
	Monom& operator-=(Monom& a);
	Monom& operator*(Monom& a);
	Monom& operator*=(Monom& a);
	bool operator==(Monom& a);
	bool operator>(Monom& a);
	bool operator<(Monom& a);
};