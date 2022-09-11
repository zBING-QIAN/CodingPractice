#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<array<double,2>> arr;
    for(int i=0;i<n;i++){
        double tmp1,tmp2;cin>>tmp1>>tmp2;arr.push_back({tmp1,tmp2});
    }
    double l=0,r = 1e12;
    for(int t=0;t<100;t++){
        double mid = (l+r)/2;
        vector<double> rec(n);
        for(int i=0;i<n;i++)rec[i] = arr[i][0]-mid*arr[i][1];
        // sellect max k
        sort(rec.begin(),rec.end());
        double tmp = 0;
        for(int i=n-1;i>=n-k;i--){
            tmp+=rec[i];
        }
        if(tmp>0){
            l = mid;
            // l = mid+tmp/k;
        }else {
            r = mid;
            // l = max(l,mid+tmp/k);
        }

    }
    cout<<setprecision(10)<<l<<endl;
    return 0;
}