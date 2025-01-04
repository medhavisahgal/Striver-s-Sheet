#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>prefix_sum(n);
        prefix_sum[0]=arr[0];
        for(int i=1; i<n; i++)
        {
            prefix_sum[i]=prefix_sum[i-1]+arr[i];
        }
        int maxlen=0;
        for(int i=0; i<n; i++)
        {
            int that_num=prefix_sum[i];
            int index=i;
            for(int j=n-1; j>i; j--)
            {
                if(that_num==prefix_sum[j])
                {
                    index=j;
                    break;
                }
            }
            int leng=index-i;
            maxlen=max(maxlen,leng);

        }
        int indexz=-1;
        for(int j=n-1; j>=0; j--)
        {
            if(prefix_sum[j]==0)
            {
                indexz=j;
                break;
            }
        }
        maxlen=max(maxlen,indexz+1);
        return maxlen;
    }
};
