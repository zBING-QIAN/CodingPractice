#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K;cin>>N>>K;
    vector<int> stall(N);for(int i=0;i<N;i++)cin>>stall[i];
    int l = 1,r =1e9;
    while(l<r){
        int mid = (l+r)>>1;
        int tmp = 0,cur = stall[0];
        for(int i=1;i<N;i++){
            if(stall[i]-cur>=mid)tmp++,cur = stall[i];
            if(tmp==K-1)break;
        }
        if(tmp==K-1){l = mid+1;}
        else r = mid;
    }cout<<r-1;
    return 0;
}