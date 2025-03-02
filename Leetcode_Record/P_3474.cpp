#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string generateString(string str1, string str2)
    {
        vector<char> ans(str1.size() + str2.size() - 1, 0);
        vector<int> z(str2.size(), -1);
        for (int i = 1, cur = -1; i < str2.size(); i++)
        {
            while (cur >= 0 && str2[cur + 1] != str2[i])
                cur = z[cur];
            if (str2[cur + 1] == str2[i])
                cur++;
            z[i] = cur;
        }

        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] == 'T')
            {
                for (int j = 0; j < str2.size(); j++)
                {
                    if (ans[i + j] != 0 && ans[i + j] != str2[j])
                        return "";
                    ans[j + i] = str2[j];
                }
            }
        }
        vector<int> pos;
        for (int i = 0, cur = -1; i < ans.size(); i++)
        {
            if (ans[i] == 0)
            {
                pos.push_back(i);
                ans[i] = 'a';
            }
            while (cur >= 0 && str2[cur + 1] != ans[i])
                cur = z[cur];
            if (str2[cur + 1] == ans[i])
                cur++;
            if (cur == str2.size() - 1)
            {
                // cout<<"debug\n";
                // cout<<i<<" "<<str2.size()<<str1[i-str2.size()+1]<<endl;
                if (str1[i - str2.size() + 1] != 'T')
                {
                    if (pos.size() == 0 || i - pos.back() >= str2.size())
                        return "";
                    else
                    {
                        ans[pos.back()] = 'b';
                        cur = -1;
                        for (int t = pos.back(); t <= i; t++)
                        {
                            while (cur >= 0 && str2[cur + 1] != ans[t])
                                cur = z[cur];
                            if (str2[cur + 1] == ans[t])
                                cur++;
                        }
                    }
                }
                else
                    cur = z[cur];
            }
        }

        // use zf to check satisfy
        string out = "";
        for (int i = 0; i < ans.size(); i++)
            out += ans[i];
        return out;
    }
};