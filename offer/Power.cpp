#include<iostream>
#include<vector>
using namespace std;
double Power(double base, int exponent) {
	if (exponent == 0)
		return 1;
	int ex = exponent;
	if (exponent < 0)
		ex = -exponent;
	double result = Power(base, ex >> 1);
	result *= result;
	if (ex & 1) result *= base;
	if (exponent < 0) result = 1.0 / result;
	return result;
}