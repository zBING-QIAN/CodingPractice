#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        long long ans=0;
        vector<long long> dif(n-1,0);
        long long base = 1,partial_sum = 0;
        reverse(batteries.begin(),batteries.end());
        for(int i=1;i<batteries.size();i++){
            if(i<n){
                dif[i-1] = batteries[i-1]-batteries[i];
            }else{
                partial_sum+=batteries[i];
                
                while(dif.size()&&partial_sum>=dif.back()*base){
                    partial_sum-=dif.back()*base;
                    dif.pop_back();base++;
                }
            }
        }
        cout<<base<<" "<<partial_sum<<endl;
        return batteries[n-base]+(partial_sum/base);
    }
};