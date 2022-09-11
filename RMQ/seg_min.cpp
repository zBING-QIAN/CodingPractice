#include<bits/stdc++.h>
using namespace std;
vector<int> segTree;
int m,n,p;

void modify(int a,int v){
   
    for( a+=p;a;a>>=1){
        segTree[a] = v;
        if(segTree[a]>segTree[a^1])v = segTree[a^1];
    }
}
int query(int a,int b){
    int ans = 1e9;

    
    for(a+=p-1,b+=p+1;a^b^1;a>>=1,b>>=1){
        if(~a&1)ans = min(ans,segTree[a^1]);
        if(b&1)ans = min(ans,segTree[b^1]);
           
    }

    cout<<ans<<endl;

}




int main(){
    cin>>m>>n;
    for(p=1;p<m;p<<=1);
    segTree.resize(2*p,1e9);
    for(int i=0;i<m;i++){
        cin>>segTree[i+p];
    }
    for(int i = p-1;i;i--){
        int tmp = i*2;
        segTree[i] = min(segTree[tmp],segTree[tmp+1]);
    }
    for(int i=0;i<n;i++){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1){
            modify(a,b);
        }
        else {
            query(a,b-1);
        }
        
    }

    return 0;
}