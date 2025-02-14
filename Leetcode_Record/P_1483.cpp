#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:

    vector<vector<int>> anc;
    void dfs(int cur,vector<int> &stac,vector<vector<int>>&son){
        stac.push_back(cur);
        int sz = stac.size();
        vector<int> anc_tmp;
        for(int gap =1;gap<=sz;gap<<=1){
            anc_tmp.push_back(stac[sz-gap]);
        }
        for(auto s:son[cur])anc[s] = anc_tmp;
        anc_tmp.clear();
        for(auto s:son[cur])dfs(s,stac,son);
        stac.pop_back();
    }
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> son(n,vector<int>());
        anc.resize(n,vector<int>());
        int rt = 0;
        for(int i=0;i<n;i++){
            if(parent[i]!=-1){
                son[parent[i]].push_back(i);
            }else rt=i;
        }
        vector<int> stac;
        dfs(rt,stac,son);
    
    }
    
    int getKthAncestor(int node, int k) {
        int cur = node;
        vector<int> stac;
        for(int i=0,b = 1;b<=k;b<<=1,i++){
            if(b&k)stac.push_back(i);
        }
        while(stac.size()){
            if(anc[cur].size()>stac.back())cur = anc[cur][stac.back()];
            else return -1;
            stac.pop_back();
        }
        return cur;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */