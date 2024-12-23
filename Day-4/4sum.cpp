#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //brute force approach 
        long long sum=0;
        int m=0;
        int n=nums.size();
        vector<vector<int>>ans;
        set<vector<int>>s;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    for(int l=k+1;l<n;l++){
                        sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l];
                        if(sum==target){
                            //before inserting sort in ascending order
                            vector<int>a={nums[i],nums[j],nums[k],nums[l]};
                            sort(a.begin(),a.end());
                            s.insert(a);
                        }
                    }
                }
            }
        }
        for(const auto &x:s){
            ans.push_back(x);
        }
        //this approach is not efficient showing TLE
        return ans;
    }
};