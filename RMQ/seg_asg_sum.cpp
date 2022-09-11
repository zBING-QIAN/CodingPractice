#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    long long v,lazy,count;
};
int Coun=0;
long long ans;
vector<node> seg;
void build(int l,int r,int cur){
    seg[cur].lazy=-1,seg[cur].v = 0;seg[cur].count = r-l+1;
    if(l==r){return;}
    int mid = (l+r)>>1;
    seg[cur].l = ++Coun;seg[cur].r= ++Coun;
    build(l,mid,seg[cur].l);
    build(mid+1,r,seg[cur].r);
}
void add(int l,int r,int v,int left,int right,int cur){
    if(left>=l&&right<=r){
        seg[cur].lazy=v,seg[cur].v = seg[cur].count*v;return;
    }
    if(seg[cur].lazy!=-1){
        seg[seg[cur].l].lazy=seg[cur].lazy;seg[seg[cur].l].v = seg[seg[cur].l].count*seg[cur].lazy;
        seg[seg[cur].r].lazy=seg[cur].lazy;seg[seg[cur].r].v = seg[seg[cur].r].count*seg[cur].lazy;
        seg[cur].lazy = -1;
    }
    int mid= (left+right)>>1;
    if(mid>=l)add(l,r,v,left,mid,seg[cur].l);
    if(mid<r)add(l,r,v,mid+1,right,seg[cur].r);
    seg[cur].v = seg[seg[cur].l].v+seg[seg[cur].r].v;

}
void search(int l,int r,int left,int right,int cur){
    if(seg[cur].lazy!=-1){
        int bl = max(left,l),br= min(right,r);
        ans+= (seg[cur].lazy*(br-bl+1));return;
    }
    if(l<=left&&r>=right){
        ans += seg[cur].v;
        return;
    }

    int mid = (left+right)>>1;
    if(mid<r) search(l,r,mid+1,right,seg[cur].r);
    if(mid>=l)search(l,r,left,mid,seg[cur].l);
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
            int l,r;cin>>l>>r;ans = 0;search(l,r-1,0,p-1,0);
            cout<<ans<<endl;
        }

    }
    return 0;
}