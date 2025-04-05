#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int fastpow(long long v, long long p, int mod)
    {
        long long out = 1;
        while (p)
        {
            if (p & 1)
                out = (out * v) % mod;
            p >>= 1;
            v = (v * v) % mod;
        }
        return out;
    }

    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size(), mod = 1e9 + 7;
        vector<int> prime(1e5 + 1, 0), pc(1e5 + 1, 0), nc(n, 0), left(n, 0), right(n, 0), order(n, 0);
        for (int i = 2; i <= 1e5; i++)
        {
            if (prime[i] == 0)
            {
                prime[i] = i;
                for (long long j = 1ll * i * i; j < 1e5; j += i)
                {
                    prime[j] = i;
                }
            }
        }
        for (int i = 2; i <= 1e5; i++)
        {
            pc[i] = pc[i / prime[i]] + (((i / prime[i]) % prime[i]) > 0);
            // cout<<i<<" "<<pc[i]<<" "<<prime[i]<<" "<<pc[i/prime[i]]<<endl;
        }
        for (int i = 0; i < n; i++)
        {
            order[i] = i;
            nc[i] = pc[nums[i]];
        }
        vector<int> stac;
        for (int i = 0; i < n; i++)
        {
            // if(stac.size()){
            //     cout<<i<<" "<<pc[i]<<" "<<stac.back()<<" "<<pc[stac.back()]<<endl;
            // }
            while (stac.size() && nc[i] > nc[stac.back()])
            {

                right[stac.back()] = i;
                stac.pop_back();
            }
            if (stac.size())
                left[i] = stac.back();
            else
                left[i] = -1;
            stac.push_back(i);
        }
        while (stac.size())
        {
            right[stac.back()] = n;
            stac.pop_back();
        }
        long long ans = 1;
        sort(order.begin(), order.end(), [&](int a, int b)
             { return nums[a] > nums[b]; });
        for (int i = 0; i < n && k > 0; i++)
        {
            int pos = order[i];
            int v = nums[pos];
            long long cnt = 1ll * (right[pos] - pos) * (pos - left[pos]);
            if (k < cnt)
                cnt = k;
            // cout<<pos<<" "<<nums[pos]<<" "<<left[pos]<<" "<<right[pos]<<" "<<cnt<<" "<<k<<endl;
            k -= cnt;
            ans *= fastpow(v, cnt, mod);
            ans %= mod;
        }
        return ans;
    }
};