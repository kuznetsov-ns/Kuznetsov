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
