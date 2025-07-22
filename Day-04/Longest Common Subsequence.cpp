
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n=nums.size();
        if(n==0)return 0;
        // sort(nums.begin(),nums.end());
        // int cnt=1;
        // int maxlen=1;
        // for(int i=1; i<n; i++)
        // {
        //     if(nums[i]==nums[i-1])
        //     {
        //         continue;
        //     }
        //     else if(nums[i]-nums[i-1]==1)
        //     {
        //         cnt++;
        //     }
        //     else
        //     {
        //         maxlen=max(maxlen,cnt);
        //         cnt=1;
        //     }
        // }
        // maxlen=max(maxlen,cnt);
        // return maxlen;
        //Time complexity->O(nlogn)
        //Space complexity->O(1)
        unordered_set<int> s;
        for(int i=0;i<n;i++)s.insert(nums[i]);
        int maxlen=1;
        for(auto x:s){
            if(s.find(x-1)==s.end()){
                int cnt=1;
                int stnum=x;
                while(s.find(x+1)!=s.end()){
                    cnt++;
                    x++;
                }
                maxlen=max(maxlen,cnt);
            }
        }
        return maxlen;
        //Time complexity->O(n)
        //Space complexity->O(n)
    }
};
