#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> v;
    void solve(int index, vector<vector<int>> &res, vector<int> &nums)
    {
        if (index == nums.size())
        {
            res.push_back(v);
            return;
        }
        v.push_back(nums[index]);
        solve(index + 1, res, nums);
        v.pop_back();
        solve(index + 1, res, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        solve(0, res, nums);
        set<vector<int>> s(res.begin(), res.end());
        res.assign(s.begin(), s.end());
        return res;
    }
};