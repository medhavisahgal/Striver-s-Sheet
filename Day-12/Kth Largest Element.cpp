#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
        }
        int cnt = 0;
        int ele = 0;
        while (cnt < k)
        {
            ele = pq.top();
            pq.pop();
            cnt++;
        }
        return ele;
    }
};