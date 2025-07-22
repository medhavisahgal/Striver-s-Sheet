#include <algorithm>
#include <vector>

class Solution
{
public:
    int minimumAddedCoins(std::vector<int> &coins, int target)
    {
        sort(coins.begin(), coins.end());
        long long range = 0;
        long long i = 0;
        long long ans = 0;
        while (range < target)
        {
            if (i < coins.size() && coins[i] <= range + 1)
            {
                range += coins[i];
                i++;
            }
            else
            {
                ans++;
                range += range + 1;
            }
        }
        return ans;
    }
};