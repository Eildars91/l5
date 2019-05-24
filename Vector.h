#pragma once
#include <iostream>
#include <string>
#ifndef VECTOR_H
#define VECTOR_H
using namespace std;
class vector
{
private:
	int vx,vy,v1x, v1y, v2x, v2y, mod, opera;
public:
	vector()
	{
		vx = 0;
		vy = 0;
		v1x = 0;
		v1y = 0;
		v2x = 0;
		v2y = 0;
		mod = 0;
		opera = 0;
	}

	vector(int v1x, int v1y, int v2x, int v2y, int opera, int vx, int vy, int mod)
	{
		this->v1x = v1x;
		this->v1y = v1y;
		this->v2x = v2x;
		this->v2y = v2y;
		this->mod = mod;
		this->opera = opera;
		this->vx = vx;
		this->vy = vy;
	}

	vector(const vector& object) :
		v1x(object.v1x), v1y(object.v1y), v2x(object.v2x), v2y(object.v2y), mod(object.mod), opera(object.opera), vx(object.vx), vy(object.vy)
	{
		cout << "Êîíñòðóêòîð êîïèðîâàíèÿ." << endl;
	}

	~vector()
	{
	}


	void modulevector()
	{
		mod = sqrt(pow(vx, 2) + pow(vy, 2));
	}

	void choice()
	{
		switch (opera)
		{
		case 1:
			vx = v1x + v2x;
			vy = v1y + v2y;
			cout << "Ñóììà (" << vx << "," << vy << ")" << endl;
			break;
		case 2:
			vx = v1x - v2x;
			vy = v1y - v2y;
			cout << "Âû÷èòàíèå (" << vx << "," << vy << ")" << endl;
			break;
		}
	}
	vector& operator=(vector & vec) {
		this->vx = vec.vx;
		this->vy = vec.vy;
		return *this;
	}

	bool operator >(vector vec) {
		return this->vx > vec.vx&& this->vy > vec.vy;
	}
	bool operator <(vector vec) {
		return this->vx < vec.vx&& this->vy < vec.vy;
	}

	bool operator >=(vector vec) {
		return this->vx >= vec.vx && this->vy >= vec.vy;
	}

	bool operator <=(vector vec) {
		return this->vx <= vec.vx && this->vy <= vec.vy;
	}

	bool operator !=(vector vec) {
		return this->vx != vec.vx && this->vy != vec.vy;
	}

	bool operator ==(vector vec) {
		return this->vx == vec.vx && this->vy == vec.vy;
	}

	friend ostream& operator<<(ostream & out, vector & vec) {
		out << "Ìîäóëü:" << vec.mod << endl;
		out << "Ïåðâûé âåêòîð: " << vec.v1x << "," << vec.v1y << ";" << endl;
		out << "Âòîðîé âåêòîð: " << vec.v2x << "," << vec.v2y << ";" << endl;
		return out;
	}

	friend istream& operator>>(istream & in, vector & vec) {
		cout << "Ââåäèòå êîîðäèíàòû ïåðâîãî âåêòîðà:" << endl;
		cout << "x = ";
		in >> vec.v1x;
		cout << "y = ";
		in >> vec.v1y;
		cout << "Ââåäèòå êîîðäèíàòû âòîðîãî âåêòîðà:" << endl;
		cout << "x = ";
		in >> vec.v2x;
		cout << "y = ";
		in >> vec.v2y;
		cout << "Îïåðàöèÿ, êîòîðóþ âû õîòèòå ñäåëàòü:" << endl;
		cout << "1. Íàéòè ñóììó." << endl;
		cout << "2. Íàéòè âû÷èòàíèå." << endl;
		cout << "Îïåðàöèÿ: ";
		in >> vec.opera;
		return in;
	}
};

#endif
