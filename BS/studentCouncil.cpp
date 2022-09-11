#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>k>>n;
    vector<int> g(n);
    for(int i=0;i<n;i++)cin>>g[i];
    long long l = 0,r = 1e13;
    while(l<r){
        long long mid = (l+r)>>1, tmp = mid*k;
        for(int i=0,j=0;i<k;i++){
            for(;j<n;j++){
                long long tt = (mid>g[j])?g[j]:mid;
                tmp-=tt;
                if(tmp<=0)break;
            }
            if(tmp<=0)break;
        }
        if(tmp<=0){
            l = mid+1;
        }else {
            r = mid;
        }
    }cout<<l-1;

    return 0;
}