#include <bits/stdc++.h>
retun
class Solution
{
public:
    double myPow(double x, int n)
    {
        // BRUTE FORCE
        long long int p = abs(n);
        long double ans = 1;
        // for(long long int i=1;i<=p;i++){
        //     ans*=x;
        // }
        // if(n<0){
        //     return 1.0/ans;
        // }
        // return ans;
        // TLE-X=0.0001
        // n=2147483647
        // reason:Time complexity is O(n) which is pretty slow for large values of n.
        // Binary Exponentiation
        // while (p)
        // {
        //     if (p & 1)
        //     {
        //         ans *= x;
        //     }
        //     x *= x;
        //     p >>= 1;
        // }
        // if (n < 0)
        // {
        //     return 1.0 / ans;
        // }
        // return ans;
        // this is iterative approach
        if (p == 0)
            return 1;
        if (p == 1)
        {
            if (n < 0)
                return 1.0 / x;
            return x;
        }
        ans = myPow(x, p >> 1);
        ans *= ans;
        if (p & 1)
        {
            ans *= x;
        }
        if (n < 0)
        {
            return 1.0 / ans;
        }
        return ans;
    }
};
// Time complexity:O(log(n));
// Space complexity:O(1);