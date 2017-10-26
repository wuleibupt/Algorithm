class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    vector<int> diff(len, 0);
    for (int i = 0; i < len; i++)
		{
			diff[i] = gas[i] - cost[i];
		}
		int total = 0;
		int sum = 0;
		int start = 0;
		for (int i = 0; i < len; i++)
		{
			total += diff[i];
			sum += diff[i];
			if (sum < 0)
			{
				sum = 0;
				start = i + 1;
			}
		}
		if (total < 0) return -1;
		return start;
    }
};
