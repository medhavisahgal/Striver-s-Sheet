class Solution {
public:
    int majorityElement(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       int mid=n/2;
       return nums[mid];
    }
};
// Time Complexity: O(nlogn)
// Space Complexity: O(1)