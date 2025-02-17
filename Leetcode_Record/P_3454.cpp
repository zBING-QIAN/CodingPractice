#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void preprocess(vector<vector<int>> &squares, vector<array<int, 3>> &output)
    {                                  // output : {bottom,h,w}
        set<array<int, 3>> roofh;      // {h,l,r}
        map<array<int, 2>, int> roofw; // {l,r,h}

        int cur_width = 0, cur_bottom = 0;
        sort(squares.begin(), squares.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });
        for (auto &sq : squares)
        {
            int l = sq[0], r = sq[0] + sq[2], u = sq[1] + sq[2], d = sq[1];
            while (roofh.size() > 0 && d >= (*roofh.begin())[0])
            {
                int nxt_bottom = (*roofh.begin())[0];
                output.push_back({cur_bottom, nxt_bottom - cur_bottom, cur_width});
                // cout<<"cur bottom "<<cur_bottom<<" "<<nxt_bottom-cur_bottom<<" "<<cur_width<<endl;
                cur_bottom = nxt_bottom;
                while (roofh.size() && (*roofh.begin())[0] == cur_bottom)
                {
                    cur_width -= (*roofh.begin())[2] - (*roofh.begin())[1];
                    roofw.erase({(*roofh.begin())[1], (*roofh.begin())[2]});
                    roofh.erase(roofh.begin());
                }
                // pop lowest roofs and pushback output then increase cur_bottom
                // decrease cur_width
            }
            if (cur_bottom < d && cur_width > 0)
            {
                // cout<<"ff "<<cur_bottom<<" "<<d<<" "<<cur_width<<endl;
                output.push_back({cur_bottom, d - cur_bottom, cur_width});
            }
            cur_bottom = d;
            auto ub = roofw.upper_bound({l, l});
            if (ub != roofw.begin())
            {
                ub--;
            }
            vector<array<int, 3>> rmlist, inlist;
            while (ub != roofw.end() && ub->first[0] < r)
            {
                if (ub->second > u)
                {
                    if (l < ub->first[0])
                    {
                        inlist.push_back({l, ub->first[0], u});
                    }
                    l = max(l, ub->first[1]);
                }
                else
                {
                    if (ub->first[1] > l)
                        rmlist.push_back({ub->first[0], ub->first[1], ub->second});
                    if (ub->first[0] < l && ub->first[1] > l)
                        inlist.push_back({ub->first[0], l, ub->second});
                    if (ub->first[1] > r)
                        inlist.push_back({r, ub->first[1], ub->second});
                }
                ub++;
            }
            if (l < r)
            {
                inlist.push_back({l, r, u});
            }
            for (auto &rm : rmlist)
            {
                // cout<<"rm  "<<rm[0]<<" "<<rm[1]<<" "<<rm[2]<<endl;
                roofh.erase({rm[2], rm[0], rm[1]});
                roofw.erase({rm[0], rm[1]});
                cur_width -= rm[1] - rm[0];
            }
            for (auto &in : inlist)
            {
                // cout<<"insert  "<<in[0]<<" "<<in[1]<<" "<<in[2]<<endl;
                roofh.insert({in[2], in[0], in[1]});
                roofw[{in[0], in[1]}] = in[2];

                cur_width += in[1] - in[0];
            }
        }
        for (auto &r : roofh)
        {
            output.push_back({cur_bottom, r[0] - cur_bottom, r[2] - r[1]});

            // cout<<"cur bottom "<<cur_bottom<<" "<<r[0]-cur_bottom<<" "<<r[2]-r[1]<<endl;
        }
    }
    double separateSquares(vector<vector<int>> &squares)
    {
        double l = 0, r = 2e9;
        int n = squares.size();
        vector<array<int, 3>> rects;
        preprocess(squares, rects);
        // for(auto &rect:rects)cout<<rect[0]<<" "<<rect[1]<<" "<<rect[2]<<endl;
        n = rects.size();
        while (l + 1e-5 < r)
        {
            double mid = (l + r) / 2;
            double up = 0, down = 0;
            for (int i = 0; i < n; i++)
            {
                double y = rects[i][0], h = rects[i][1], w = rects[i][2];
                if (y < mid)
                {
                    if (mid - y >= h)
                        down += h * w;
                    else
                        down += (mid - y) * w;
                }
                if (y + h > mid)
                {
                    if (mid <= y)
                        up += w * h;
                    else
                        up += (y + h - mid) * w;
                }
            }
            if (up <= down)
                r = mid;
            else
                l = mid;
        }
        return (l + r) / 2;
    }
};