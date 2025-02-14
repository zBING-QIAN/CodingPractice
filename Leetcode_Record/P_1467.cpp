#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double total,equal;
    int Cnxm[7][7];
    void dfs(int cnt,int n,vector<int> &dist,vector<int> &balls)
    {
        if(cnt==n){
            double samp=1;
            int k0=0,k1=balls.size()-dist.size();
            for(int i=0;i<dist.size();i++){
                if(dist[i]>0)k0++;
                if(dist[i]<balls[i])k1++;
                samp*=Cnxm[balls[i]][dist[i]];
            }
            if(k1==k0)equal+=samp;
            total+=samp;

        }
        else if(dist.size()<balls.size()){
            int k = dist.size();
            for(int i=0;i<=balls[k];i++){
                if(cnt+i<=n){    
                    dist.push_back(i);
                    dfs(cnt+i,n,dist,balls);
                    dist.pop_back();
                }
            }
        }
    }

    double getProbability(vector<int>& balls) {
        total=0,equal=0;
        int bar[7];bar[0]=1;
        for(int i=1;i<7;i++){bar[i]=bar[i-1]*i;}
        for(int i=0;i<=6;i++){
            for(int j=0;j<=i;j++){
                Cnxm[i][j] = bar[i]/bar[j]/bar[i-j];
            }
        }
        int tmp = 0;
        for(auto b:balls){tmp+=b;assert(b>0);}
        vector<int>dist;
        dfs(0,tmp>>1,dist,balls);
        return equal/total;
    }
};