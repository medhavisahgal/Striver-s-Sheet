#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //brute force approach 
        // long long sum=0;
        // int m=0;
        int n=nums.size();
        vector<vector<int>>ans;
        // set<vector<int>>s;
        // for(int i=0;i<n-3;i++){
        //     for(int j=i+1;j<n-2;j++){
        //         for(int k=j+1;k<n-1;k++){
        //             for(int l=k+1;l<n;l++){
        //                 sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l];
        //                 if(sum==target){
        //                     //before inserting sort in ascending order
        //                     vector<int>a={nums[i],nums[j],nums[k],nums[l]};
        //                     sort(a.begin(),a.end());
        //                     s.insert(a);
        //                 }
        //             }
        //         }
        //     }
        // }
        // //this approach is not efficient showing TLE
        set<vector<int>>s;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;i<n;j++){
        //         //declare an hashset to store the specific array elements as we intend to search the fourth 
        //         //element in that hashset
        //         unordered_set<long long> hashset;//-> cannot be used as vector<int> is not hashable
        //         for(int k=j+1;k<n;k++){
        //             long long sum=(long long)nums[i]+(long long)nums[j];
        //             sum+=(long long)nums[k];
        //             long long f=target-sum;
        //             if(hashset.find(f)!= hashset.end()){
        //                 vector<int> a={nums[i],nums[j],nums[k],(int)f};
        //                 sort(a.begin(),a.end());
        //                 s.insert(a);
        //             }
        //             hashset.insert(nums[k]);
        //         }
        //     }
        // }
        //this approach is better but not efficient still
        //using two pointer approach
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }for(int j=i+1;j<n;j++){
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=(long long)nums[i];
                    sum+=(long long)nums[j];
                    sum+=(long long)nums[k];
                    sum+=(long long)nums[l];
                    if(sum==target){
                        vector<int>a={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(a);
                        k++;
                        l--;
                        while(k<l&&nums[k]==nums[k-1])k++;
                        while(k<l&&nums[l]==nums[l+1])l--;
                    }
                    if(sum<target){
                        k++;
                    }
                    if(sum>target){
                        l--;
                    }
                }
            }
        }
         return ans;
    }
};