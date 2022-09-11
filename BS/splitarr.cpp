#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,K;cin>>N>>K;
    vector<long long> w(N);
    long long r=0,l =0;
    for(int i=0;i<N;i++){
        cin>>w[i];r += w[i];l = max(w[i],l);
    }
    while(l<r){
        long long mid = (l+r)>>1;
        long long tmp=0;
        int ktmp = K;
        for(int i=0;i<N;i++){
            if(tmp+w[i]>mid){
                tmp = w[i];ktmp--;
                if(ktmp<=0)break;
            }else tmp+=w[i];
        }
//cout<<mid<<" "<<ktmp<<" ";
        if(ktmp<=0)l = mid+1;
        else r = mid;
    }
    cout<<l<<endl;

    return 0;
}