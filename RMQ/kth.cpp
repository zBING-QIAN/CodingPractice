#include<bits/stdc++.h>
using namespace std;
int m,n,p;
vector<int> seg_count;
void modify(int a){
    int v = 1-seg_count[a+=p];
    for(;a;a>>=1){
        seg_count[a] = v;
        v = seg_count[a]+seg_count[a^1];
    }
}
void query(int a){
    int f = 1;
    for(;f<p;){
        if(seg_count[f<<1]>=a)f<<=1;
        else {a-=seg_count[f<<1];f =1+(f<<1);}
    }
    cout<<f-p<<endl;
}

int main(){
    cin>>m>>n;
    for(p=1;p<m;p<<=1);
    seg_count.resize(p*2);
    for(int i=0;i<m;i++){
        cin>>seg_count[i+p];
    }
    for(int i=p-1;i;i--){
        int tmp = i<<1;
        seg_count[i] = seg_count[tmp]+seg_count[tmp+1]; 
    }
    for(int i=0;i<n;i++){
        int op,a;
        cin>>op>>a;
        if(op==1){
            modify(a);
        }else {
            query(a+1);
        }

    }
    return 0;
}