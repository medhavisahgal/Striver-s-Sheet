class Solution {
public:
    // int countPath(int i,int j,int m, int n){
    //     if(i==m-1&&j==n-1)return 1;
    //     if(i>=m||j>=n)return 0;
    //    return countPath(i+1,j,m,n)+countPath(i,j+1,m,n);
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    //     int up=countPath(0,0,m,n);
    //     return up;
    // }
    //brute force approach
    //Time complexity: O(2^(m+n))
    //Space complexity: O(m+n)
    //optimized approach
    public:
    int countPath(int i,int j,int m, int n,vector<vector<int>>&dp){
        if(i==m-1&&j==n-1)return 1;
        if(i>=m||j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        else{
            return dp[i][j]=countPath(i+1,j,m,n,dp)+countPath(i,j+1,m,n,dp);
        }
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int up=countPath(0,0,m,n,dp);
        return up;
      }
    //Time complexity: O(m*n)
    //Space complexity: O(m*n)
};