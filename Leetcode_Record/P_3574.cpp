#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gcd(int a, int b)
    {
        if (a < b)
        {
            swap(a, b);
        }
        while (b)
        {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long maxGCDScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> pow2(n, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            long long tmp = nums[i];
            while (tmp && (tmp & 1) == 0)
            {
                pow2[i]++;
                tmp >>= 1;
            }
        }
        long long ans = max(n, 2 * k);
        for (int i = 0; i < n; i++)
        {
            long long cur = nums[i];
            int small2 = pow2[i], smallcnt = 0;
            for (int j = i; j < n; j++)
            {
                cur = gcd(cur, nums[j]);
                if (pow2[j] < small2)
                {
                    smallcnt = 1;
                    small2 = pow2[j];
                }
                else if (pow2[j] == small2)
                {
                    smallcnt++;
                }
                if (smallcnt <= k)
                    ans = max(ans, (cur << 1) * (j - i + 1));
                else
                    ans = max(ans, cur * (j - i + 1));
            }
        }
        return ans;
    }
};