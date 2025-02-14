#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mod = 1e9+7;
    int checkRecord(int n) {
        long long e=1,ell=0,el=1;
        long long ea=1,eall=0,eal=0;
        for(int i=2;i<=n;i++){
            int eatmp = ea;
            ea = (eal+eall+ell+el+e+ea)%mod;
            eall = eal;// should same as (ell*(i-2))%mod;
            eal = eatmp;// should same as el*(i-1))%mod;
            
            int etmp = (e)%mod;
            e = (ell+el+e)%mod;
            ell= el;
            el = etmp;
            
            // printf("%d %d %d %d %d %d \n",e,el,ell,ea,eal,eall);
        }
        return (e+ell+el+ea+eall+eal)%mod;
    }
};