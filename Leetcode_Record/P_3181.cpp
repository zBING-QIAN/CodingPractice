#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxTotalReward(vector<int> &rewardValues)
    {
        sort(rewardValues.begin(), rewardValues.end());
        int n = 0;
        for (int i = 1; i < rewardValues.size(); i++)
        {
            if (rewardValues[i] != rewardValues[n])
            {
                n++;
                rewardValues[n] = rewardValues[i];
            }
        }
        rewardValues.resize(n + 1);

        vector<bool> dp(rewardValues.back(), 0);
        dp[0] = 1;
        for (int i = 0, j = 0; i < dp.size(); i++)
        {
            if (dp[i])
            {
                while (j < n && rewardValues[j] <= i)
                    j++;
                for (int t = j; t < n && i + rewardValues[t] < rewardValues.back(); t++)
                    dp[i + rewardValues[t]] = 1;
            }
            if (dp.back())
                break;
        }
        int best = 0;
        for (int i = dp.size() - 1; i; i--)
        {
            if (dp[i])
            {
                best = i;
                break;
            }
        }
        return best + rewardValues.back();
    }
};