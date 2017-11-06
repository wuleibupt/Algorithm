#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int g_maxValue = 6;
void PrintProbabilty(int number)
{
	if (number < 1) return;

	vector<vector<int>> pProbability(2, move(vector<int>(g_maxValue*number + 1, 0)));
	int flag = 1;
	for (int i = 1; i <= g_maxValue; ++i)
		pProbability[flag][i] = 1;
	for (int k = 2; k <= number; k++)
	{
		for (int i = 0; i < k; i++)
			pProbability[1 - flag][i] = 0;
		for (int i = k; i <= g_maxValue*k; i++)
		{
			pProbability[1 - flag][i] = 0;
			for (int j = 1; j < i && j <= g_maxValue; j++)
			{
				pProbability[1 - flag][i] += pProbability[flag][i - j];
			}
		}
		flag = 1 - flag;
	}
	double tatol = pow(g_maxValue, number);
	for (int i = 0; i <= g_maxValue*number; ++i)
	{
		cout << (double(pProbability[flag][i]) / tatol) << endl;
	}
}

