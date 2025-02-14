#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int cur,vector<vector<int>> &link,vector<int> &rec){
        int depth = 0;
        for(auto &to:link[cur]){
            
            if(rec[to] == -1){return -1;}
            else if(rec[to] == -2){
                rec[to] = -1; 
                if(dfs(to,link,rec)<0){return -1;}
            }
            depth = max(depth,rec[to]);
        }
        rec[cur] = depth+1;
        return depth+1;
    }


    vector<int> order(int k,vector<vector<int>> &cond){
        vector<int> rec(k+1,-1);
        vector<vector<int>> link(k+1,vector<int>());
        for(auto &c:cond){
            int a = c[0],b=c[1];
            link[a].push_back(b);
            rec[b] = -2;
        }
        int no_loop =-1;
        for(int i=1;i<rec.size();i++){
            if(rec[i]==-1){
                no_loop= dfs(i,link,rec);
                if(no_loop<0){break;}
            }
        }
        for(int i=1;i<=k;i++){
            if(rec[i]<0){
                no_loop= -1;
                break;
            }
        }
        vector<int> out_order(k+1,0);
        cout<<no_loop<<endl;
        if(no_loop>=0){
            vector<int> idx(k,0);for(int i=1;i<=k;i++)idx[i-1]=i;    
            sort(idx.begin(),idx.end(),[&](auto a,auto b){
                return rec[a]>rec[b];
            });
            for(int i=k-1;i>=0;i--){
                out_order[idx[i]] = i;
            }
            return out_order;
        }
        else{return vector<int>();}
    }


    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> out(k,vector<int>(k,0));
        vector<int> order_row = order(k,rowConditions);
        if(order_row.size()==0)return {};
        vector<int> order_col = order(k,colConditions);
        if(order_col.size()){
            for(int i=1;i<=k;i++){out[order_row[i]][order_col[i]]=i;}
            return out;
        }
        return {};
    }
};