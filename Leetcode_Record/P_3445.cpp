#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s, int k) {
        int ans = -1e9; // not good
        int n = s.size();
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(i==j)continue;
                queue<pair<int,int>> que;que.push({0,0});
                vector<pair<int,int>> rec(4,{1e9,0});
                vector<int> ready(4,-1e9);
                
                int cnt_i = 0,cnt_j=0;
                for(int t=0;t<n;t++){
                    if(s[t]=='0'+i)cnt_i++;
                    if(s[t]=='0'+j)cnt_j++;
                    if(que.size()==k){
                        auto [a,b] = que.front();
                        int type = ((a&1)<<1)+(b&1);
                        if(rec[type].second-rec[type].first<b-a)rec[type]=que.front();
                        for(int h = 0;h<4;h++)if(rec[h].first<cnt_i&&rec[h].second<cnt_j)ready[h] = rec[h].second-rec[h].first;
                        type = ((~cnt_i&1)<<1)+(cnt_j&1);
                        if(cnt_i-cnt_j+ready[type]>ans){
                            ans = cnt_i-cnt_j+ready[type];
                        }
                        que.pop();
                    }
                    que.push({cnt_i,cnt_j});
                }
            }
        }
        return ans;
    }
};