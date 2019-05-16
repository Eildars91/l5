#include <iostream>
#include "Complex.h"
#include "Vector.h"

int main()
{
	setlocale(LC_ALL, "rus");
	complex C;
	cin >> C;
	C.modulecomplex();
	C.argumentcomplex();
	cout << C;

	vector V;
	cin >> V;
	V.modulevector();
	V.choice();
	cout << V;
}