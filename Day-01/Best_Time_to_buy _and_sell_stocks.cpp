class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int buy = prices[0];
        for (auto x : prices)
        {
            if (x < buy)
            {
                buy = x;
            }
            else if (x - buy > profit)
            {
                profit = x - buy;
            }
        }
        return profit;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)