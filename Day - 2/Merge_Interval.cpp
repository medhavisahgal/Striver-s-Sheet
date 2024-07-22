class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int lb=intervals[0][0];
        int ub=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=ub){
                ub=max(ub,intervals[i][1]);
            }
            else{
                ans.push_back({lb,ub});
                lb=intervals[i][0];
                ub=intervals[i][1];
            }
        }
        ans.push_back({lb,ub});
        return ans;
        }
        
};
// Time Complexity: O(nlogn)
// Space Complexity: O(n)