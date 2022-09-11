#include<bits/stdc++.h>
using namespace std;
int m,n,p;
vector<int> segTree;
void update(int a,int v){
    for(a+=p;a;a>>=1){
        segTree[a] = v;
        v = max(segTree[a],segTree[a^1]);
    }
}

void query(int a){
    if(a>segTree[1]){cout<<-1<<endl;return;}
    int t = 1;
    for(;t<p;){
        if(segTree[t<<1]>=a)t<<=1;
        else{t<<=1;t++;}
    }
    cout<<t-p<<endl;
}

int main(){
    cin>>m>>n;
    for(p=1;p<m;p<<=1);
    segTree.resize(p<<1,0);
    for(int i=0;i<m;i++){
        cin>>segTree[p+i];
    }
    for(int i=p-1;i;i--){
        int tmp = i<<1;
        segTree[i] = max(segTree[tmp],segTree[tmp+1]);
    }
    for(int i=0;i<n;i++){
        int op,a,b;
        cin>>op;
        if(op == 1){
            cin>>a>>b;
            update(a,b);
        }else {
            cin>>a;
            query(a);
        }

    }

    return 0;
    
}