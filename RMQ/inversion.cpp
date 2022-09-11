#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

int main(){
    int N,p = 1;
    vector<int> seg(MAXN*4,0);
    cin>>N;
    for(;p<N;p<<=1);
    for(int i=0;i<N;i++){
        int tmp,buf;
        cin>>buf;tmp = buf+p-1;
        while(tmp>0){seg[tmp]++;tmp>>=1;}
        tmp = buf+p-1;
        int ans = 0;
        while(tmp>1){
            if(~tmp&1)ans+=seg[tmp^1];
            tmp>>=1;
        }

        cout<<ans<<" ";
    }cout<<endl;
    
    return 0;
}