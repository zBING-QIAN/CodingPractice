#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    long long a,d,dl;
};
vector<node> seg;
int Coun;
void build(int l,int r,int cur){
    seg[cur].a = seg[cur].d = seg[cur].dl = 0;
    if(l==r){ return ;}
    int mid = (l+r)>>1;
    seg[cur].l = ++Coun;seg[cur].r = ++Coun;
    build(l,mid,seg[cur].l);
    build(mid+1,r,seg[cur].r);
}
void search(int left,int right,int cur,int pos){
    if(left==right){
        cout<<(seg[cur].a+seg[cur].d*(pos+1) - seg[cur].dl)<<endl;
        return;
    }
    if(seg[cur].a!=0){
        seg[seg[cur].l].a+=seg[cur].a;
        seg[seg[cur].r].a+=seg[cur].a;
        seg[cur].a = 0;
    }
    if(seg[cur].d!=0){
        seg[seg[cur].l].d+=seg[cur].d;
        seg[seg[cur].r].d+=seg[cur].d;
        seg[cur].d = 0;
    }
    if(seg[cur].dl!=0){
        seg[seg[cur].l].dl+=seg[cur].dl;
        seg[seg[cur].r].dl+=seg[cur].dl;
        seg[cur].dl = 0;
    }
    int mid = (left+right)>>1;
    if(mid>=pos)search(left,mid,seg[cur].l,pos);
    if(mid<pos)search(mid+1,right,seg[cur].r,pos);
}
void add(int l,int r,long long a,long long d,int left,int right,int cur){
    if(left>=l&&right<=r){
        seg[cur].a +=a;
        seg[cur].d += d;
        seg[cur].dl+=d*(l+1);
        return;
    }
    int mid = (left+right)>>1;
    if(seg[cur].a!=0){
        seg[seg[cur].l].a+=seg[cur].a;
        seg[seg[cur].r].a+=seg[cur].a;
        seg[cur].a = 0;
    }
    if(seg[cur].d!=0){
        seg[seg[cur].l].d+=seg[cur].d;
        seg[seg[cur].r].d+=seg[cur].d;
        seg[cur].d = 0;
    }
    if(seg[cur].dl!=0){
        seg[seg[cur].l].dl+=seg[cur].dl;
        seg[seg[cur].r].dl+=seg[cur].dl;
        seg[cur].dl = 0;
    }
    if(mid>=l)add(l,r,a,d,left,mid,seg[cur].l);
    if(mid<r)add(l,r,a,d,mid+1,right,seg[cur].r);
}

int main(){
    int p,n,m;Coun = 0;
    cin>>n>>m;for(p=1;p<n;p<<=1);
    seg.resize(p*2);
    build(0,p-1,0);
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            int l,r,a,d;
            cin>>l>>r>>a>>d;add(l-1,r-1,a,d,0,p-1,0);
        }else{
            int pos;cin>>pos;
            search(0,p-1,0,pos-1);
        }


    }
    return 0;
}