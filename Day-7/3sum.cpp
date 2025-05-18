#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // int n = nums.size();
        // vector<vector<int>> v;
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < n; i++)
        // {
        //     if (i > 0 && nums[i] == nums[i - 1])
        //         continue;
        //     int a = nums[i];
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (j > i + 1 && nums[j] == nums[j - 1])
        //             continue;
        //         int b = nums[j];
        //         int findnum = -(a + b);
        //         int left = j + 1;
        //         int right = n - 1;
        //         while (left <= right)
        //         {
        //             int mid = left + (right - left) / 2;
        //             if (nums[mid] == findnum)
        //             {
        //                 vector<int> v1 = {a, b, nums[mid]};
        //                 v.push_back(v1);
        //                 break;
        //             }
        //             else if (nums[mid] > findnum)
        //             {
        //                 right = mid - 1;
        //             }
        //             else
        //             {
        //                 left = mid + 1;
        //             }
        //         }
        //     }
        // }
        // set<vector<int>> s(v.begin(), v.end());
        // vector<vector<int>> v2(s.begin(), s.end());
        // return v2;
        // Time complexity: O(n^2log(n))
        // Space complexity: O(n^2)
        // Using two pointers
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    v.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return v;
    }
};
