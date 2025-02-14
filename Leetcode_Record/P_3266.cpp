#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long powd(double a,int multiplier){
        
        long long tmp = round(a);
        int mod = 1e9+7;
        long long out =1,mul=multiplier;
        while(tmp){
            if(tmp&1){
                out*=mul;out%=mod;
            }
            tmp>>=1;
            mul *=mul;mul%=mod;
        }
        return out;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        set<pair<double,int>> table;
        vector<double>rec;
        if(multiplier==1)return nums;
        for(int i=0;i<nums.size();i++){
            rec.push_back(log(nums[i])/log(multiplier));
            table.insert({rec.back(),i});
        }
        int mod = 1e9+7;
        int ktmp=k;
        while(ktmp>0){
            if((table.rbegin()->first-table.begin()->first<=1)&&ktmp>2*nums.size()){
                int mtmp = ktmp/nums.size()-1;
                ktmp%=nums.size();
                ktmp+=nums.size();
                set<pair<double,int>> table_tmp;
                for(auto &[a,b]:table)table_tmp.insert({a+mtmp,b});
                table=table_tmp;
            }
            else {
                auto [a,b] = (*table.begin());
                table.erase(table.begin());
                table.insert({a+1,b});
                ktmp--;
            }
        }
        vector<int> outs(nums.size(),0);
        for(auto &[a,b]:table){
            int tmp = nums[b];
            nums[b]=(powd(a-rec[b],multiplier)*tmp)%mod;
        }
       
        return nums;
    }
};