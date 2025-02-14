#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 


    int findIntegers(int n) {
        int rsb = 1;
        vector<int> rec0(32,0),rec1(32,0);rec0[0]=1,rec1[0]=1;
        for(int i=1;i<32&&(1<<i)<=n;i++){
            rec0[i] = rec1[i-1]+rec0[i-1];
            rec1[i] = rec0[i-1];
            rsb = i;
        }
        
        int ans = 0;
        cout<<rsb<<endl;
        for(;rsb>=0;rsb--){
            if((1<<rsb)&n){
                if((1<<(rsb+1))&n){
                    if(rsb){ans+=rec0[rsb-1]+rec1[rsb-1];return ans;}
                }
                else{
                    ans+=rec0[rsb];
                }
            }
        }
        return ans+1;
    }
};