#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> table,cnt; 
    vector<vector<bool>> link;
    bool issq(int n){
        for(long long i=0;i*i<=n;i++){
            if(i*i==n)return true;
        }
        return 0;
    }
    int dfs(int cur){
        cnt[cur]--;assert(cnt[cur]>=0);
        bool end = 1;
        int out = 0;
        for(int i=0;i<table.size();i++){
           if(cnt[i]>0){
               if(link[i][cur])out += dfs(i);
               end=0;
           }
        }
        cnt[cur]++;
        
        if(end)return 1;
        return out;
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        table.push_back(nums[0]);cnt.push_back(1);
        for(int i=1;i<nums.size();i++){
            if(table.back()==nums[i])cnt.back()++;
            else {table.push_back(nums[i]);cnt.push_back(1);}
        }
        link.resize(table.size(),vector<bool>(table.size(),0));
        for(int i=0;i<table.size();i++){
            for(int j=i;j<table.size();j++){
                if(issq(table[i]+table[j])){
                    link[i][j] = 1;link[j][i] = 1;  
                }
            }
        }
        int ans = 0;
        for(int i=0;i<table.size();i++){
            ans +=dfs(i);
        }
        return ans;
    }
};