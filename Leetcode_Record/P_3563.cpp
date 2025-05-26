#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char prevchar(char c)
    {
        if (c == 'a')
            return 'z';
        else
            return c - 1;
    }
    char nxtchar(char c)
    {
        if (c == 'z')
            return 'a';
        else
            return c + 1;
    }
    vector<vector<bool>> skip;

    string lexicographicallySmallestString(string s)
    {
        int n = s.size();
        skip.resize(n, vector<bool>(n, 0));
        for (int i = 1; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if ((i == 1 || skip[j - i + 1][j - 1]) && (s[j - i] == nxtchar(s[j]) || s[j - i] == prevchar(s[j])))
                    skip[j - i][j] = 1;
                else
                    for (int k = j - i + 1; k < j; k++)
                    {
                        if (skip[j - i][k] && skip[k + 1][j])
                        {
                            skip[j - i][j] = 1;
                            break;
                        }
                    }
            }
        }
        vector<int> gonext;
        gonext.push_back(0);
        s.push_back(0);
        for (int i = 1; i < n; i++)
        {
            if (skip[0][i])
                gonext.push_back(i + 1);
        }
        string res;
        while (gonext.size())
        {
            char tmp = 'z' + 1;
            for (int i = 0; i < gonext.size(); i++)
            {
                tmp = min(tmp, s[gonext[i]]);
            }
            if (tmp && tmp <= 'z')
                res.push_back(tmp);
            set<int> nxtstate;
            for (int i = 0; i < gonext.size(); i++)
                if (s[gonext[i]] == tmp)
                {
                    int base = gonext[i] + 1;
                    if (base <= n)
                        nxtstate.insert(base);
                    for (int j = base + 1; j < n; j++)
                    {
                        if (skip[base][j])
                            nxtstate.insert(j + 1);
                    }
                }
            gonext = vector<int>();
            for (auto t : nxtstate)
                gonext.push_back(t);
        }
        return res;
    }
};