#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int pow(long long c, int n)
    {
        long long r = 1;
        while (n)
        {
            if (n & 1)
            {
                r *= c;
                r %= mod;
            }
            c *= c;
            c %= mod;
            n >>= 1;
        }
        return r;
    }
    int inv(int c)
    {
        return pow(c, mod - 2);
    }

    int subsequencesWithMiddleMode(vector<int> &nums)
    {
        int n = nums.size();
        int inv2 = inv(2), inv3 = inv(3), inv4 = inv(4);
        vector<long long> dp;
        long long res = 0;
        unordered_map<int, int> fcnt, bcnt;
        fcnt[nums[0]]++;
        fcnt[nums[1]]++;
        for (int j = 3; j < n; j++)
        {
            bcnt[nums[j]]++;
        }
        for (long long i = 2; i < n - 2; i++)
        {
            long long cnt = i * (i - 1) * (n - i - 2) * (n - i - 1);
            long long fnoti = i - fcnt[nums[i]], bnoti = n - i - 1 - bcnt[nums[i]];
            long long noti = fnoti * (fnoti - 1) * (bnoti - 1) * bnoti;
            cnt -= noti;
            cnt = ((cnt % mod) * inv4) % mod;
            for (auto kv : fcnt)
            {
                if (kv.first != nums[i])
                {
                    if (bcnt[kv.first])
                    {
                        long long fails = ((bnoti - bcnt[kv.first]) * fcnt[nums[i]] * kv.second * bcnt[kv.first]) % mod;
                        cnt = (cnt - fails) % mod;
                    }
                    if (kv.second > 1)
                    {
                        long long fails = (bnoti * kv.second * (kv.second - 1) * bcnt[nums[i]]) % mod;
                        fails = (fails * inv2) % mod;
                        cnt = (cnt - fails) % mod;
                    }
                }
            }
            // cout<<i<<" "<<cnt<<endl;
            for (auto kv : bcnt)
            {
                if (kv.first != nums[i])
                {
                    if (fcnt[kv.first])
                    {
                        long long fails = ((fnoti - fcnt[kv.first]) * bcnt[nums[i]] * kv.second * fcnt[kv.first]) % mod;
                        cnt = (cnt - fails) % mod;
                    }
                    if (kv.second > 1)
                    {
                        long long fails = (fnoti * kv.second * (kv.second - 1) * fcnt[nums[i]]) % mod;
                        fails = (fails * inv2) % mod;
                        cnt = (cnt - fails) % mod;
                    }
                }
            }
            // cout<<i<<" "<<cnt<<endl;
            res = (res + cnt) % mod;

            fcnt[nums[i]]++;
            bcnt[nums[i + 1]]--;
            if (bcnt[nums[i + 1]] == 0)
                bcnt.erase(nums[i + 1]);
        }
        if (res < 0)
            res += mod;
        return res;
    }
};