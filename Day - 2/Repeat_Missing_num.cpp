vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n=A.size();
    long long int sum_n=(n*(n+1))/2;
    long long int sum2_n=(n*(n+1)*(2*n+1))/6;
    long long int s=0;
    long long int s2=0;
    vector<int>ans;
    for(int i=0;i<n;i++){
        s+=(long long int)A[i];
        s2+=(long long int)A[i]*(long long int)A[i];
    }
    long long int fe=sum_n-s;
    long long int se=sum2_n-s2;
    long long int te=se/fe;
    long long int m=(fe+te)/2;
    long long int r=m-fe;
    ans.push_back((int)r);
    ans.push_back((int)m);
    return ans;
}
// Time Complexity: O(n)
// Space Complexity: O(1)