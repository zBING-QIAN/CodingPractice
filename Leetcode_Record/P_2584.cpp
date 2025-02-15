#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> prime;
    bool collect_prime(int v, unordered_set<int> &buff, unordered_set<int> &left_primes)
    {
        int overlap = false;
        while (v > 1)
        {
            int d = prime[v];
            buff.insert(d);
            // cout<<ov<<" "<<d<<endl;
            if (left_primes.count(d))
                overlap = 1;
            while (v % d == 0)
            {
                v /= d;
            }
        }
        return overlap;
    }
    int findValidSplit(vector<int> &nums)
    {
        int n = nums.size(), x = 0;
        for (int i = 0; i < n; i++)
        {
            x = max(x, nums[i]);
        }
        prime.assign(x + 1, 0);
        for (int i = 0; i <= x; i++)
            prime[i] = i;
        for (int i = 2; i <= x; i++)
        {
            if (prime[i] == i && i <= x / i)
            {
                for (int j = i * i; j <= x; j += i)
                {
                    prime[j] = i;
                }
            }
        }
        int ans = 0;
        unordered_set<int> buff, left_primes;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                continue;
            bool fail = collect_prime(nums[i], buff, left_primes);
            if (fail || i == 0)
            {
                ans = i;
                left_primes.insert(buff.begin(), buff.end());
                buff.clear();
            }
        }
        if (ans >= n - 1)
            return -1;
        else
            return ans;
    }
};