#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int h=matrix.size(),w=matrix[0].size();
        int ans =0;
        vector<vector<int>> dp(h,vector<int>(w,0));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j] = (j>0)?dp[i][j-1]+1:1;
                    int tmpw= dp[i][j];
                    for(int k=0;k<=i;k++){
                        tmpw = min(tmpw,dp[i-k][j]);
                        ans = max(ans,tmpw*(k+1));     
                    }   
                }
                else dp[i][j] = 0;
            }
        }
        return ans;
    }
};