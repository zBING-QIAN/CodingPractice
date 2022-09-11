#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r,v,lazy;
};
int Coun=0;
vector<node> seg;
void build(int l,int r,int cur){
    if(l==r){seg[cur].lazy=0,seg[cur].v = 0;return;}
    int mid = (l+r)>>1;
    seg[cur].l = ++Coun;seg[cur].r= ++Coun;
    build(l,mid,seg[cur].l);
    build(mid+1,r,seg[cur].r);
    seg[cur].lazy=seg[cur].v = 0;
}
void add(int l,int r,int v,int left,int right,int cur){
    if(left>=l&&right<=r){
        seg[cur].lazy|=v;return ;
    }
    if(seg[cur].lazy!=0){
        seg[seg[cur].l].lazy|=seg[cur].lazy;
        seg[seg[cur].r].lazy|=seg[cur].lazy;
        seg[cur].lazy = 0;
    }
    int mid= (left+right)>>1;
    if(mid>=l)add(l,r,v,left,mid,seg[cur].l);
    if(mid<r)add(l,r,v,mid+1,right,seg[cur].r);
    seg[cur].v = (seg[seg[cur].l].v|seg[seg[cur].l].lazy)&(seg[seg[cur].r].v|seg[seg[cur].r].lazy);

}
int search(int l,int r,int left,int right,int cur){
    if(l<=left&&r>=right){
        return seg[cur].lazy|seg[cur].v;
    }
    int mid = (left+right)>>1,ans = -1;
    if(mid<r)ans &= search(l,r,mid+1,right,seg[cur].r);
    if(mid>=l)ans &= search(l,r,left,mid,seg[cur].l);
    return ans|seg[cur].lazy;
}

int main(){
    int n,m,p;cin>>n>>m;
    for(p=1;p<n;p<<=1);
    seg.resize(p*2);build(0,p-1,0);
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            int l,r,v;cin>>l>>r>>v;
            add(l,r-1,v,0,p-1,0);
        }else{
            int l,r;cin>>l>>r;
            cout<<search(l,r-1,0,p-1,0)<<endl;
        }

    }
    return 0;
}