#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumTimeToInitialState(string word, int k)
    {
        int n = word.size();
        vector<int> dp(n, -1);
        for (int i = 1; i < n; i++)
        {
            int p = dp[i - 1];
            while (p >= 0 && word[p + 1] != word[i])
            {
                p = dp[p];
            }
            if (word[p + 1] == word[i])
                p++;
            dp[i] = p;
        }
        int lcp = dp.back();
        while (lcp >= 0 && ((n - lcp - 1) % k))
        {
            lcp = dp[lcp];
        }
        return (n + k - lcp - 2) / k;
    }
};