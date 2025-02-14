#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leader(int cur,vector<int> &id,vector<int> &value){
        vector<int> rec;
        int v = value[cur];
        while(cur!=id[cur]){
            rec.push_back(cur);
            cur=id[cur];
            v &= value[cur];
        }
        while(rec.size()){id[rec.back()] = cur;value[rec.back()]=v;rec.pop_back();}
        value[cur] = v;
        return cur;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> id(n,0),value(n,INT_MAX),ans;
        for(int i=0;i<n;i++){id[i] = i;}
        for(auto &e:edges){
            int aid = leader(e[0],id,value);
            int bid = leader(e[1],id,value);
            // cout<<aid<<" "<<value[aid]<<" "<<e[2]<<endl;
            value[aid] &= value[bid]&e[2];
            
            // cout<<aid<<" "<<value[aid]<<" "<<e[2]<<endl;
            id[bid] = aid;
        }
        for(auto &e:query){
            int aid = leader(e[0],id,value);
            int bid = leader(e[1],id,value);
            if(aid!=bid)ans.push_back(-1);
            else ans.push_back(value[aid]);
        }
        return ans;
    }
};