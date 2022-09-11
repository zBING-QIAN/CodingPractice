#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long l=1,r=n*n;
    while(l<r){
        long long mid =(l+r)>>1;
        long long tmp=0;
        for(long long i=1,j=n;i<=n && j>0 && tmp<k;i++){
            for(;j;j--){
                if(i*j<=mid){tmp+=j;break;}
            }
        }
        if(tmp>=k)r = mid;
        else l = mid+1;
    }
    long long ans = 1e10;
    for(int i = 1;i<=n;i++){
        long long tmp = l/i;
        if(tmp*i<l){tmp++;}
        if(tmp<=n&&ans>tmp*i)ans = tmp*i;
    }
    cout<<l<<endl;
    return 0;
}