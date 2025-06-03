#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        int n = status.size();
        set<int> lockboxes;
        vector<int> finish(n, 0);
        queue<int> q;
        int res = 0;
        for (auto i : initialBoxes)
        {
            if (status[i])
            {
                q.push(i);
                finish[i] = 1;
            }
            else
                lockboxes.insert(i);
        }
        while (q.size())
        {
            int cur = q.front();
            q.pop();
            res += candies[cur];
            for (auto k : keys[cur])
            {
                status[k] = 1;
                if (finish[k] == 0 && lockboxes.find(k) != lockboxes.end())
                {
                    finish[k] = 1;
                    q.push(k);
                    lockboxes.erase(k);
                }
            }
            for (auto b : containedBoxes[cur])
            {
                if (status[b] && finish[b] == 0)
                {
                    finish[b] = 1;
                    q.push(b);
                    lockboxes.erase(b);
                }
                else
                {
                    lockboxes.insert(b);
                }
            }
        }
        return res;
    }
};