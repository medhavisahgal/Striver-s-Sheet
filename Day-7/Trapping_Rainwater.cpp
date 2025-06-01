#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        //     int n = height.size();
        //     vector<int> prefixmaxleft(n);
        //     vector<int> prefixmaxright(n);
        //     prefixmaxleft[0] = height[0];
        //     prefixmaxright[n - 1] = height[n - 1];
        //     int ans = 0;
        //     for (int i = 1; i < n; i++)
        //     {
        //         prefixmaxleft[i] = max(prefixmaxleft[i - 1], height[i]);
        //     }
        //     for (int i = n - 1; i > 0; i--)
        //     {
        //         prefixmaxright[i - 1] = max(prefixmaxright[i], height[i - 1]);
        //     }
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (prefixmaxleft[i] > height[i] && prefixmaxright[i] > height[i])
        //         {
        //             ans += min(prefixmaxleft[i], prefixmaxright[i]) - height[i];
        //         }
        //     }
        //     return ans;
        // }
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        // Optimized solution:
        int n = height.size();
        int left = 0, right = n - 1;
        int maxLeft = 0, maxRight = 0;
        int ans = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= maxLeft)
                {
                    maxLeft = height[left];
                }
                else
                {
                    ans += maxLeft - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= maxRight)
                {
                    maxRight = height[right];
                }
                else
                {
                    ans += maxRight - height[right];
                }
                right--;
            }
        }
        return ans;
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)
};