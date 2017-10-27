#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;
int ladderLengthCore(string beginWord, string endWord, unordered_set<string>& wordList) {
	queue<string> que;
	que.push(beginWord);
	int res = 1;
	while (!que.empty())
	{
		int qsize = que.size();
		while (qsize--)
		{
			string cur_front = que.front();
			que.pop();
			int size = cur_front.size();
			for (int i = 0; i < size; i++)
			{
				char ch = cur_front[i];
				for (int j = 0; j < 26; j++)
				{
					cur_front[i] = 'a' + j;
					if (wordList.find(cur_front) != wordList.end())
					{
						if (cur_front == endWord) return res + 1;
						que.push(cur_front);
						wordList.erase(cur_front);
					}
				}
				cur_front[i] = ch;
			}
		}
		res++;
	}
	return 0;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> set(wordList.begin(), wordList.end());
	return ladderLengthCore(beginWord, endWord, set);
}