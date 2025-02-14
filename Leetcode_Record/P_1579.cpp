#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lead(int cur,vector<int>&sid){
        vector<int> tmp;
        while(sid[cur]!=cur){tmp.push_back(cur);cur= sid[cur];}
        for(auto &t:tmp){
            sid[t] = cur;
        }
        return cur;
    }
    bool merge(int a,int b, vector<int> &sid){
        int la = lead(a,sid), lb = lead(b,sid);
        if(la==lb)return 1;
        sid[lb] = la;return 0;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> sid(n+5);for(int i=0;i<=n;i++)sid[i] = i;
        int ans = 0;
        for(auto &e:edges){
            if(e[0]==3){
                ans+=merge(e[1],e[2],sid);
            }
        }
        // cout<<"common end\n";
        vector<int> sid_a = sid,sid_b = sid;
        for(auto &e:edges){
            if(e[0]==1){ans+=merge(e[1],e[2],sid_a);}
        }
        // cout<<"a end\n";/
        for(auto &e:edges){
            if(e[0]==2){ans+=merge(e[1],e[2],sid_b);}
        }
        // cout<<ans<<endl;
        int lead_a = lead(1,sid_a),lead_b = lead(1,sid_b);
        for(int i=2;i<=n;i++){
            if(lead(i,sid_a)!=lead_a)return -1;
            if(lead(i,sid_b)!=lead_b)return -1;
        }
        return ans;
    }
};