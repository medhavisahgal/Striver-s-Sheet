class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n=nums.size();
       for(int num:nums){
        int i=abs(num);
        if(nums[i]<0){
            return i;
        }
        nums[i]=-nums[i];
       }
       return n;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)