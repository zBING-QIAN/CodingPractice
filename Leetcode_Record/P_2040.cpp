#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        long long l = -2e10, r = 1e10;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> nums2_r = nums2;
        reverse(nums2_r.begin(), nums2_r.end());
        long long ans = -1e11, res = 0;
        while (l <= r)
        {
            long long cnt = 0;
            long long target = (l + r) / 2;
            ans = -1e10 - 1;
            for (int i = 0; i < n1; i++)
            {
                if (nums1[i] < 0)
                {
                    int left = 0, right = n2;
                    while (left < right)
                    {
                        int mid = (left + right) >> 1;
                        if (1ll * nums1[i] * nums2_r[mid] <= target)
                        {
                            left = mid + 1;
                        }
                        else
                        {
                            right = mid;
                        }
                    }
                    if (left > 0)
                    {
                        ans = max(ans, 1ll * nums1[i] * nums2_r[left - 1]);
                        cnt += left;
                    }
                }
                else
                {
                    int left = 0, right = n2;
                    while (left < right)
                    {
                        int mid = (left + right) >> 1;
                        if (1ll * nums1[i] * nums2[mid] <= target)
                        {
                            left = mid + 1;
                        }
                        else
                        {
                            right = mid;
                        }
                    }
                    if (left > 0)
                    {
                        ans = max(ans, 1ll * nums1[i] * nums2[left - 1]);
                        cnt += left;
                    }
                }
                if (cnt > k)
                    break;
            }
            if (cnt > k)
            {
                r = target - 1;
                res = ans;
            }
            else if (cnt < k)
                l = target + 1;
            else
                return ans;
        }
        return res;
    }
};