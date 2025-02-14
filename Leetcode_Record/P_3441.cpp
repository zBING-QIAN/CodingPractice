#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string minCostGoodCaption(string caption) {
        if(caption.size()<3)return "";
        int n = caption.size()+1;
        vector<array<int,3>> cost(n,{1000000000,1000000000,1000000000});
        cost[0] = {0,0,0};
        vector<array<char,3>> ch(n,{0,0,0});
        vector<char>arr(6,0);
        for(int i = 0;i<n;i++){
            int cost_min = min(cost[i][0],min(cost[i][1],cost[i][2]));
            for(int t = 1,nxt = i+t;t<6&&nxt<n;nxt++,t++){
                arr[t-1] = caption[nxt-1];
                for(int h = t-1;h;h--){
                    if(arr[h]<arr[h-1])swap(arr[h],arr[h-1]);
                    else break;
                }
                if(t>2){
                    int cost_tmp = 0;
                    int mid = (t-1)>>1;
                    for(int k=0;k<t;k++){cost_tmp+=abs(arr[k]-arr[mid]);}
                    cost[nxt][t-3] = cost_tmp+cost_min;
                    ch[nxt][t-3] = arr[mid];         
                }
            }
        }
        vector<bool> good_path(n,0);good_path[n-1] = 1;
        for(int i=n-1;i>0;i--){
            if(good_path[i]==0){
                for(int j=0;j<3;j++)ch[i][j] = 0;
            }
            else{
                int cost_min = min(cost[i][0],min(cost[i][1],cost[i][2]));
                for(int j=0;j<3;j++){
                    if(cost_min == cost[i][j]){
                        good_path[i-j-3] = 1;
                    }
                    else ch[i][j] = 0;
                }
            }
            
        }
        string ans = string(n-1,'z'+1);
        for(int i=0,cnt =0;i<n-1;i++){
            bool skip = 1;
            for(int j=0;j<3&&skip;j++){
                if(i==0||ch[i][j]==ans[i-1]){
                    skip=0;
                }
            }
            if(skip){
                for(int j=3;j<6&&i+j<n;j++){
                    ch[i+j][j-3] = 0;
                }    
                continue;
            }

            int jj=0;
            char c = ans[i];
            
            for(int j=3;j<6;j++){
                if(i+j<n&&ch[i+j][j-3]&&ch[i+j][j-3]<=c){
                    c = ch[i+j][j-3];
                    jj = j;
                }
            }
            for(int j=3;j<6;j++){
                if(i+j<n&&ch[i+j][j-3]!=c){
                    ch[i+j][j-3] = 0;
                }
            }
            for(int j=0;j<jj;j++){
                ans[i+j] = c;
            }
        }
        return ans;
    }
};