
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // brute force
        int n = s.length();
        if (s.size() == 0)
        {
            return 0;
        }
        int max_len = 0;
        // for(int i=0;i<n;i++){
        //     unordered_set<char>st;
        //     for(int j=i;j<n;j++){
        //         if(st.find(s[j])!=st.end()){
        //             max_len=max(max_len,j-i);
        //             break;
        //         }
        //         st.insert(s[j]);
        //     }
        //     max_len=max(max_len,static_cast<int>(st.size()));
        // }
        // Time complexity: O(n^2)
        // Space complexity: O(n)
        // Optimized approach 1
        // two pointer approach
        // we will use two pointers start and end
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> st;
            for (int j = i; j < n; j++)
            {
                if (st.find(s[j]) != st.end())
                {
                    break;
                }
                max_len = max(max_len, j - i + 1);
                st.insert(s[j]);
            }
        }
        return max_len;
    }
};
