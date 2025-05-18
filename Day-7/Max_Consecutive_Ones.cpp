#include <vector>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max_ones = 0;
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
            }
            else
            {
                max_ones = max(max_ones, cnt);
                cnt = 0;
            }
        }
        max_ones = max(max_ones, cnt);
        return max_ones;
    }
};