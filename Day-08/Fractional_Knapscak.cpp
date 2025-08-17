#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        vector<vector<double>> v;
        for (int i = 0; i < n; i++)
        {
            double ratio = (double)val[i] / wt[i];
            v.push_back({ratio, (double)wt[i], (double)val[i]});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b)
             { return a[0] > b[0]; });
        double ans = 0.0;
        int i = 0;
        while (capacity > 0 && i < n)
        {
            if (capacity < v[i][1])
            {
                ans += v[i][0] * capacity;
                capacity = 0;
            }
            else
            {
                ans += v[i][2];
                capacity -= (int)v[i][1];
            }
            i++;
        }
        return ans;
    }
};
