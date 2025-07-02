#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int possibleStringCount(string word, int k)
    {
        int ans = 0, mod = 1e9 + 7;
        vector<pair<char, int>> letters;
        letters.push_back({word[0], 0});
        for (int i = 1; i < word.size(); i++)
        {
            if (word[i - 1] == word[i])
            {
                letters.back().second++;
            }
            else
            {
                letters.push_back({word[i], 0});
            }
        }
        k -= letters.size();
        // cout<<"k is "<<k<<endl;
        if (k < 0)
            k = 0;
        vector<vector<long long>> dp(letters.size(), vector<long long>(k + 1, 0));
        for (int i = 0; i <= letters[0].second; i++)
        {
            if (i <= k)
                dp[0][i] = 1;
            else
                dp[0][k]++;
            // if(i<=k)cout<<0<<" "<<i<<" "<< dp[0][i]<<endl;
            // else cout<<0<<" "<<i<<" "<< dp[0][k]<<endl;
        }
        for (int i = 1; i < letters.size(); i++)
        {
            long long sum = 0;
            // cout<<i<<" letters i "<<letters[i].second<<endl;
            for (int j = 0; j <= letters[i].second + k; j++)
            {

                if (j <= k)
                {
                    sum += dp[i - 1][j];
                    dp[i][j] = (dp[i][j] + sum) % mod;
                }
                else
                    dp[i][k] = (dp[i][k] + sum) % mod;
                // if(j==k)dp[i][j] = (dp[i][j] + (letters[i].second)*dp[i-1][j])%mod;
                // cout<<i<<" "<<j<<" "<<sum<<endl;
                if (j >= letters[i].second)
                    sum -= dp[i - 1][j - letters[i].second];
                sum %= mod;
                if (sum < 0)
                    sum += mod;
            }
            // for(int j=k+1;j<=letters[i].second+k;j++){
            //     dp[i][k]=(dp[i][k]+sum)%mod;
            //     if(j>=letters[i].second)sum-=dp[i-1][j-letters[i].second];
            //     sum%=mod;
            //     if(sum<0)sum+=mod;
            // }
        }

        return dp[letters.size() - 1][k];
    }
};