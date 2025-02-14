#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int> &stac,vector<int> &stac_idx,int value){
        // cout<<value<<endl;
        // for(int i=0;i<stac.size();i++)cout<<stac[i]<<" ";cout<<endl;
        // for(int i=0;i<stac.size();i++)cout<<stac_idx[i]<<" ";cout<<endl;cout<<endl;
        int l=-1,r = stac.size()-1;
        while(l<r){
            int mid = (l+r+1)>>1;
            if(stac[mid]<=value){
                r = mid-1;
            }else{
                l = mid;
            }
        }
        if(l<0){return -1;}
        return stac_idx[l];
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> stac,stac_idx;
        vector<int> ans(queries.size());
        vector<vector<int>> ask(heights.size(),vector<int>()),order(heights.size(),vector<int>());
        for(int i=0;i<queries.size();i++){
            auto q = queries[i];
            if(q[0]<q[1])swap(q[0],q[1]);
            else if (q[0]==q[1]){
                ans[i] = q[0];continue;
            }
            int idx = q[0];
            ask[idx].push_back(heights[q[1]]);
            order[idx].push_back(i);
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(stac.size()&&stac.back()<=heights[i]){
                stac.pop_back();stac_idx.pop_back();
            }
            stac.push_back(heights[i]);stac_idx.push_back(i);
            for(int j=0;j<ask[i].size();j++){
                ask[i][j]=search(stac,stac_idx,ask[i][j]);
            }
            
        }


        for(int i=0;i<ask.size();i++){
            for(int j=0;j<ask[i].size();j++){
                ans[order[i][j]] = ask[i][j];
            }
        }
        return ans;
    }
};