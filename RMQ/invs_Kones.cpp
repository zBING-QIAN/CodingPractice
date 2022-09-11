#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r,v,count;
};
vector<node> segtree;
int Coun = 0;
vector<long long> arr;
void build(int l,int r,int v){
    segtree[v].count = segtree[v].v = 0;
    if(l==r){return;}
    int mid = (l+r)>>1;
    segtree[v].l = ++Coun;segtree[v].r = ++Coun;
    build(l,mid,segtree[v].l);
    build(mid+1,r,segtree[v].r);  
}
void add(int l,int r,int left,int right,int cur){
    if(l<=left&&r>=right){
        segtree[cur].v^=1 ;segtree[cur].count = right-left+1-segtree[cur].count;
        return; 
    }
    int mid = (left+right)>>1;
    if(segtree[cur].v){
        segtree[segtree[cur].l].v ^=1;segtree[segtree[cur].r].v ^=1;
        segtree[segtree[cur].l].count = ((right-left+1)>>1)-segtree[segtree[cur].l].count;
        segtree[segtree[cur].r].count = ((right-left+1)>>1)-segtree[segtree[cur].r].count;
        segtree[cur].v = 0;
    }
    if(l<=mid)add(l,r,left,mid,segtree[cur].l);
    if(r>mid)add(l,r,mid+1,right,segtree[cur].r);
    segtree[cur].count = segtree[segtree[cur].l].count+segtree[segtree[cur].r].count;
}
void search(int l,int r,int cur,int pos){
   // cout<<"k = "<<pos<<" left,right: "<<l<<" "<<r<<" seg count "<<segtree[cur].count<<endl;
    if(l == r){cout<<l<<endl;return;}
    if(segtree[cur].v){
        segtree[segtree[cur].l].v^=1;segtree[segtree[cur].r].v^=1;
        segtree[segtree[cur].l].count = ((r-l+1)>>1)-segtree[segtree[cur].l].count;
        segtree[segtree[cur].r].count = ((r-l+1)>>1)-segtree[segtree[cur].r].count;
        segtree[cur].v=0;
    }
    int mid = (l+r)>>1;
    if(pos<=segtree[segtree[cur].l].count){
        search(l,mid,segtree[cur].l,pos);
    }
    else search(mid+1,r,segtree[cur].r,pos-segtree[segtree[cur].l].count);//cout<<"go right";

}
int main(){
    int n,m,p,flag=0;
    cin>>n>>m;for(p=1;p<n;p<<=1);
    segtree.resize(2*p);arr.resize(p+1,0);
    build(0,p-1,0);
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            int l,r;;cin>>l>>r;
            add(l,r-1,0,p-1,0);
        }else{
            int l;cin>>l;
            search(0,p-1,0,l+1);
        }
    }
    return 0;
}