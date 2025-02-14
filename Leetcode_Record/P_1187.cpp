#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        vector<array<int,2>> rec,nxt;
        for(int i=0;i<arr2.size();i++){
            if(arr2[i]<arr1[0]){rec.push_back({arr2[i],1});}
            else break;
        }
        rec.push_back({arr1[0],0});
        for(int i=1;i<arr1.size();i++){
            int tmp = INT_MAX, j=0, k=0;
            for(;k<arr2.size();k++){
                if(arr2[k]<arr1[i]){
                    while(rec.size()>j&&rec[j][0]<arr2[k]){
                        nxt.push_back({arr2[k],rec[j][1]+1});
                        tmp = min(tmp,rec[j][1]);j++;
                    }
                }else break;
            }
            while(j<rec.size()&&rec[j][0]<arr1[i]){
                tmp = min(tmp,rec[j][1]);j++;
            }
            if(tmp!=INT_MAX){
                nxt.push_back({arr1[i],tmp});
            }
            for(;k<arr2.size();k++){
                while(rec.size()>j&&rec[j][0]<arr2[k]){
                    nxt.push_back({arr2[k],rec[j][1]+1});
                    tmp = min(tmp,rec[j][1]);j++;
                }
                
            }
        
            
            rec= nxt;nxt.clear();
            if(rec.size()==0)return -1;
        }
        int ans =arr1.size();
        for(int i=0;i<rec.size();i++)ans = min(ans,rec[i][1]);
        return ans;
    }
};