#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums, int k, int limit)
    {
        set<array<int, 3>> dp; // k,len  product
        dp.insert({0, 0, 1});
        int n = nums.size(), ans = -1;
        for (int i = 0; i < n; i++)
        {

            set<array<int, 3>> dptmp = dp; // k,len  product
            // cout<<dp.size()<<endl;
            for (auto &d : dptmp)
            {
                auto [kk, len, prod] = d;
                long long product = 1ll * prod * nums[i];
                // cout<<kk<<" "<<len<<" "<<prod<<" "<<i<<" "<<nums[i]<<endl;
                if (len & 1)
                {
                    kk -= nums[i];
                }
                else
                {
                    kk += nums[i];
                }
                if (product > limit || product < 0)
                    product = -1;
                dp.insert({kk, 1 - len, (int)product});
                if (ans < product && kk == k)
                    ans = product;
            }
        }
        return ans;
    }
};