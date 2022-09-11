#include<bits/stdc++.h>
using namespace std;
int m,n,p;
vector<long long>segTree;

void add(int pos,int v){
    pos+=p;
    while(pos>0){
        segTree[pos]+=v;
        pos>>=1;
    }
}

long long query(int a,int b){
    long long ans =0;
    //for(a+=p-1,b+=p+1;b-a>1;a>>=1,b>>=1)
    for(a+=p-1,b+=p+1;a^b^1;a>>=1,b>>=1){ 
        if(~a&1)ans+=segTree[a^1];
        if(b&1)ans+=segTree[b^1];
    }
    return ans;
}

long long sum(int a){
    if(a == m)return segTree[1];
    long long ans = 0;
    a+=p;
    for(;a^1;a>>=1){
        if(a&1)ans+=segTree[a-1];
    }
    return ans;
}
long long query_1(int a,int b){
    return sum(b+1)-sum(a);
}
int main(){
    cin>>m>>n;
    p =1;
    while(p<m){
        p<<=1;
    }
    segTree.resize(2*p+5,0);
    for(int i=0;i<m;i++){
        cin>>segTree[p+i];
    }
    for(int i=p-1;i;i--){
        int tmp = i*2;
        segTree[i]=segTree[tmp]+segTree[tmp+1];
    }

    for(int i=0;i<n;i++){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1){
            add(a,b-segTree[p+a]);
        }else if(op == 2){
            cout<<query_1(a,b-1)<<endl;
        }

    }
    return 0;
}