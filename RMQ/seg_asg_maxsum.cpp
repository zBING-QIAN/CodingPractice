#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    bool lazy;
    long long v,vlazy,lv,rv,tot;
    node(){}
   
};
int Coun=0;
vector<node> seg;

void build(int l,int r,int cur){
    seg[cur].v = seg[cur].lazy = seg[cur].vlazy = seg[cur].lv=seg[cur].rv = seg[cur].tot = 0;
    if(l==r){return;}
    int mid = (l+r)>>1;
    seg[cur].l = ++Coun;seg[cur].r = ++Coun;
    build(l,mid,seg[cur].l);
    build(mid+1,r,seg[cur].r);
}
void modify(int l,int r,long long v ,int left,int right,int cur){
    if(left>=l&&right<=r){ 
        int count = right-left+1;
        seg[cur].tot = v*count;seg[cur].vlazy = v;
        v = (v>0)?v:0;
        seg[cur].lazy = true;
        seg[cur].v = seg[cur].rv = seg[cur].lv = v*count;
        return;
    }
    if(seg[cur].lazy){
        seg[seg[cur].r].lazy = seg[seg[cur].l].lazy = true;
        seg[seg[cur].r].vlazy = seg[seg[cur].l].vlazy = seg[cur].vlazy;
        seg[seg[cur].l].tot = seg[seg[cur].r].tot = seg[cur].vlazy * ((right-left+1)>>1);
        if(seg[cur].vlazy <0)seg[cur].vlazy = 0;
        seg[seg[cur].r].lv = seg[seg[cur].r].rv = seg[seg[cur].r].v = seg[seg[cur].l].lv = \
        seg[seg[cur].l].rv = seg[seg[cur].l].v = seg[cur].vlazy*((right-left+1)>>1);
        seg[cur].lazy = false;
    }
    int mid = (left+right)>>1;
    if(mid>=l)modify(l,r,v,left,mid,seg[cur].l);
    if(mid<r)modify(l,r,v,mid+1,right,seg[cur].r);
    seg[cur].v = max(max(seg[seg[cur].l].rv+seg[seg[cur].r].lv,seg[seg[cur].r].v),seg[seg[cur].l].v);
    seg[cur].rv = max(seg[seg[cur].l].rv+seg[seg[cur].r].tot,seg[seg[cur].r].rv);
    seg[cur].lv = max(seg[seg[cur].r].lv+seg[seg[cur].l].tot,seg[seg[cur].l].lv);
    seg[cur].tot = seg[seg[cur].l].tot+seg[seg[cur].r].tot;
}


int main(){
    int m,n,p;cin>>n>>m;for(p=1;p<n;p<<=1);
    seg.resize(p*2+10);build(0,p-1,0);
    for(int i=0;i<m;i++){
        int l,r,v;cin>>l>>r>>v;
        modify(l,r-1,v,0,p-1,0);
        cout<<seg[0].v<<endl;
    }


}