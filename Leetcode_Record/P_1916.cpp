#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mem_size;
    long long mod = 1e9+7;
    int inv(long long e){
        long long out=1;
        for(int t = mod-2;t>0;t>>=1,e=(e*e)%mod){
            if(t&1)out = (out*e)%mod;
        }
        return int(out);
    }
    // map<int,int> inv_table;
    vector<long long> inv_bar_table;
    vector<long long> bar_table;
    vector<vector<int>> link;
    vector<int> rec,sum;
    void setup(int n){
        mem_size = n;
        bar_table.resize(mem_size+1,1);
        inv_bar_table.resize(mem_size+1,1);
        rec.resize(mem_size,0);
        sum.resize(mem_size,0);
        link.resize(mem_size,vector<int>());
        for(int i=1,bar =1;i<mem_size+1;i++){bar_table[i] = (bar_table[i-1]*i)%mod;}
        for(int i=2;i<inv_bar_table.size();i++)inv_bar_table[i] = inv(bar_table[i]);
    }
    void dfs(int id){
        for(int i=0;i<link[id].size();i++){
            dfs(link[id][i]);
            sum[id]+=sum[link[id][i]];
        }
        long long tmp=1;
        //calc comb
        for(auto &n :link[id]){
            tmp = (tmp*rec[n])%mod;  
        }
        tmp = (tmp*bar_table[sum[id]])%mod;
        for(auto &n:link[id]){
            tmp = (tmp*inv_bar_table[sum[n]])%mod;
        }
        rec[id]=tmp;
        sum[id]++;
    }

    int waysToBuildRooms(vector<int>& prevRoom) {

        setup(prevRoom.size());
        for(int i=1;i<mem_size;i++)link[prevRoom[i]].push_back(i);
        dfs(0);
        return rec[0];
    }
};