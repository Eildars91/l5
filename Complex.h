#pragma once
#include <iostream>
#include <string>
#ifndef COMPLEX_H
#define COMPLEX_H
using namespace std;
class complex
{
private:
	double rez, imz;
	double mod, arg;
public:
	complex()
	{
		rez = 0.0;
		imz = 0.0;
	}

	~complex()// ïîáèòîâîå ëîãè÷åñêîå îòðèöàíèå
	{
	}

	complex(double rez, double imz)
	{
		this->rez = rez;
		this->imz = imz;
	}

	complex(const complex& object) :
		rez(object.rez), imz(object.imz), mod(object.mod), arg(object.arg)
	{
		cout << "Êîíñòðóêòîð êîïèðîâàíèÿ." << endl;
	}

	void modulecomplex()
	{
		mod = sqrt(pow(imz, 2) + pow(rez, 2));
	}

	void argumentcomplex()
	{
		arg = imz / rez;
	}

	complex& operator=(complex & comp) {
		this->imz = comp.imz;
		this->rez = comp.rez;
		return *this;
	}

	bool operator >(complex comp) {
		return this->mod > comp.mod&& this->arg > comp.arg;
	}

	bool operator <(complex comp) {
		return this->mod < comp.mod&& this->arg < comp.arg;
	}

	bool operator >=(complex comp) {
		return this->mod >= comp.mod && this->arg >= comp.arg;
	}

	bool operator <=(complex comp) {
		return this->mod <= comp.mod && this->arg <= comp.arg;
	}

	bool operator !=(complex comp) {
		return this->mod != comp.mod && this->arg != comp.arg;
	}

	bool operator ==(complex comp) {
		return this->mod == comp.mod && this->arg == comp.arg;
	}

	friend const complex operator++(complex & v, int) {
		complex retcomp(v.imz, v.rez);
		v.imz++;
		v.rez++;
		return retcomp;
	}

	friend const complex operator--(complex & v, int) {
		complex retcomp(v.imz, v.rez);
		v.imz++;
		v.rez++;
		return retcomp;
	}

	friend const complex& operator --(complex & v) {
		v.imz--;
		v.rez--;
		return v;
	}

	friend const complex& operator++(complex & v) {
		v.imz++;
		v.rez++;
		return v;
	}

	friend ostream& operator<<(ostream & out, complex & comp) {
		out << "Ìîäóëü êîìïëåêñíîãî ÷èñëà:" << comp.mod << endl;
		out << "Àðãóìåíò êîìïëåêñíîãî ÷èñëà:" << comp.arg << endl;
		return out;
	}

	friend istream& operator>>(istream & in, complex & comp) {
		cout << "Ââåäèòå íîìåð äåéñòâèòåëüíîé ÷àñòè:";
		cin >> comp.rez;
		cout << "Ââåäèòå íîìåð ìíèìîé ÷àñòè:";
		cin >> comp.imz;
		return in;
	}
};
#endif
