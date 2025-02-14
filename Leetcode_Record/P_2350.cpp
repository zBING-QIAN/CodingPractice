#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        vector<bool> get(k+1,0);
        int ans=0;
        for(int i=0,cnt=0;i<rolls.size();i++){
            if(!get[rolls[i]]){
                cnt++;get[rolls[i]]=1;
                if(cnt==k){
                    ans++;cnt=0;
                    for(int j=0;j<=k;j++)get[j]=0;
                }
            }
        }
        return ans+1;
    }
};