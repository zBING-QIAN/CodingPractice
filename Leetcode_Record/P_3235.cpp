#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool touch(int x0, int y0, int r0, int x1, int y1, int r1)
    {
        return 1ll * (x0 - x1) * (x0 - x1) + 1ll * (y0 - y1) * (y0 - y1) <= 1ll * (r1 + r0) * (r1 + r0);
    }
    vector<int> stac;
    int head(vector<int> &sid, int a)
    {
        while (sid[a] != sid[sid[a]])
        {
            stac.push_back(a);
            a = sid[a];
        }
        while (stac.size())
        {
            sid[stac.back()] = sid[a];
            stac.pop_back();
        }
        return sid[a];
    }
    bool touch_line(int cx, int cy, int cr, int x, int y, int dir)
    {
        if (dir)
        {
            swap(cx, cy);
            swap(x, y);
        }
        if (x > cr + cx || x < cx - cr)
            return 0;
        if (cy >= y)
            return 1ll * (cy - y) * (cy - y) <= (1ll * cr * cr - 1ll * (cx - x) * (cx - x));
        return 1;
    }
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>> &circles)
    {
        int n = circles.size();
        vector<int> sid(n);
        vector<bool> touch_left(n, 0), touch_right(n, 0), touch_bot(n, 0), touch_up(n, 0);
        for (int i = 0; i < n; i++)
        {
            sid[i] = i;
            touch_left[i] = touch_line(circles[i][0], circles[i][1], circles[i][2], 0, yCorner, 0);
            touch_right[i] = touch_line(circles[i][0], circles[i][1], circles[i][2], xCorner, yCorner, 0);
            touch_up[i] = touch_line(circles[i][0], circles[i][1], circles[i][2], xCorner, yCorner, 1);
            touch_bot[i] = touch_line(circles[i][0], circles[i][1], circles[i][2], xCorner, 0, 1);

            if (touch_left[i] && (touch_right[i] | touch_bot[i]))
                return false;
            if (touch_up[i] && (touch_right[i] | touch_bot[i]))
                return false;
        }
        for (int i = 0; i < n; i++)
        {
            bool in0 = circles[i][0] <= xCorner && circles[i][1] <= yCorner;
            for (int j = i + 1; j < n; j++)
            {
                int a = head(sid, i), b = head(sid, j);
                if (a == b)
                    continue;
                bool in1 = circles[j][0] <= xCorner && circles[j][1] <= yCorner;
                if ((in0 | in1) == 0)
                {
                    long long tmp0 = (circles[i][0] - circles[j][0]), tmp1 = (circles[i][1] - circles[j][1]);
                    int tmp = j;
                    if (tmp0 < 0)
                    {
                        tmp1 = -tmp1;
                        tmp0 = -tmp0;
                        tmp = i;
                    }
                    if (tmp1 * (xCorner - circles[tmp][0]) >= tmp0 * (yCorner - circles[tmp][1]))
                        continue;
                }
                if (touch(circles[i][0], circles[i][1], circles[i][2], circles[j][0], circles[j][1], circles[j][2]))
                {
                    sid[b] = a;
                    touch_left[a] = touch_left[a] | touch_left[b];
                    touch_right[a] = touch_right[a] | touch_right[b];
                    touch_bot[a] = touch_bot[a] | touch_bot[b];
                    touch_up[a] = touch_up[a] | touch_up[b];
                    if (touch_left[a] && (touch_right[a] | touch_bot[a]))
                        return false;
                    if (touch_up[a] && (touch_bot[a] | touch_right[a]))
                        return false;
                }
            }
        }
        return true;
    }
};