#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        set<int> sts;for(auto s:stones)sts.insert(s);
        if(stones[1]!=1)return 0;
        set<pair<int,int>> rec;
        rec.insert({1,1});
        while(rec.size()){
            int cur = rec.begin()->first;if(cur==stones.back())return 1;
            while(rec.size()&&rec.begin()->first==cur){
                int gp = rec.begin()->second;
                if(gp>1&&sts.find(gp+cur-1)!=sts.end())rec.insert({gp+cur-1,gp-1});
                if(sts.find(gp+cur)!=sts.end())rec.insert({gp+cur,gp});
                if(gp<INT_MAX&&sts.find(gp+cur+1)!=sts.end())rec.insert({gp+cur+1,gp+1});
                rec.erase(rec.begin());
            }
        }
        return 0;
    }
};