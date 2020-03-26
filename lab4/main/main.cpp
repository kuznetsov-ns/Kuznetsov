#include <iostream>
#include "polinomial.h"
#include "monomial.h"

using namespace std;

int main()
{
	int arr1[] = { 1,2,3 };
	int arr2[] = { 4,5,6 };
	int arr3[] = { 7,8,9 };
	int arr4[] = { 10,11,12 };

	Monom m1(3, arr1, 1);
	Monom m2(3, arr2, 2);
	Monom m3(3, arr3, 5);
	Monom m4(3, arr4, 7);

	cout << "Monomial 1: " << m1 << endl;
	cout << "Monomial 2: " << m2 << endl;
	cout << "Monomial 3: " << m3 << endl;
	cout << "Monomial 4: " << m4 << endl;

	return 0;
}