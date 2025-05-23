#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        int ans = 0, n = ratings.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({ratings[i], i});
        }
        vector<int> dp(n, 0);
        while (pq.size())
        {
            auto [v, i] = pq.top();
            pq.pop();
            int c = 1;
            if (i > 0 && ratings[i - 1] < v && c < dp[i - 1] + 1)
            {
                c = dp[i - 1] + 1;
            }
            if (i + 1 < n && ratings[i + 1] < v && c < dp[i + 1] + 1)
            {
                c = dp[i + 1] + 1;
            }
            dp[i] = c;
            ans += c;
        }
        return ans;
    }
};