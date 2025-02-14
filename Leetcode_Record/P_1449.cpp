#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> best_dist;
    int best_cnt;
    vector<int> idx;
    bool larger(vector<int> &d0,vector<int> &d1){
        for(int i=8;i>=0;i--){
            if(d0[i]==d1[i])continue;
            else return d0[i]>d1[i];
        }return 0;
    }
    void dfs(int c,int t,int target,vector<int> &cost,vector<int>&dist){
        if(target==0){
            if(c>best_cnt||(c==best_cnt&&larger(dist,best_dist))){
                best_cnt=c;
                best_dist = dist;
            }
            return;
        }
        while(t<9&&t>0&&cost[idx[t]]==cost[idx[t-1]])t++;
        if(t==9)return;
        for(int i=target/cost[idx[t]];i>=0;i--){
            dist[idx[t]]=i;
            int tmp = target-i*cost[idx[t]];
            dfs(c+i,t+1,tmp,cost,dist);
            
            dist[idx[t]]=0;
            if(best_cnt>0&&t<8){
                if(best_cnt>c+i+tmp/cost[idx[t+1]])return;
            }
        }
    }
    string largestNumber(vector<int>& cost, int target) {
        string ans="";
        idx.resize(9);
        for(int i=0;i<9;i++){idx[i]=i;}
        sort(idx.begin(),idx.end(),[&](auto &a,auto &b){return (cost[a]<cost[b])||(cost[a]==cost[b]&&a>b);});
        best_dist.resize(9,0);
        vector<int> dtmp(9,0);
        best_cnt = 0;best_dist.resize(9,0);
        dfs(0,0,target,cost,dtmp);
        if(best_cnt){
            for(int i=8;i>=0;i--){
                for(int j=0;j<best_dist[i];j++){
                    ans+=char('1'+i);
                }
            }
            return ans;
        }else return "0";

    }
};