#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> b1,b2;
        set<int> bs;
        vector<int> l1,l2;
        for(auto b:basket1){b1[b]++;bs.insert(b);}
        for(auto b:basket2){b2[b]++;bs.insert(b);}
        for(auto b:bs){
            int avg = (b1[b]+b2[b])>>1;
            if(b1[b]+b2[b]!=(avg<<1))return -1;
            for(int i=b1[b];i>avg;i--)l1.push_back(b);
            for(int i=b2[b];i>avg;i--)l2.push_back(b);
        }
        if(l1.size()!=l2.size())return -1;
        sort(l1.begin(),l1.end());
        sort(l2.begin(),l2.end());
        int small = (*bs.begin());
        long long ans = 0;
        for(int i=0;i<l1.size();i++){
            if(min(l1[i],l2[l1.size()-i-1])>2*small)ans+=small*2;
            else
            ans += min(l1[i],l2[l1.size()-i-1]);
        }

        return ans;
    }
};