#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int inv(long long v){
        long long mod_tmp = mod-2;
        long long out = 1;
        while(mod_tmp){
            if(mod_tmp&1){
                out *=v;
                out %=mod;
            }
            v = (v*v) % mod;
            mod_tmp>>=1;
        }
        return out;
    }
    int cnk(int n,int k){
        if(n<=0||k<=0)return 1;
        long long out=1,down =1;
        k = min(k,n-k);
        for(int i=1;i<=k;i++){
            out=((n-i+1)*out)%mod;
            down=(down*i)%mod;
        }
        return (out*inv(down))%mod;
    }
    int distanceSum(int m, int n, int k) {
        long long ans = 0;
        long long  mul = cnk(m*n-2,k-2);
        for(long long i=0;i<m;i++){
            for(long long j=0;j<n;j++){
                long long d=0,w = 0;
                d=((long long)(m-i-1)*(m-i)/2+(long long)(i)*(i+1)/2)%mod;
                w=((long long)(n-j-1)*(n-j)/2+(long long)(j)*(j+1)/2)%mod;
                ans+=(((d*n+w*m)%mod)*mul)%mod;
                ans%=mod;
            }   
        }
        return ans*inv(2)%mod;
    }
};