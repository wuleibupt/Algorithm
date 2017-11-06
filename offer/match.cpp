#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool matchCore(char* str, int strIndex, char* pattern, int patternIndex)
{
	if (str[strIndex] == '\0' && pattern[patternIndex] == '\0')
		return true;
	if (str[strIndex] != '\0' && pattern[patternIndex] == '\0')
		return false;
	if (pattern[patternIndex] != '\0' && pattern[patternIndex + 1] == '*')
	{
		if ((str[strIndex] != '\0' && pattern[patternIndex] == str[strIndex]) || (pattern[patternIndex] == '.'&& str[strIndex] != '\0'))
		{
			return matchCore(str, strIndex, pattern, patternIndex + 2)
				|| matchCore(str, strIndex + 1, pattern, patternIndex + 2)
				|| matchCore(str, strIndex + 1, pattern, patternIndex);
		}
		else
		{
				return matchCore(str, strIndex, pattern, patternIndex + 2);
		}
	}
	if ((strIndex != strlen(str) && pattern[patternIndex] == str[strIndex]) || (strIndex != strlen(str) && pattern[patternIndex] == '.'))
		return matchCore(str, strIndex + 1, pattern, patternIndex + 1);
	return false;

}
bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL)
		return false;
	int strIndex = 0;
	int patternIndex = 0;
	return matchCore(str, strIndex, pattern, patternIndex);
}
