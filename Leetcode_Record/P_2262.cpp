#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long appealSum(string s) {
        long long ans =0;vector<int> rec(26,-1);
        for(int i=0;i<s.size();i++){
            rec[s[i]-'a'] = i;
            for(int j=0;j<26;j++){
                ans+=(rec[j]+1);
            }
        }
        return ans;
    }
};