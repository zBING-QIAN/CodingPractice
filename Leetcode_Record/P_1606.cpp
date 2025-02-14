#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> good;
        set<pair<int,int>> busy;
        vector<int> cnt(k,0);
        vector<int> ans;
        for(int i=0;i<k;i++)good.insert(i);
        for(int i=0;i<arrival.size();i++){
            auto rm_end = busy.begin();
            for(auto &b:busy){
                if(b.first<=arrival[i]){good.insert(b.second);rm_end++;}
                else break;
            }
            busy.erase(busy.begin(),rm_end);
            if(good.size()==0)continue;
            auto it = good.lower_bound(i%k);
            if(it==good.end()){
                it=good.begin();
            }
            cnt[*it]++;
            busy.insert({arrival[i]+load[i],*it});
            good.erase(it);

        }
        int tmp = 0;
        for(int i=0;i<k;i++){
            if(tmp<cnt[i]){
                ans.clear();ans.push_back(i);tmp = cnt[i];
            }else if(tmp==cnt[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};