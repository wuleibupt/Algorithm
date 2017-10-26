#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;
		int rows = board.size();
		int cols = board[0].size();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && board[i][j] == 'O')
					solveCore(board, i, j);
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == '$') board[i][j] = 'O';
			}
		}
	}
	void solveCore(vector<vector<char>>& board, int i, int j)
	{
		int rows = board.size();
		int cols = board[0].size();
		if (board[i][j] = '0')
		{
			board[i][j] = '$';
			if (j>0 && board[i][j - 1] == 'O')
				solveCore(board, i, j - 1);
			if (j < cols - 1 && board[i][j + 1] == 'O')
				solveCore(board, i, j + 1);
			if (i>0 && board[i - 1][j] == 'O')
				solveCore(board, i - 1, j);
			if (i < rows - 1 && board[i + 1][j] == 'O')
				solveCore(board, i + 1, j);
		}
	}
};


