#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int r = destination[1],c = destination[0];
        vector<vector<int>> dp(r+c+1,vector<int>(max(r,c),0));
        for(int i=0;i<dp.size();i++){dp[i][0]=1;}
        string ans="";
        for(int n=1;n<=r+c;n++){
            for(int k=1;k<dp[0].size();k++){
                dp[n][k]=dp[n-1][k]+dp[n-1][k-1];
            }
        }
        int cnt = 0,n = r+c;
        while(n>0){
            if(r==0||(r>0&&dp[n-1][r-1]<k)){
                
                // cout<<"V ";
                // if(r)cout<<n-1<<" "<<r-1<<" "<<dp[n-1][r-1]<<" "<<k<<endl;
                if(r)k-=dp[n-1][r-1];
                ans+="V";
                c--;
            }else if(r>0){
                // cout<<"H ";
                // if(c)cout<<n-1<<" "<<c-1<<" "<<dp[n-1][c-1]<<" "<<k<<endl;
                ans+="H";
                r--;
            }
            n--;
        }
        return ans;
    }
};