#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(factory.begin(),factory.end());
        sort(robot.begin(),robot.end());
        vector<int> use(factory.size(),0);
        int nxt=0;
        long long ans = 0;
        vector<int> stac;
        for(int i=0;i<robot.size();i++){
            int r = robot[i];
            
            long long left_cost = 1e13;
            while(nxt<use.size()){
                if(factory[nxt][0]<r||factory[nxt][1]==0){
                    if(use[nxt]<factory[nxt][1]){stac.push_back(nxt);}
                    nxt++;
                }
                else break;
            }
            if(stac.size()){
                // cout<<"left cost fab  "<<factory[stac.back()][0]<<" "<<stac.back()<<" "<<r<<endl;
                vector<int> use_tmp = use;
                use_tmp[stac.back()]++;
                int nxt_tmp =0;
                left_cost = 0;
                for(int j=0;j<=i;j++){
                    while(nxt_tmp<=nxt&&use_tmp[nxt_tmp]==0){nxt_tmp++;}
                    left_cost+=abs(robot[j]-factory[nxt_tmp][0]);
                    use_tmp[nxt_tmp]--;
                }
            }
            long long right_cost = 1e13;
            if(nxt<factory.size()){
                right_cost = ans+abs(factory[nxt][0]-r);//cout<<"right cost fab  "<<factory[nxt][0]<<" "<<nxt<<" "<<r<<endl;
            }
            if(right_cost<=left_cost){
                use[nxt]++;
                ans = right_cost;
                if(use[nxt]==factory[nxt][1])nxt++;
            }else {
                use[stac.back()]++;if(use[stac.back()]==factory[stac.back()][1])stac.pop_back();
                ans = left_cost;
            }
            // cout<<ans<<" "<<r <<" "<<left_cost<<" "<<right_cost<<endl;
        }
        
        return ans;
    }
};