#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rec,cnt,sum;
    vector<vector<int>>edge;
    
    
    void dfs(int cur){//cout<<"dfs"<<endl;
        for(auto &to :edge[cur]){
            if(rec[to]==-1){
                rec[to]=cur;
                dfs(to);
            }
        }
        int s=0,c=1;
        for(auto &to:edge[cur]){
            if(rec[to]==cur){
                c+=cnt[to];
                s+=sum[to]+cnt[to];
            }
        }
        cnt[cur]=c;sum[cur]=s;
    }
    void dfs2(int cur,int s,int c){//cout<<"dfs2 "<<cur<<" "<<s<<" "<<c<<endl;
        sum[cur]+=s+c;
        cnt[cur]+=c;
        // assert(cnt[cur]==edge.size());
        s = sum[cur];
        c = cnt[cur];
        for(auto &to:edge[cur]){
            if(rec[to]==cur){
                int ctmp =c- cnt[to];
                int stmp =s- (sum[to]+cnt[to]);
                dfs2(to,stmp,ctmp);
            }
        }
        
        
    }
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        rec.resize(n,-1);cnt.resize(n,1);sum.resize(n,0);
        edge.resize(n,vector<int>());
        for(auto &e:edges){
            edge[e[0]].push_back(e[1]);edge[e[1]].push_back(e[0]);
        }
        rec[0]= -2;
        dfs(0);
        dfs2(0,0,0);
        return sum;
    }
};