class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)