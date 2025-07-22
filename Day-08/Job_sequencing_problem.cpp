#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int find(int x, vector<int> &parent)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x], parent); // Path compression
    }
    void unionSets(int u, int v, vector<int> &parent)
    {
        parent[u] = v;
    }
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
        vector<int> parent(max_deadline + 1); // day 0 is unused
        // int pro = 0, jobs = 0;
        // for (auto x : v)
        // {
        //     int p = x.first;
        //     int dead = x.second;
        //     for (int d = dead; d > 0; d--)
        //     {
        //         if (ava_day[d] == -1)
        //         {
        //             ava_day[d] = 0;
        //             pro += p;
        //             jobs++;
        //             break;
        //         }
        //     }
        // }
        // return {jobs, pro};
        // Time Complexity: O(n log n) for sorting + O(n * m) for job scheduling
        // Space Complexity: O(m) for storing available days
        //  TLE if m is large, but works for reasonable constraints
        // Greedy + DSU approach can be used for better efficiency
        // Time Complexity: O(n log n) for sorting + O(n) for union-find operations
        // Space Complexity: O(n) for union-find structure
        for (int i = 1; i <= max_deadline; i++)
        {
            parent[i] = i; // Initialize each day as its own parent
        }
        int jobs_cnt = 0, psum = 0;
        for (auto job : v)
        {
            int p = job.first;
            int d = job.second;
            int ava_day = find(d, parent);
            if (ava_day > 0)
            {
                jobs_cnt++;
                psum += p;
                unionSets(ava_day, ava_day - 1, parent);
            }
        }
        return {jobs_cnt, psum}; // Return the count of jobs and total profit
    }
};