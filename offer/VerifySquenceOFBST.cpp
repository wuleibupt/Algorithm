#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int g_maxValue = 6;
bool VerifySquenceOFBST(vector<int> sequence)
{
	int size = sequence.size();
	if (size == 0) return false;
	int i = 0;
	while (--size)
	{
		while (i<size && sequence[i++] < sequence[size]);
		while (i<size && sequence[i++] > sequence[size]);
		if (i != size)
			return false;
		i = 0;
	}
	return true;
}