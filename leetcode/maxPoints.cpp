#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
	int maxPoints(vector<Point> &points) {
		int size = points.size();
		if (size == 0) return 0;
		else if (size == 1) return 1;
		int ret = 0;
		for (int i = 0; i < size; i++)
		{
			int currmax = 1;
			map<double, int> map;
			int vcnt = 0;
			int dup = 0;
			for (int j = 0; j < size; j++)
			{
				if (j != i)
				{
					double x1 = points[i].x - points[j].x;
					double y1 = points[i].y - points[j].y;
					if (x1 == 0 && y1 == 0)
						dup++;
					else if (x1 == 0)
					{
						if (vcnt == 0)
							vcnt = 2;
						else
							vcnt++;
						currmax = max(vcnt, currmax);
					}
					else
					{
						double k = y1 / x1;
						if (map[k] == 0)
							map[k] = 2;
						else
							map[k]++;
						currmax = max(map[k], currmax);
					}
				}
			}
			ret = max(ret, currmax + dup);
		}
		return ret;

	}
};

