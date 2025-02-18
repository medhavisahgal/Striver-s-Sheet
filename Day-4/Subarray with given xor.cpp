#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int> &a, int k);
};

int Solution::solve(vector<int> &a, int k) {
    int n=a.size();
    //brute force
    int cnt=0;
    // for(int i=0;i<n;i++){
    //     int temp=0;
    //     for(int j=i+1;j<n;j++){
    //         temp^=a[j];
    //         if(temp==k){
    //             cnt++;
    //         }
    //     }
    // }
    //Time complexity: O(n^2)
    //Space complexity: O(1)
    //Optimized approach
    //We will use prefix xor array
    //xor of 1st part of lets say is x and remaining part is k till index i 
    //and we know the prefix of the lements till i is xr
    //then x^k=xr
    //x^k^k=xr^k
    //x=xr^k
    //so we will find the occurence of xr^k in the prefix xor array using map 
    //and add the count to the answer
    //steps to solve
    unordered_map<int,int>freq;
    int xr=0;
    int cnt=0;
    freq[0]=1;
    for(int i=0;i<n;i++){
        xr^=a[i];
        int x=xr^k;
        cnt+=freq[x];
        freq[xr]++;
    }
    return cnt;
   
}

