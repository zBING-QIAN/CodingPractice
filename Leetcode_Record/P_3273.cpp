#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long ans =0,tt = 0;
        int n = damage.size();
        for(int i=0;i<n;i++){
            int t = (health[i]+power-1)/power;
            health[i] = t;
            tt+=t;
        }
        vector<int> idx(n,0);
        for(int i =0;i<n;i++){idx[i]=i;}
        sort(idx.begin(),idx.end(),[&](auto a,auto b){return damage[a]*health[b]>damage[b]*health[a];});
        for(int i = 0,t = 0;i<n;i++){
            t+=health[idx[i]];
            ans += (long long)(damage[idx[i]])*t;
        }

        return ans;
    }
};