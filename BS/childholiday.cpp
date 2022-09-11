#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>m>>n;
    vector<int> t(n),z(n),y(n);
    for(int i=0;i<n;i++)cin>>t[i]>>y[i]>>z[i];
    int l = 0,r = 2e9;
    while(l<r){
        int mid = (l+r)>>1;
        long long tmp = 0;
        for(int i=0;i<n;i++){
            int tt = t[i]*y[i]+z[i];
            int ttt = min(y[i],(mid - (mid/tt)*tt)/t[i]);
            tmp +=(mid/tt)*y[i]+ttt;
        }
        if(tmp>=m)r = mid;else l = mid+1;
    }
    cout<<l<<endl;
    long long tmp =0;
    for(int i=0;i<n;i++){
        int tt = t[i]*y[i]+z[i];
        int ttt = min(y[i],(l - (l/tt)*tt)/t[i]);
        int tttt = (l/tt)*y[i]+ttt;
        if(tmp + tttt<=m){cout<<tttt<<" ";tmp +=tttt;}
        else {cout<<m-tmp<<" ";tmp = m;}
    }
    return 0;
}