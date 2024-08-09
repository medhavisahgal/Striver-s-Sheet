class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // Brute force
        //  map<int,int>m;
        vector<int> ans;
        int n = nums.size();
        // for(int i=0;i<n;i++){
        //     m[nums[i]]++;
        // }
        // for(auto x:m){
        //     if(x.second>n/3){
        //         ans.push_back(x.first);
        //     }
        // }
        // return ans;
        // Extended Boyer Moore’s Voting Algorithm
        int cnt1 = 0, can1 = INT_MIN;
        int cnt2 = 0, can2 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && nums[i] != can2)
            {
                can1 = nums[i];
                cnt1++;
            }
            else if (cnt2 == 0 && nums[i] != can1)
            {
                can2 = nums[i];
                cnt2++;
            }
            else if (nums[i] == can1)
            {
                cnt1++;
            }
            else if (nums[i] == can2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == can1)
            {
                cnt1++;
            }
            if (nums[i] == can2)
            {
                cnt2++;
            }
        }
        if (cnt1 > (n / 3))
            ans.push_back(can1);
        if (cnt2 > (n / 3))
            ans.push_back(can2);
        return ans;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)