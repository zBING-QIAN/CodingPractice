#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,p;cin>>N;for(p=1;p<2*N;p<<=1);
    vector<int> seg(8*N,0),pos(N+1,-1),ans(N+1,0);
    for(int i=0;i<N*2;i++){
        int tmp;
        cin>>tmp;
        if(pos[tmp] == -1)pos[tmp] = i;
        else{
            int left = pos[tmp]+p;
            while(left>1){
                if(~left&1)ans[tmp]+=seg[left^1];
                left>>=1;
            }

            tmp = pos[tmp]+p;
            while(tmp>0){
                seg[tmp]++;tmp>>=1;
            }
        }
        

    }for(int j=1;j<=N;j++)cout<<ans[j]<<" ";
    return 0;
}