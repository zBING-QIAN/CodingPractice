#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        vector<int> first(prices.size(), 0);
        for (int i = 1, small = prices[0]; i < prices.size(); i++)
        {
            first[i] = prices[i] - small;
            small = min(small, prices[i]);
            ans = max(first[i], ans);
        }
        if (prices.size() > 3)
        {
            int bestprofit = max(first[1], 0);
            int bestsmall = prices[2];

            for (int i = 3; i < prices.size(); i++)
            {
                if (prices[i] - bestsmall + bestprofit > ans)
                {
                    ans = prices[i] - bestsmall + bestprofit;
                }
                bestsmall = min(bestsmall, prices[i]);
                if (first[i - 1] - prices[i] > bestprofit - bestsmall)
                {
                    bestprofit = first[i - 1];
                    bestsmall = prices[i];
                }
                first[i] = max(first[i], first[i - 1]);
            }
        }

        return ans;
    }
};