#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs)
    {
        vector<array<int, 2>> pairs;
        for (auto &p : conflictingPairs)
        {
            if (p[0] > p[1])
                swap(p[0], p[1]);
            pairs.push_back({p[1], p[0]});
        }
        sort(pairs.begin(), pairs.end());
        long long ans = 0, addition = 0;
        for (int i = 1, j = 0, skipj = 0, prevadd = 0; i <= n; i++)
        {
            while (j < pairs.size() && i > pairs[j][1])
                j++;
            int end = (j < pairs.size()) ? pairs[j][0] : n + 1;
            ans += end - i;
            if (i == n - 1 || j >= skipj)
            {
                if (prevadd > addition)
                    addition = prevadd;
                prevadd = 0;
                skipj = j + 1;
            }
            while (skipj < pairs.size() && i > pairs[skipj][1])
                skipj++;
            int skipend = (skipj < pairs.size()) ? pairs[skipj][0] : n + 1;
            prevadd += skipend - end;
            // cout<<i<<" "<<end<<" "<<skipend<<" "<<ans<<" "<<addition<<endl;

            // cout<<i<<" "<<end<<" "<<ans<<" "<<addition<<endl;
        }

        return ans + addition;
    }
};