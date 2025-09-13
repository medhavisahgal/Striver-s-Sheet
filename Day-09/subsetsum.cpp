#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int index, vector<int> &arr, int sum, vector<int> &res)
    {
        if (index == arr.size())
        {
            res.push_back(sum);
            return;
        }
        solve(index + 1, arr, sum + arr[index], res);
        solve(index + 1, arr, sum, res);
    }
    vector<int> subsetSums(vector<int> &arr)
    {
        vector<int> res;
        solve(0, arr, 0, res);
        sort(res.begin(), res.end());
        return res;
    }
};
