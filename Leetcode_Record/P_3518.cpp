#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long> bar;
    long long calc(vector<int> &cnt, int c)
    {
        cnt[c]--;
        int sum = 0, mostcnt = 0, mci = 0;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i])
            {
                sum += cnt[i];
                if (mostcnt < cnt[i])
                {
                    mostcnt = cnt[i], mci = i;
                }
            }
        }
        long long upper = 1;
        while (mostcnt < sum)
        {
            mostcnt++;
            upper *= mostcnt;
            if (upper > 1e15)
            {
                cnt[c]++;
                return 1000000;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] && i != mci)
            {
                if (cnt[i] > 16)
                {
                    cnt[c]++;
                    return 1000000;
                }
                upper /= bar[cnt[i]];
            }
        }
        cnt[c]++;
        return upper;
    }

    string smallestPalindrome(string s, int k)
    {
        int n = s.size();
        n >>= 1;
        bar.resize(17, 1);
        for (int i = 1; i < 17; i++)
            bar[i] = bar[i - 1] * i;
        vector<int> cnt(26, 0);
        for (auto c : s)
        {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
            cnt[i] /= 2;
        string ans;
        for (int i = 0; i < n; i++)
        {
            for (int c = 0; c < 26; c++)
            {
                if (cnt[c])
                {
                    long long tmp = calc(cnt, c);
                    if (tmp < k)
                        k -= tmp;
                    else
                    {
                        cnt[c]--;
                        ans += c + 'a';
                        break;
                    }
                }
            }
        }

        if (ans.size() != n || k != 1)
            return "";
        string ans_r = ans;
        reverse(ans_r.begin(), ans_r.end());
        if (s.size() & 1)
        {
            ans += s[n];
        }
        return ans + ans_r;
    }
};