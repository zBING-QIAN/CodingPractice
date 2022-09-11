#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    bool isasg;//or assign
    long long v,lazy;
};
int Coun=0;
long long ans;
vector<node> seg;
void build(int l,int r,int cur){
    seg[cur].lazy = 0,seg[cur].v = 0;seg[cur].isasg = false;
    if(l==r){return;}
    int mid = (l+r)>>1;
    seg[cur].l = ++Coun;seg[cur].r= ++Coun;
    build(l,mid,seg[cur].l);
    build(mid+1,r,seg[cur].r);
}
void add(int l,int r,int v,int left,int right,int cur){
    if(left>=l&&right<=r){
        seg[cur].lazy+=v;return;
    }
    if(seg[cur].isasg){
        seg[seg[cur].r].isasg = seg[seg[cur].l].isasg = true;
        seg[seg[cur].r].lazy = seg[seg[cur].l].lazy=seg[cur].lazy;
        seg[seg[cur].l].v = seg[seg[cur].r].v = 0;
        seg[cur].isasg = seg[cur].lazy = 0;
    }
    if(seg[cur].lazy!=0){
        seg[seg[cur].r].lazy += seg[cur].lazy; seg[seg[cur].l].lazy += seg[cur].lazy;
        seg[cur].lazy = 0;
    }
    int mid= (left+right)>>1;
    if(mid>=l)add(l,r,v,left,mid,seg[cur].l);
    if(mid<r)add(l,r,v,mid+1,right,seg[cur].r);
    seg[cur].v = seg[seg[cur].l].v+seg[seg[cur].r].v+  \
    seg[seg[cur].l].lazy*((right-left+1)>>1)+seg[seg[cur].r].lazy*((right-left+1)>>1);

}
void assign(int l,int r,int v,int left,int right,int cur){
    if(left>=l&&right<=r){
        seg[cur].isasg = true;seg[cur].v = 0;
        seg[cur].lazy=v;return;
    }
    if(seg[cur].isasg){
        seg[seg[cur].r].isasg = seg[seg[cur].l].isasg = true;
        seg[seg[cur].r].lazy = seg[seg[cur].l].lazy=seg[cur].lazy;
        seg[seg[cur].l].v = seg[seg[cur].r].v = 0;
        seg[cur].isasg = seg[cur].lazy = 0;
    }
    if(seg[cur].lazy!=0){
        seg[seg[cur].r].lazy += seg[cur].lazy; seg[seg[cur].l].lazy += seg[cur].lazy;
        seg[cur].lazy = 0;
    }
    int mid= (left+right)>>1;
    if(mid>=l)assign(l,r,v,left,mid,seg[cur].l);
    if(mid<r)assign(l,r,v,mid+1,right,seg[cur].r);
    seg[cur].v = seg[seg[cur].l].v+seg[seg[cur].r].v+  \
    seg[seg[cur].l].lazy*((right-left+1)>>1)+seg[seg[cur].r].lazy*((right-left+1)>>1);
}
void search(int l,int r,int left,int right,int cur){
    if(l<=left&&r>=right){
        ans += seg[cur].v+seg[cur].lazy*(right-left+1);
        return;
    }
    if(seg[cur].isasg){
        seg[seg[cur].r].isasg = seg[seg[cur].l].isasg = true;
        seg[seg[cur].r].lazy = seg[seg[cur].l].lazy=seg[cur].lazy;
        seg[seg[cur].l].v = seg[seg[cur].r].v = 0;
        seg[cur].isasg = seg[cur].lazy = 0;
    }
    if(seg[cur].lazy!=0){
        seg[seg[cur].r].lazy += seg[cur].lazy; seg[seg[cur].l].lazy += seg[cur].lazy;
        seg[cur].lazy = 0;
    }
    int mid = (left+right)>>1;
    if(mid<r) search(l,r,mid+1,right,seg[cur].r);
    if(mid>=l)search(l,r,left,mid,seg[cur].l);
    seg[cur].v = seg[seg[cur].l].v+seg[seg[cur].r].v+  \
    seg[seg[cur].l].lazy*((right-left+1)>>1)+seg[seg[cur].r].lazy*((right-left+1)>>1);
}

int main(){
    int n,m,p;cin>>n>>m;
    for(p=1;p<n;p<<=1);
    seg.resize(p*2);build(0,p-1,0);
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            int l,r,v;cin>>l>>r>>v;
            assign(l,r-1,v,0,p-1,0);
        }else if(op==2){
            int l,r,v;cin>>l>>r>>v;
            add(l,r-1,v,0,p-1,0);
        }else if(op==3){
            int l,r;cin>>l>>r;ans = 0;
            search(l,r-1,0,p-1,0);
            cout<<ans<<endl;
        }

    }
    return 0;
}