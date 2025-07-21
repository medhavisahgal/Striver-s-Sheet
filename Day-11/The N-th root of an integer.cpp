class Solution
{
public:
    int nthRoot(int n, int m)
    {
        int left = 0;
        int right = m;
        while (left <= right)
        {
            int mid = right - (right - left) / 2;
            int prod = 1;
            for (int i = 0; i < n; i++)
            {
                prod *= mid;
            }
            if (prod == m)
            {
                return mid;
            }
            else if (prod > m)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};