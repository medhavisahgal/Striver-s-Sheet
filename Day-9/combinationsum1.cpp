#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int index, vector<int> &candidates, int target, vector<int> &temp)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (target < 0 || index >= candidates.size())
        {
            return;
        }
        // not taking the element //not taking the element
        solve(index + 1, candidates, target, temp);
        // taking the element
        temp.push_back(candidates[index]);
        solve(index, candidates, target - candidates[index], temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        solve(0, candidates, target, temp);
        return ans;
    }
};