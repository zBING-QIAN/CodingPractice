#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    long long v,lazy;
};
vector<node>seg;

int Coun = 0;
void build(int l,int r,int cur){
    seg[cur].v = seg[cur].lazy = 0;
    if(l==r)return;
    int mid = (l+r)>>1;
    seg[cur].l = ++Coun;seg[cur].r = ++Coun;
    build(l,mid,seg[cur].l);
    build(mid+1,r,seg[cur].r);
}
void add(int l,int r,long long v,int left,int right,int cur){
    if(l<=left&&r>=right){
        seg[cur].lazy+=v;return;
    }
    if(seg[cur].lazy>0){
        seg[seg[cur].l].lazy+=seg[cur].lazy;
        seg[seg[cur].r].lazy+=seg[cur].lazy;
        seg[cur].lazy = 0;
    }
    int mid = (left+right)>>1;
    if(mid>=l)add(l,r,v,left,mid,seg[cur].l);
    if(mid<r)add(l,r,v,mid+1,right,seg[cur].r);
    seg[cur].v = max(seg[seg[cur].l].v+seg[seg[cur].l].lazy,seg[seg[cur].r].v+seg[seg[cur].r].lazy);

}
int search(int left,int right,int cur,int x,int l){
    //cout<<"left,right "<<left<<" "<<right<<" "<<seg[cur].v+seg[cur].lazy<<endl;
    if(left==right){
        return ((seg[cur].v+seg[cur].lazy)>=x)?left:-1;
    }
    if(seg[cur].lazy>0){
        //cout<<"update :"<<left<<" "<<right<<" "<<seg[cur].lazy<<endl;
        seg[seg[cur].l].lazy+=seg[cur].lazy;
        seg[seg[cur].r].lazy+=seg[cur].lazy;
        seg[cur].v += seg[cur].lazy;
        seg[cur].lazy = 0;
    }
    int mid = (left+right)>>1,ansl = -1;
    if(mid>=l&&seg[seg[cur].l].v+seg[seg[cur].l].lazy>=x){
        ansl = search(left,mid,seg[cur].l,x,l);
        //cout<<"left,right "<<left<<" "<<right<<" ansl "<<ansl<<endl;
        if(ansl!=-1)return ansl;
    }
    if(seg[seg[cur].r].v+seg[seg[cur].r].lazy>=x)return search(mid+1,right,seg[cur].r,x,l);
    return -1;

}
int main(){
    int m,n,p;cin>>n>>m;for(p=1;p<n;p<<=1);
    seg.resize(p*2);
    build(0,p-1,0);
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            int l,r,v;cin>>l>>r>>v;
            add(l,r-1,v,0,p-1,0);
        }else{
            int x,l;cin>>x>>l;
            cout<<search(0,p-1,0,x,l)<<endl;
        }

    }
    return 0;
}