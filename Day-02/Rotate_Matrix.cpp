class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n=a.size();
        int m=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                int temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
        }
        for(int i=0;i<n;i++){
            reverse(a[i].begin(),a[i].end());
        }
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(1)