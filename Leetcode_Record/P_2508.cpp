#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(int n, vector<vector<int>> &edges)
    {
        vector<set<int>> cnt(n, set<int>());
        for (auto &e : edges)
        {
            cnt[e[0] - 1].insert(e[1] - 1);
            cnt[e[1] - 1].insert(e[0] - 1);
        }
        vector<int> odds;
        for (int i = 0; i < n; i++)
        {
            if (cnt[i].size() & 1)
            {
                odds.push_back(i);
            }
        }
        if (odds.size() > 4)
            return 0;
        if (odds.size() == 4)
        {
            for (int i = 1; i < 4; i++)
            {
                int a = odds[0], b = odds[i], c = (i == 1) ? odds[2] : odds[1], d = (i == 3) ? odds[2] : odds[3];
                if (cnt[a].find(b) == cnt[a].end() && cnt[c].find(d) == cnt[c].end())
                {
                    return 1;
                }
            }
        }
        else if (odds.size() == 3)
        {
            return 0;
        }
        else if (odds.size() == 2)
        {
            if (cnt[odds[0]].find(odds[1]) == cnt[odds[0]].end())
                return 1;
            for (int i = 0; i < n; i++)
            {
                if (cnt[i].find(odds[0]) == cnt[i].end() && cnt[i].find(odds[1]) == cnt[i].end())
                    return 1;
            }
        }
        else if (odds.size() == 1)
            return 0;
        else
            return 1;
        return 0;
    }
};