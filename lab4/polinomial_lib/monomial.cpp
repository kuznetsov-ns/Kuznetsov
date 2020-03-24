#include "monomial.h"

Monom::Monom()
{
	next = NULL;
	power = NULL;
	coeff = 0;
	n = 0;
}

Monom::Monom(int _n, int* _power, double _coeff)
{
	if (_n < 0) throw "Size is lower than 0";
	else
		if (_n == 0)
		{
			power = NULL;
			next = NULL;
			n = _n;
			coeff = _coeff;
		}
		else
		{
			n = _n;
			coeff = _coeff;
			next = NULL;
			power = new int[_n];
			for (int i = 0; i < _n; i++)
				if (_power[i] >= 0)
					power[i] = _power[i];
				else
					throw "Power is lower than 0";
		}
}

Monom::Monom(Monom& a)
{
	n = a.n;
	coeff = a.coeff;
	next = a.next;
	power = new int[n];
	for (int i = 0; i < n; i++)
		power[i] = a.power[i];
}

Monom::~Monom()
{
	if (power != 0)
		delete[] power;
	n = 0;
	coeff = 0;
	next = 0;
}

void Monom::setNext(Monom* _next)
{
	next = _next;
}

void Monom::setPower(int* _power)
{
	for (int i = 0; i < n; i++)
		if (_power[i] >= 0)
			power[i] = _power[i];
		else
			throw - 1;
}

void Monom::setCoeff(double _coeff)
{
	coeff = _coeff;
}

void Monom::setN(int _n)
{
	if (_n < 0)
		throw "Size is lower than 0";
	else
		if (_n == 0)
		{
			if (power != 0)
				delete[] power;
			n = 0;
			power = 0;
		}
		else
		{
			int* tmp = new int[n];
			for (int i = 0; i < n; i++)
				tmp[i] = power[i];
			delete[] power;
			int i = 0;
			power = new int[_n];
			if (n < _n)
			{
				for (; i < n; i++)
					power[i] = tmp[i];
				for (; i < _n; i++)
					power[i] = 0;
			}
			if (_n < n)
				for (; i < _n; i++)
					power[i] = tmp[i];
			n = _n;
		}
}

Monom* Monom::getNext()
{
	return next;
}

int* Monom::getPower()
{
	return power;
}

double Monom::getCoeff()
{
	return coeff;
}

int Monom::getN()
{
	return n;
}

Monom& Monom::operator=(Monom& a)
{
	if (n != a.n) throw - 1;
	coeff = a.coeff;
	n = a.n;
	next = a.next;
	delete[] power;
	power = new int[n];
	for (int i = 0; i < n; i++)
		power[i] = a.power[i];
	return *this;
}

Monom Monom::operator+(Monom& a)
{
	Monom tmp(a);
	if (n != a.n) throw - 1;
	if (!(*this == a)) throw - 1;
	tmp.coeff = coeff + a.coeff;
	return tmp;
}

Monom Monom::operator+=(Monom& a)
{
	if (n != a.n) throw - 1;
	if (!(*this == a)) throw - 1;
	coeff += a.coeff;
	return *this;
}

Monom Monom::operator-(Monom& a)
{
	Monom tmp(a);
	if (n != a.n) throw - 1;
	if (!(*this == a)) throw - 1;
	tmp.coeff = coeff - a.coeff;
	return tmp;
}

Monom Monom::operator-=(Monom& a)
{
	if (n != a.n) throw - 1;
	if (!(*this == a)) throw - 1;
	coeff -= a.coeff;
	return *this;
}

Monom Monom::operator*(Monom& a)
{
	if (n != a.n) throw - 1;
	Monom tmp(a);
	tmp.coeff = coeff * a.coeff;
	for (int i = 0; i < n; i++)
		tmp.power[i] = power[i] * a.power[i];
	return tmp;
}

Monom Monom::operator*=(Monom& a)
{
	if (n != a.n) throw - 1;
	coeff *= a.coeff;
	for (int i = 0; i < n; i++)
		power[i] += a.power[i];
	return *this;
}

bool Monom::operator==(Monom& a)
{
	if (n != a.n) throw - 1;
	for (int i = 0; i < n; i++)
		if (power[i] != a.power[i])
			return false;
	return true;
}

bool Monom::operator>(Monom& a)
{
	if (n != a.n) throw - 1;
	if (*this == a) throw "Equal";
	for (int i = 0; i < n; i++)
	{
		if (power[i] == a.power[i])
			continue;
		else
			if (power[i] > a.power[i])
				return true;
			else
				return false;
	}
	return true;
}

bool Monom::operator<(Monom& a)
{
	if (n != a.n) throw - 1;
	if (*this == a) throw "Equal";
	for (int i = 0; i < n; i++)
	{
		if (power[i] == a.power[i])
			continue;
		else
			if (power[i] < a.power[i])
				return true;
			else
				return false;
	}
	if (coeff > a.coeff)
		return false;
	return true;
}
