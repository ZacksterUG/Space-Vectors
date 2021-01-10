#include <iostream>
#include "spacevector.h"
using namespace std;


int main()
{
	ZackVector::Vector a(0,0,10);
	ZackVector::Vector b(0,10,0);
	ZackVector::Vector c = crossProd(b, a);
	ZackVector::Vector R = (a + b)*4;
	float x, y, z;
	ZackVector::Vector G = c*(a * b * 3);
	R.getPos(x, y, z);
	cout << "X " << x << " Y " << y << " Z " << z << endl;
	float angle = ZackVector::Vector::vecAngle(a, b, ZackVector::Degree);
	cout << angle << endl;
	G.getPos(x,y,z);
	cout << "X " << x << " Y " << y << " Z " << z << endl;
	return 0;
}
