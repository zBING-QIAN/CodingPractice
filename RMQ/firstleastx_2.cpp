#include<bits/stdc++.h>
using namespace std;
int m,n,p;
vector<int> segTree;
void modify(int a,int b){
    for(a+=p;a;a>>=1){
        segTree[a] = b;
        b = max(segTree[a],segTree[a^1]);
    }
}
void query(int a,int b){
    
    int t= p+b-1;
    for(;t;t>>=1){
        if(~t&1&&segTree[t+1]>=a){
            t++;break;
        }
    }
    
    for(;t<p;){
        t<<=1;
        if(segTree[t]<a)t++;
    }
    if(t-p<b||segTree[t]<a){cout<<-1<<endl;}
    else cout<<t-p<<endl;
}



int main(){
    cin>>m>>n;
    for(p=1;p<m;p<<=1);
    segTree.resize(2*p,-1);
    for(int i=0;i<m;i++){
        cin>>segTree[i+p];
    }
    for(int i=p-1;i;i--){
        int tmp = i<<1;
        segTree[i]=max(segTree[tmp+1],segTree[tmp]);
    }
    for(int i=0;i<n;i++){
        int op,a,b;
        cin>>op>>a>>b;
        if(op == 1){
            modify(a,b);
        }else{
            query(a,b);
        }
    }

    return 0;
}