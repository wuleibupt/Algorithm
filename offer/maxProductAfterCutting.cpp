#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxProductAfterCutting(int length)
{
	if (length < 2) return 0;
	if (length == 2) return 1;
	if (length == 3) return 2;
	vector<int> products(length + 1);
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;
	for (int i = 4; i <= length; i++)
	{
		int product = 0;
		for (int j = 1; j <= i >> 1; j++)
		{
			int num = products[j] * products[i - j];
			product = max(product, num);
		}
		products[i] = product;
	}
	return products[length];
}
int maxProductAfterCutting1(int length)
{
	if (length < 2) return 0;
	if (length == 2) return 1;
	if (length == 3) return 2;
	int numof3 = length / 3;
	if (length % 3 == 1) numof3 -= 1;
	int numof2 = (length - numof3 * 3) / 2;
	return int(pow(2, numof2)*pow(3, numof3));
}