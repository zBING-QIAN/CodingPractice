#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int size1 = str1.size(),size2 = str2.size();
        vector<vector<int>> dp(size2+1,vector<int>(size1+1,0)),dp_from(size2+1,vector<int>(size1+1,0));// 0 down,1 left,2 diag
        for(int i=0;i<=size1;i++)dp_from[0][i]=1;
        for(int i=1;i<=size2;i++){
            for(int j=1;j<=size1;j++){
                if(str1[j-1]==str2[i-1]){dp[i][j] = dp[i-1][j-1]+1;dp_from[i][j] = 2;}
                if(dp[i][j]<dp[i][j-1]){
                    dp[i][j] = dp[i][j-1];dp_from[i][j] = 1;
                }
                if(dp[i][j]<dp[i-1][j]){
                    dp[i][j] = dp[i-1][j];dp_from[i][j] = 0;
                }
            }
        }
        string ans="" ;
        for(int i=size2,j=size1;i!=0||j!=0;){
            if(dp_from[i][j] == 2){
                i--,j--;
                ans.push_back(str2[i]);
            }else{
                if(dp_from[i][j]==1){
                    j--;ans.push_back(str1[j]);
                }
                
                if(dp_from[i][j]==0){
                    i--;ans.push_back(str2[i]);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};