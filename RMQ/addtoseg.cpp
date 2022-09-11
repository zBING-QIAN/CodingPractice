#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,p;cin>>n>>m;for(p=1;p<n;p<<=1);
    vector<long long > seg((n+1)*4,0),lazy((n+1)*4,0);
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op == 1){
            long long  l,r,v,left,right;cin>>l>>r>>v;
            for(right = r + p,left = p + l-1;left^right^1;left>>=1,right>>=1){
                if(~left&1){
                    lazy[left^1] += v;
                }if(right&1)lazy[right^1] += v;

            }


        }else {
            int pos,tmp = 1,left = 0,right = p;cin>>pos;
            while(tmp<p){
                int mid = (left+right)>>1; 
                if(lazy[tmp]>0){
                    lazy[tmp*2]+=lazy[tmp];lazy[tmp*2+1]+=lazy[tmp];lazy[tmp] = 0;
                }
                if(pos>=mid){
                    tmp= tmp*2+1;left = mid+1;
                }else {
                    tmp<<=1;right = mid;
                }
            }
            cout<<lazy[pos+p]<<endl;
        }



    }
    return 0;
}