#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestSubsequenceRepeatedK(string s, int k)
    {
        vector<int> cnt(26, 0);
        for (auto c : s)
            cnt[c - 'a']++;
        vector<char> letters;
        string ans = "";
        for (int i = 0; i < 26; i++)
            if (cnt[i] >= k)
            {
                letters.push_back('a' + i);
                ans = string(1, 'a' + i);
            }
        map<string, array<int, 2>> dp;
        for (auto c1 : letters)
            for (auto c2 : letters)
                dp[string(1, c1) + c2] = {0, 0};
        for (int t = 2; t <= 8 && dp.size(); t++)
        {
            for (int i = 0; i < s.size(); i++)
            {
                for (auto &cand : dp)
                {
                    if (s[i] == cand.first[cand.second[1]])
                    {
                        if (cand.second[1] + 1 == t)
                        {
                            cand.second[1] = 0;
                            cand.second[0]++;
                        }
                        else
                            cand.second[1]++;
                    }
                }
            }

            map<string, array<int, 2>> nxtdp;
            for (auto &cand : dp)
            {
                if (cand.second[0] >= k)
                {
                    ans = cand.first;
                    for (auto &c : letters)
                    {
                        nxtdp[cand.first + c] = {0, 0};
                    }
                }
            }
            dp = nxtdp;
        }
        return ans;
    }
};