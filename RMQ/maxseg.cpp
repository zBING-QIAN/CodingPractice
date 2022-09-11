#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r,v;
};
vector<node> seg;
//vector<int> arr;
int Coun = 0;
void build(int l,int r,int cur){
    if(l==r){/*seg[cur].v= arr[l];*/return;}
    int mid = (l+r)>>1;
    seg[cur].l = ++Coun;seg[cur].r = ++Coun;
    build(l,mid,seg[cur].l);
    build(mid+1,r,seg[cur].r);
    //seg[cur].v = max(seg[seg[cur].l].v,seg[seg[cur].r].v);
}
void search(int l,int r,int cur,int pos){
    if(l==r){cout<<seg[cur].v<<endl;return;}
    int tmp = seg[cur].v;
    seg[seg[cur].l].v = max(tmp,seg[seg[cur].l].v);
    seg[seg[cur].r].v = max(tmp,seg[seg[cur].r].v);
    int mid = (l+r)>>1;
    if(pos<=mid)search(l,mid,seg[cur].l,pos);
    else search(mid+1,r,seg[cur].r,pos);
}
void add(int l,int r,int v,int left,int right,int cur){
    if(l<=left&&r>=right){
        seg[cur].v = max(seg[cur].v,v);return;
    }
    int mid = (left+right)>>1;
    if(l<=mid)add(l,r,v,left,mid,seg[cur].l);
    if(r>mid)add(l,r,v,mid+1,right,seg[cur].r);
    
}
int main(){
    int p,m,n;cin>>n>>m;
    for(p=1;p<n;p<<=1);
    seg.resize(2*p);//arr.resize(p,0);
    build(0,p-1,0);
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            int l,r,v;cin>>l>>r>>v;
            add(l,r-1,v,0,p-1,0);
        }else {
            int pos;cin>>pos;
            search(0,p-1,0,pos);
        }

    }

    return 0;
}