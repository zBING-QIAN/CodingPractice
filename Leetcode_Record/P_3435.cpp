#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int cur,vector<vector<int>> &edge,vector<int> &visit,int n){
        visit[cur] = 1;
        for(int i=0;i<n;i++){
            if(edge[cur][i]){
                if(visit[i]==0){if(dfs(i,edge,visit,n))return 1;}
                else if(visit[i] == 1)return 1;
            }
        }
        visit[cur] = 2;
        return 0;
    }

    bool check_loop(vector<vector<int>> &edge,int n){
        vector<int> visit(n,0);
        for(int i=0;i<n;i++){
            if(visit[i]==0&&dfs(i,edge,visit,n))return 1;
        }
        return 0;
    }



    vector<vector<int>> supersequences(vector<string>& words) {
        map<char,int> table;
        int id =0,ans_cnt=32;
        vector<vector<int>> ans;
        for(auto w:words){
            if(table.find(w[0])==table.end())table[w[0]] = id++;
            if(table.find(w[1])==table.end())table[w[1]] = id++;
        }
        vector<vector<int>> edge(id,vector<int>(id,0));
        for(auto w:words){
            edge[table[w[0]]][table[w[1]]] = 1;
        }
        for(int i=0;i<(1<<id);i++){
            vector<int> ans_tmp(id,1);
            int i_tmp=i,rm_cnt = id;
            vector<int> rm_list;
            for(int t=id-1;i_tmp;t--,i_tmp>>=1){
                if(i_tmp&1){
                    ans_tmp[t]++;
                    rm_cnt++;
                    rm_list.push_back(t);
                    if(rm_cnt>ans_cnt)break;
                }
            }
            
            if(rm_cnt<=ans_cnt){
                vector<vector<int>> edge_tmp = edge;
                for(auto t:rm_list){
                    for(int j=0;j<id;j++){
                        edge_tmp[j][t]=0;
                        edge_tmp[t][j]=0;
                    }
                }
                if(!check_loop(edge_tmp,id)){
                    if(rm_cnt<ans_cnt){ans.clear();ans_cnt = rm_cnt;}
                    // cout<<"i "<<i<<endl;
                    // for(int h = 0;h<id;h++)cout<<ans_tmp[h]<<" ";cout<<endl;
                    
                    ans.push_back(ans_tmp);
                }
            }
            
            
        }
        vector<vector<int>> out; 
        for(auto &a:ans){
            vector<int> out_tmp(26,0);
            for(auto &c:table){
                out_tmp[c.first-'a'] = a[c.second];
            }
            out.push_back(out_tmp);
        }
        return out;
        

    }
};