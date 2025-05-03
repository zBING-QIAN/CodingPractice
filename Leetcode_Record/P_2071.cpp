#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        map<int, int> task;
        for (auto t : tasks)
            task[t]++;
        sort(workers.begin(), workers.end());
        int n = workers.size(), l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            int pil = pills;
            int i = mid;
            map<int, int> tasktmp = task;
            for (; i < n; i++)
            {
                auto it = tasktmp.begin();
                if (it == tasktmp.end())
                    break;
                if (it->first <= workers[i])
                {
                    it->second--;
                }
                else if (pil > 0)
                {
                    it = tasktmp.upper_bound(workers[i] + strength);
                    if (it != tasktmp.begin())
                    {
                        it--;
                        it->second--;
                        pil--;
                    }
                    else
                        break;
                }
                else
                    break;
                if (it->second == 0)
                    tasktmp.erase(it);
            }
            if (pil >= 0 && i == n)
                r = mid;
            else
                l = mid + 1;
        }

        return n - l;
    }
};