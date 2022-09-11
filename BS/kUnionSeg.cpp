#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<array<long long,2>> p;
    for(int i=0;i<n;i++){
        int tmp1,tmp2; cin>>tmp1>>tmp2;
        p.push_back({tmp1,tmp2});
    }
    long long l = -2*1e9,r = 2*1e9;
    while(l<r){
        long long mid = (l+r)/2;
        long long tmp = 0;
        for(int i=0;i<n;i++){
            if(mid>p[i][0]){
                if(mid>p[i][1]){
                    tmp+=p[i][1]-p[i][0]+1;
                }else{
                    tmp+=mid-p[i][0];
                }
            }
            if(tmp>k)
                break;
        }
        if(tmp>k){
            r = mid-1;
        }else {
            l = mid;
        }
        if(l+1==r){
            tmp = 0;
            for(int i=0;i<n;i++){
                if(r>p[i][0]){
                    if(r>p[i][1]){
                        tmp+=p[i][1]-p[i][0]+1;
                    }else{
                        tmp+=r-p[i][0];
                    }
                }
                if(tmp>k){r--;break;}
            }
            l = r;
        }
    }
    cout<<l;
    return 0;
}