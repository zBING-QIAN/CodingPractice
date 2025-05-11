#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int head(vector<array<int, 2>> &sid, int cur)
    {
        vector<int> stac;
        while (sid[cur][0] != sid[sid[cur][0]][0])
        {
            stac.push_back(cur);
            cur = sid[cur][0];
        }
        while (stac.size())
        {
            sid[stac.back()][0] = sid[cur][0];
            stac.pop_back();
        }
        return sid[cur][0];
    }
    long long maxScore(int n, vector<vector<int>> &edges)
    {
        vector<array<int, 2>> sid(n);
        set<int> loops;
        vector<int> lines, lps;
        for (int i = 0; i < n; i++)
        {
            sid[i] = {i, 1};
        }
        for (auto &e : edges)
        {
            int h0 = head(sid, e[0]);
            int h1 = head(sid, e[1]);
            if (h1 == h0)
            {
                loops.insert(h0);
            }
            else
                sid[h1][0] = h0, sid[h0][1] += sid[h1][1];
        }
        for (int i = 0; i < n; i++)
            if (sid[i][0] == i && loops.count(i) == 0)
                lines.push_back(sid[i][1]);
        for (auto l : loops)
            lps.push_back(sid[l][1]);
        sort(lps.begin(), lps.end());
        sort(lines.begin(), lines.end());
        long long res = 0;
        for (int i = lps.size() - 1; i >= 0; i--)
        {
            res += 1ll * n * (n - 1) + 1ll * n * (n - 2);
            n--;
            for (int t = 3; t < lps[i]; t++)
            {
                res += 1ll * n * (n - 2);
                n--;
            }
            res += 1ll * n * (n - 1);
            n -= 2;
        }

        for (int i = lines.size() - 1; i >= 0; i--)
        {
            if (lines[i] > 1)
                res += 1ll * n * (n - 1);
            n -= 2;
            for (int t = 2; t < lines[i]; t++)
            {
                res += 1ll * n * (n + 2);
                n--;
            }
        }
        return res;
    }
};