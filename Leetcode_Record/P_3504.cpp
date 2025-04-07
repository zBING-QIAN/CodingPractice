#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void run_pal(string &s, vector<int> &pal)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j + i < n && i >= j; j++)
            {
                if (s[i + j] == s[i - j])
                    pal[i - j] = max(pal[i - j], j * 2 + 1);
                else
                    break;
            }
            for (int j = 1; j + i <= n && i >= j; j++)
            {
                if (s[i - j] == s[i + j - 1])
                    pal[i - j] = max(pal[i - j], j * 2);
                else
                    break;
            }
        }
    }
    void kmp(string s, vector<int> &kp)
    {
        kp.resize(s.size(), -1);
        for (int i = 1, cur = -1; i < s.size(); i++)
        {
            while (cur >= 0 && s[i] != s[cur + 1])
            {
                cur = kp[cur];
            }
            if (s[i] == s[cur + 1])
                cur++;
            kp[i] = cur;
        }
    }

    int longestPalindrome(string s, string t)
    {
        vector<int> spal(s.size() + 1, 1), tpal(t.size() + 1, 1), skmp;
        spal.back() = 0;
        tpal.back() = 0;
        int ans = 0, slen = s.size();
        run_pal(s, spal);
        // for(int i=0;i<s.size();i++)cout<<spal[i]<<" ";cout<<endl;
        for (int i = 0; i < s.size(); i++)
            ans = max(spal[i], ans);
        reverse(t.begin(), t.end());
        run_pal(t, tpal);
        // for(int i=0;i<t.size();i++)cout<<tpal[i]<<" ";cout<<endl;
        for (int i = 0; i < t.size(); i++)
            ans = max(tpal[i], ans);
        for (int i = 0; i < s.size(); i++)
        {
            kmp(s.substr(i), skmp);
            for (int j = 0, cur = -1; j < t.size() && i + cur < slen; j++)
            {
                while (cur >= 0 && s[i + cur + 1] != t[j])
                {
                    cur = skmp[cur];
                }
                if (s[i + cur + 1] == t[j])
                    cur++;
                ans = max(ans, (cur + 1) * 2 + max(spal[i + cur + 1], tpal[j + 1]));
            }
        }
        return ans;
    }
};