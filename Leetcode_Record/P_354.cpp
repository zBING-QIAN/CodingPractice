#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int,int>> env;
        for(auto &e :envelopes){
            env.push_back({e[0],e[1]});
        }
        sort(env.begin(),env.end(),[](auto &a,auto &b){return a.first<b.first||((a.first==b.first)&&a.second>b.second);});
        vector<int> rec;

        for(int i=0;i<env.size();i++){
            if(rec.size()==0||rec.back()<env[i].second){rec.push_back(env[i].second);continue;}
            int l=0,r=rec.size()-1;
            while(l<r){
                int mid = (l+r)>>1;
                if(rec[mid]<env[i].second)l=mid+1;
                else r=mid;
            }
            rec[l] = env[i].second;
        }

        return rec.size();
    }
};