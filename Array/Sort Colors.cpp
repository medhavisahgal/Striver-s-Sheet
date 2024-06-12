//This problem is a variation of the popular Dutch National flag algorithm. 
//This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:
//arr[0….low-1] contains 0. [Extreme left part]
//arr[low….mid-1] contains 1.
//arr[high+1….n-1] contains 2. [Extreme right part], n = size of the arra
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }

    }
};
