#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9+7;
struct node{
    int l,r;
    long long v,lazy;
};
vector<node> seg;
int Coun;
void build(int l,int r,int cur){
    seg[cur].v = r-l+1,seg[cur].lazy = 1;
    if(l==r){ return ;}
    int mid = (l+r)>>1;
    seg[cur].l = ++Coun;seg[cur].r = ++Coun;
    build(l,mid,seg[cur].l);
    build(mid+1,r,seg[cur].r);
}
long long search(int l,int r,int left,int right,int cur){
    if(left>=l&&right<=r){
        return (seg[cur].v*seg[cur].lazy)%MOD;
    }
    int mid = (left+right)>>1;
    long long sum = 0;
    if(mid>=l)sum = search(l,r,left,mid,seg[cur].l);
    if(mid<r)sum = (sum + search(l,r,mid+1,right,seg[cur].r))%MOD;
    return (sum*seg[cur].lazy)%MOD;
}
void add(int l,int r,long long v,int left,int right,int cur){
    if(left>=l&&right<=r){
        seg[cur].lazy =(v*seg[cur].lazy) % MOD;
        return;
    }
    int mid = (left+right)>>1;
    if(seg[cur].lazy!=1){
        seg[seg[cur].l].lazy=(long long)(seg[seg[cur].l].lazy*seg[cur].lazy)%MOD;
        seg[seg[cur].r].lazy=(long long)(seg[seg[cur].r].lazy*seg[cur].lazy)%MOD;
        seg[cur].lazy = 1;
    }
    if(mid>=l)add(l,r,v,left,mid,seg[cur].l);
    if(mid<r)add(l,r,v,mid+1,right,seg[cur].r);
    seg[cur].v = (((seg[seg[cur].l].v*seg[seg[cur].l].lazy)%MOD)+((seg[seg[cur].r].v*seg[seg[cur].r].lazy)%MOD))%MOD;
}

int main(){
    int p,n,m;Coun = 0;
    cin>>n>>m;for(p=1;p<n;p<<=1);
    seg.resize(p*2+10);
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