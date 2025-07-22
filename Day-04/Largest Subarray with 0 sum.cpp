#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxLen(vector<int>& arr)
    {
        int n = arr.size();
        // vector<int>prefix_sum(n);
        // prefix_sum[0]=arr[0];
        // for(int i=1; i<n; i++)
        // {
        //     prefix_sum[i]=prefix_sum[i-1]+arr[i];
        // }
        // int maxlen=0;
        // for(int i=0; i<n; i++)
        // {
        //     int that_num=prefix_sum[i];
        //     int index=i;
        //     for(int j=n-1; j>i; j--)
        //     {
        //         if(that_num==prefix_sum[j])
        //         {
        //             index=j;
        //             break;
        //         }
        //     }
        //     int leng=index-i;
        //     maxlen=max(maxlen,leng);

        // }
        // int indexz=-1;
        // for(int j=n-1; j>=0; j--)
        // {
        //     if(prefix_sum[j]==0)
        //     {
        //         indexz=j;
        //         break;
        //     }
        // }
        // maxlen=max(maxlen,indexz+1);
        // return maxlen;
        //Time complexity: O(n^2)
        //Space complexity: O(n)
        //how to optimize this code?
        //we can use hashmap to store the prefix sum and its index
        //if we find the same prefix sum again then we can calculate the length of the subarray
        //and update the maxlen
        //if we find the prefix sum as 0 then we can update the maxlen with the current index
        //code for the same is below
        unordered_map<int,int>mp;
        int sum=0;
        int maxlen=0;
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
            if(sum==0)
            {
                maxlen=i+1;
            }
            if(mp.find(sum)!=mp.end())
            {
                maxlen=max(maxlen,i-mp[sum]);
            }
            else
            {
                mp[sum]=i;
            }
        }
        return maxlen;
        //Time complexity: O(n)
        //Space complexity: O(n)

    }
};
