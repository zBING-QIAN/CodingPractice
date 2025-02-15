#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void zf(string &s, vector<int> &z)
    {
        z.push_back(-1);
        for (int i = 1, cur = -1; i < s.size(); i++)
        {
            while (cur >= 0 && s[cur + 1] != s[i])
            {
                cur = z[cur];
            }
            if (s[cur + 1] == s[i])
                cur++;
            z.push_back(cur);
        }
    }
    void rungoodpos(string &s, string &str, vector<int> &zfs, vector<int> &isgood)
    {
        if (str.size() == 0)
            isgood[0] = 0;
        for (int i = 0, cur = -1; i < s.size(); i++)
        {
            if (str.size() == 0)
            {
                isgood[i + 1] = i + 1;
                continue;
            }
            while (cur >= 0 && s[i] != str[cur + 1])
            {
                cur = zfs[cur];
            }
            if (s[i] == str[cur + 1])
                cur++;
            if (cur == str.size() - 1)
            {
                isgood[i + 1] = i + 1;
                cur = zfs[cur];
            }
            else if (i)
            {
                isgood[i + 1] = isgood[i];
            }
        }
    }
    int shortestMatchingSubstring(string s, string p)
    {
        vector<int> z[3];
        vector<string> str;
        std::string::size_type begin = 0, end = p.find("*");
        while (end != std::string::npos)
        {
            if (end - begin != 0)
            {
                str.push_back(p.substr(begin, end - begin));
            }
            else
            {
                str.push_back("");
            }
            begin = end + 1;
            end = p.find("*", begin);
        }
        str.push_back(p.substr(begin, end - begin));
        vector<vector<int>> zfs;
        for (auto &ps : str)
        {
            zfs.push_back(vector<int>());
            if (ps.size() > 0)
                zf(ps, zfs.back());
        }
        vector<vector<int>> isgood(3, vector<int>(s.size() + 1, -1));
        for (int i = 0; i < 3; i++)
            rungoodpos(s, str[i], zfs[i], isgood[i]);
        int ans = s.size() + 1;
        for (int i = 0; i <= s.size(); i++)
        {
            if (isgood[2][i] == i)
            {
                int prev2 = isgood[1][i - str[2].size()];
                if (prev2 >= 0)
                {
                    int prev1 = isgood[0][prev2 - str[1].size()];
                    if (prev1 >= 0)
                    {
                        if (ans > i - (prev1 - str[0].size()))
                            ans = i - (prev1 - str[0].size());
                    }
                }
            }
        }
        if (ans > s.size())
            return -1;
        return ans;
    }
};