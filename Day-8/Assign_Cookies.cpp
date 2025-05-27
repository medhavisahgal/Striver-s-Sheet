
#include <vector>
#include <algorithm>

class Solution
{
public:
    int findContentChildren(std::vector<int> &g, std::vector<int> &s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int ans = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                ans++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};