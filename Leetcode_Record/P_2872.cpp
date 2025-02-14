#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> link(n,vector<int>());
        vector<int> value=values,visit_cnt(n,0);
        for(auto &e:edges){
            link[e[0]].push_back(e[1]);
            link[e[1]].push_back(e[0]);
        }
        int ans = 0;
        vector<int> que;
        for(int i=0;i<n;i++){if(link[i].size()<=1){que.push_back(i);}}
        int flag = 0;
        while(flag<que.size()){
            int cur = que[flag];
            visit_cnt[cur]++;
            int cur_val = values[cur];
            for(int i=0;i<link[cur].size();i++){
                int to = link[cur][i];
                if(visit_cnt[to] == link[to].size()){
                    if(value[to]%k){cur_val = (cur_val+value[to])%k;}
                }else{
                    visit_cnt[to]++;
                    if(visit_cnt[to]==link[to].size()-1)que.push_back(to);
                }
            }
            value[cur] = cur_val;
            if ((value[cur]%k)==0)ans++;
            flag++;
        }
        return ans;
    }
};