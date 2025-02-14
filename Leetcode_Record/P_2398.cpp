#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        map<int,int> max_rec;
        long long sum = 0;
        int ans =0;
        for(int i=0,j=0;j<chargeTimes.size();j++){
            max_rec[chargeTimes[j]]++;
            sum += runningCosts[j];
            long long max_charge = (max_rec.size()==0)?0:max_rec.rbegin()->first;
            int k = j-i+1;
            while(sum*k+max_charge>budget){
                sum-=runningCosts[i];
                // cout<<max_rec[chargeTimes[i]]<<endl;
                max_rec[chargeTimes[i]]--;
                // cout<<"erase maxrec chargetimes "<<chargeTimes[i]<<" "<<max_rec[chargeTimes[i]]<<endl;
                // for(auto &m:max_rec)cout<<m.first<<" "<<m.second<<endl;
                if(max_rec[chargeTimes[i]]==0){
                    max_rec.erase(chargeTimes[i]);
                    // cout<<"erase "<<chargeTimes[i]<<endl;
                }
                i++;k--;max_charge = (max_rec.size()==0)?0:max_rec.rbegin()->first;
            }
            // cout<<i<<" "<<j<<" "<<sum<<" "<<max_charge<<" "<<sum*k+max_charge<<" "<<budget<<endl;
            ans = max(ans,k);
            
        }
        return ans;   
    }
};