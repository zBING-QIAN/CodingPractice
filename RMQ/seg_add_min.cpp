#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    long long v,lazy;
};
vector<node> seg;
int Coun;
void build(int l,int r,int cur){
    if(l==r){ seg[cur].v = 0,seg[cur].lazy = 0;return ;}
    int mid = (l+r)>>1;
    seg[cur].l = ++Coun;seg[cur].r = ++Coun;
    build(l,mid,seg[cur].l);
    build(mid+1,r,seg[cur].r);
    seg[cur].v = 0;seg[cur].lazy = 0;
}
long long search(int l,int r,int left,int right,int cur){
    if(left>=l&&right<=r){
        return seg[cur].v+seg[cur].lazy;
    }
    int mid = (left+right)>>1;
    long long small = 1e16;
    if(mid>=l)small = min(small,search(l,r,left,mid,seg[cur].l));
    if(mid<r)small = min(small,search(l,r,mid+1,right,seg[cur].r));
    return small+seg[cur].lazy;
}
void add(int l,int r,long long v,int left,int right,int cur){
    if(left>=l&&right<=r){
        seg[cur].lazy +=v;
        return;
    }
    int mid = (left+right)>>1;
    if(seg[cur].lazy!=0){
        seg[seg[cur].l].lazy+=seg[cur].lazy;
        seg[seg[cur].r].lazy+=seg[cur].lazy;
        seg[cur].lazy = 0;
    }
    if(mid>=l)add(l,r,v,left,mid,seg[cur].l);
    if(mid<r)add(l,r,v,mid+1,right,seg[cur].r);
    seg[cur].v = min(seg[seg[cur].l].v+seg[seg[cur].l].lazy,seg[seg[cur].r].v+seg[seg[cur].r].lazy);
}

int main(){
    int p,n,m;Coun = 0;
    cin>>n>>m;for(p=1;p<n;p<<=1);
    seg.resize(p*2);
    build(0,p-1,0);
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            int l,r,v;
            cin>>l>>r>>v;add(l,r-1,v,0,p-1,0);
        }else{
            int l,r;cin>>l>>r;
            cout<<search(l,r-1,0,p-1,0)<<endl;
        }


    }
    return 0;
}