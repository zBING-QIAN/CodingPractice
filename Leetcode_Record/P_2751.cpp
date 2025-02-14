#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> stac;
        vector<int> idx(positions.size());for(int i=0;i<positions.size();i++)idx[i] = i;
        sort(idx.begin(),idx.end(),[&](auto a,auto b){return positions[a]<positions[b];});
        for(auto a:idx){
            if(directions[a] == 'L'){
                while(stac.size()&&healths[a]){
                    cout<<healths[stac.back()]<<endl;
                    if(directions[stac.back()]=='R'){
                        if(healths[a]>healths[stac.back()]){
                            healths[a]--;healths[stac.back()]=0;
                        }
                        else {
                            if(healths[a]<healths[stac.back()]){healths[stac.back()]--;}   
                            else healths[stac.back()] = 0;
                            healths[a]=0;
                        // cout<<healths[stac.back()]<<" "<<healths[a]<<endl;
                        }
                    }
                    if(healths[stac.back()]==0)stac.pop_back();
                }
            }else{
                stac.push_back(a);
            }
        }
        vector<int>ans;
        for(int i=0;i<healths.size();i++)if(healths[i]>0)ans.push_back(healths[i]);
        return ans;
    }
};