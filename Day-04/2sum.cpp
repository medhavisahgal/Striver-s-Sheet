#include <vector>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int sum=nums[i]+nums[j];
                if(sum==target){
                    s.push_back(i);
                    s.push_back(j);
                    break;
                }
            }
        }
       return s;
    }
};