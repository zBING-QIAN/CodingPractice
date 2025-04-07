#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long minOperations(vector<int> &nums, int x, int k)
    {
        int n = nums.size();
        vector<long long> dp(n + 1, 1e16);
        vector<vector<long long>> dpp(k + 1, vector<long long>(n + 1, 1e16));
        map<int, int> big, small;
        for (int i = 0; i < x; i++)
        { // calc dp
            big[nums[i]]++;
        }
        for (int i = 0; (i + 1) * 2 <= x; i++)
        {
            if (big.begin()->second == 0)
                big.erase(big.begin()->first);
            big.begin()->second--;
            small[big.begin()->first]++;
        }
        if (big.begin()->second == 0)
            big.erase(big.begin()->first);
        int mid = big.begin()->first, bcnt = x - x / 2, scnt = x / 2;

        dp[0] = 0;
        for (auto &b : big)
        {
            dp[0] += 1ll * (b.first - mid) * b.second;
        }
        for (auto &s : small)
        {
            dp[0] += 1ll * (mid - s.first) * s.second;
        }
        for (int i = x; i < n; i++)
        { // calc dp
            // for(auto &b:big)cout<<b.first<<" "<<b.second<<", ";cout<<endl;
            dp[i - x + 1] = dp[i - x];
            dp[i - x + 1] -= abs(nums[i - x] - mid);
            dp[i - x + 1] += abs(nums[i] - mid);
            if (nums[i - x] >= mid)
                bcnt--, big[nums[i - x]]--;
            else
                small[nums[i - x]]--, scnt--;
            if (nums[i] >= mid)
                big[nums[i]]++, bcnt++;
            else
                small[nums[i]]++, scnt++;

            while (scnt < x / 2)
            {
                while (big.begin()->second == 0)
                    big.erase(big.begin()->first);
                big.begin()->second--;
                small[big.begin()->first]++;
                dp[i - x + 1] -= (big.begin()->first - mid) * 2;
                bcnt--;
                scnt++;
            }
            while (scnt > x / 2)
            {
                while (small.rbegin()->second == 0)
                    small.erase(small.rbegin()->first);
                small.rbegin()->second--;
                big[small.rbegin()->first]++;
                dp[i - x + 1] -= (mid - small.rbegin()->first) * 2;
                bcnt++;
                scnt--;
            }
            // for(auto &b:big){
            //                 cout<<b.first<<" "<<b.second<<endl;
            //             }
            while (big.begin()->second == 0)
            {
                big.erase(big.begin()->first);
            }

            // cout<<nums[i]<<" "<<mid<<" "<<big.begin()->first<<endl;
            dp[i - x + 1] = dp[i - x + 1] + 1ll * (x / 2) * (big.begin()->first - mid) + 1ll * (x - x / 2) * (mid - big.begin()->first);
            // cout<<dp[i-x+1]<<" "<<big.begin()->first<<" "<<big.begin()->second<<endl;
            mid = big.begin()->first;
        }
        // for(int i=0;i<n;i++)cout<<dp[i]<<" ";cout<<endl;
        for (int i = 0; i < n; i++)
            dpp[0][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dpp[j][i] = dpp[j][i - 1];
                if (i >= x && dpp[j][i] > dpp[j - 1][i - x] + dp[i - x])
                {
                    dpp[j][i] = dpp[j - 1][i - x] + dp[i - x];
                }
            }
        }
        // for(int i=0;i<=k;i++){
        //     for(int j=0;j<=n;j++){cout<<dpp[i][j]<<" ";}cout<<endl;
        // }
        return dpp[k][n];
    }
};