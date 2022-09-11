#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,p;cin>>n;for(p = 1;p<n;p<<=1);
    vector<long long> seg(4*n+4,0);
    for(int i=0;i<n;i++){
        cin>>seg[i+p];if(i&1)seg[i+p] = -seg[i+p];
    }
    for(int i=p-1;i>0;i--)seg[i] = seg[i*2]+seg[i*2+1];
    cin>>m;
    for(int i=0;i<m;i++){
        int op,a,b;
        cin>>op>>a>>b;
        if(op){
            long long ans =0;a--,b--;
            for(int left = a+p-1,right = b+p+1;left^right^1;left>>=1,right>>=1){
                if(~left&1)ans += seg[left^1];
                if(right&1)ans += seg[right^1];
            }
            if(a&1)ans *= -1;
            cout<<ans<<endl;
        }else {a--;
            if(a&1)b*= -1;
            a+=p;
            int dif = b - seg[a];
            while(a>1){
                seg[a] += dif;a>>=1;
            }
            //cout<<" new seg  ";for(int j= 1;j<4*n;j++)cout<<seg[j]<<" ";cout<<endl;

        }

    }

    return 0;
}
