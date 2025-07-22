class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)return {{1}};
        vector<vector<int>>pv=generate(numRows-1);
        vector<int>nv(numRows,1);
        for(int i=1;i<numRows-1;i++){
            nv[i]=pv.back()[i-1]+pv.back()[i];
        }
        pv.push_back(nv);
        return pv;
    }
};
//recursive approach
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            vector<int>nr(i+1,1);
            for(int j=1;j<i;j++){
                nr[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(nr); 
        }
        return ans;
    }
};
//iterative approach
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
vector<int>gr(int row){
    long long int ans=1;
    vector<int>ar;
    ar.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/col;
        ar.push_back(ans);
    }
    return ar;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>a;
        for(int i=1;i<=numRows;i++){
            a.push_back(gr(i));
        }
        return a;
    }
};
//ncr approach
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
