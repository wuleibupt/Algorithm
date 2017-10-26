#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
int NumberOf1Between1AndN_Solution(int n)
{
	int count = 0;
	long long i = 1;
	for (; i <= n; i *= 10)
	{
		int a = n / i, b = n%i;
		count = count + (a + 8) / 10 * i + (a % 10 == 1)*(b + 1);
	}
	return count;
}




