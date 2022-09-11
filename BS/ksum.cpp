#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long long l=a[0]+b[0],r=a.back()+b.back();
    while(l<r){
        long long mid =(l+r)>>1;
        long long tmp=0;
        for(int i=1,j=n;i<=n && j>0 && tmp<k;i++){
            for(;j;j--){
                if(a[i-1]+b[j-1]<=mid){tmp+=j;break;}
            }
        }
        if(tmp>=k)r = mid;
        else l = mid+1;
    }
    cout<<l<<endl;
    return 0;
}