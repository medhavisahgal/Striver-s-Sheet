#include <vector>
class Solution {
public:
    int reversePairs(std::vector<int>& nums) {
        //brute force technique
        long long int n=nums.size();
        long long int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long int pro=2LL*nums[j];
                if(nums[i]>pro){
                    cnt++;
                }
            }
        }
        return cnt;
        //Time complexity: O(n^2)
        //Space complexity: O(1)
        //Optimized approach
        
    }
};