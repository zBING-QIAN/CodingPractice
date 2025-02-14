#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int,vector<int>>links;
        map<int,int> rec;
        int start=-1;
        for(auto &p:pairs){
            rec[p[0]]++;
            rec[p[1]]--;
            if(links.find(p[0])==links.end())links[p[0]]=vector<int>();
            links[p[0]].push_back(p[1]);
        }  
        for(auto &r : rec)if(r.second>0){start = r.first;break;}
        if(start==-1)start = pairs[0][0];
        int cnt = pairs.size();
        vector<int>stac;stac.push_back(start);
        while(stac.size()){
            int p = stac.back(),nxt =-1;
            if(links[p].size()){nxt= links[p].back();links[p].pop_back();}
            if(nxt==-1){
                if(stac.size()>1)ans.push_back({stac[stac.size()-2],stac.back()});
                stac.pop_back();
            }else{
                stac.push_back(nxt);
            }


        }
        
        reverse(ans.begin(),ans.end());
        return ans;

    }
};