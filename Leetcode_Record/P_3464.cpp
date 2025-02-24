#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct link
    {
        link *nxt, *pre;
        bool picked;
        int x, y;
        link(array<int, 2> e)
        {
            x = e[0], y = e[1];
            picked = 0;
        }
        void remove()
        {
            if (nxt && pre)
            {
                nxt->pre = pre;
                pre->nxt = nxt;
            }
        }
    };

    bool check(vector<link> &circle, int k, int dist)
    {
        int n = circle.size();
        for (int i = 0; i < circle.size(); i++)
        {
            int nxt = (i + 1) % n, pre = (i + n - 1) % n;
            circle[i].nxt = &circle[nxt];
            circle[i].pre = &circle[pre];
            circle[i].picked = 0;
        }

        int cnt = 1;
        link *cur = &circle[0];
        queue<link *> rec;
        while (1)
        {
            cur->picked = 1;
            rec.push(cur);
            if ((abs(cur->x - rec.front()->x) + abs(cur->y - rec.front()->y)) >= dist && rec.size() == k)
                return 1;
            int x = cur->x, y = cur->y;
            link *nxt = cur->nxt;
            while ((abs(nxt->x - x) + abs(nxt->y - y) < dist) || nxt->picked)
            {
                if (nxt->picked)
                {
                    rec.pop();
                    nxt->remove();
                    // cout<<nxt->x<<" "<<nxt->y<<endl;
                    if (rec.size() == 0)
                    {
                        assert(cur == nxt);
                        if (nxt->nxt == nxt)
                            return 0;
                        cur = nxt->nxt;
                        rec.push(cur);
                        cur->picked = 1;
                        x = cur->x, y = cur->y;
                    }
                }
                nxt = nxt->nxt;
            }
            if (abs(nxt->x - x) + abs(nxt->y - y) >= dist && nxt->picked == 0)
            {
                cur = nxt;
            }
            else
                break;
        }

        return 0;
    }

    int maxDistance(int side, vector<vector<int>> &points, int k)
    {
        long long left = 1, right = side + 2;
        vector<array<int, 2>> l, r, t, b;
        int n = points.size();
        for (auto &p : points)
        {
            if (p[0] == 0)
            {
                l.push_back({p[0], p[1]});
            }
            else if (p[0] == side)
            {
                r.push_back({p[0], p[1]});
            }
            else if (p[1] == 0)
            {
                b.push_back({p[0], p[1]});
            }
            else
                t.push_back({p[0], p[1]});
        }
        sort(l.begin(), l.end(), [](auto &a, auto &b)
             { return a > b; });
        sort(t.begin(), t.end(), [](auto &a, auto &b)
             { return a > b; });

        sort(r.begin(), r.end());
        sort(b.begin(), b.end());
        vector<link> circle;
        for (auto e : b)
            circle.push_back(link(e));
        for (auto e : r)
            circle.push_back(link(e));
        for (auto e : t)
            circle.push_back(link(e));
        for (auto e : l)
            circle.push_back(link(e));
        while (left < right)
        {
            int mid = (left + right) >> 1;
            if (check(circle, k, mid))
            {
                left = mid + 1;
            }
            else
                right = mid;
        }
        return left - 1;
    }
};