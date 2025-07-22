#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        vector<pair<int, int>> v;
        int n = deadline.size();
        int max_deadline = *max_element(deadline.begin(), deadline.end());
        for (int i = 0; i < n; i++)
        {
            v.push_back({profit[i], deadline[i]});
        }
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.first > b.first; });
        vector<int> ava_day(max_deadline + 1, -1); // day 0 is unused
        int pro = 0, jobs = 0;
        for (auto x : v)
        {
            int p = x.first;
            int dead = x.second;
            for (int d = dead; d > 0; d--)
            {
                if (ava_day[d] == -1)
                {
                    ava_day[d] = 0;
                    pro += p;
                    jobs++;
                    break;
                }
            }
        }
        return {jobs, pro};
    }
};