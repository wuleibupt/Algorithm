int candy(vector<int>& ratings)
{
    if (ratings.empty()) return 0;
    int len = ratings.size();
    vector<int> count(len, 1);
    int sum = 0;
    for (int i = 0; i < len-1; i++)
    {
         if (ratings[i] < ratings[i + 1])
         {
             count[i + 1] = count[i] + 1;
         }
    }
    for (int i = len - 2; i >= 0; i--)
    {
         if (ratings[i] > ratings[i + 1] && count[i]<=count[i+1])
         {
             count[i] = count[i + 1] + 1;
         }
    }
    int res=accumulate(begin(count), end(count), 0);
    return res;
}
