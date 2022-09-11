#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    long long v;
};
vector<node> segtree;
int Coun = 0;
vector<long long> arr;
void build(int l,int r,long long  v){
    if(l==r){segtree[v].v = arr[l];return;}
    int mid = (l+r)>>1;
    segtree[v].l = ++Coun;segtree[v].r = ++Coun;
    build(l,mid,segtree[v].l);
    build(mid+1,r,segtree[v].r);  
    segtree[v].v = segtree[segtree[v].l].v+segtree[segtree[v].r].v;  //cout<<segtree[v].v<<" ";
}
void add(int l,int r,long long  v,int left,int right,int pos){
    if(l<=left&&r>=right){
        segtree[pos].v +=v;return; 
    }
    int mid = (left+right)>>1;
    if(l<=mid)add(l,r,v,left,mid,segtree[pos].l);
    if(r>mid)add(l,r,v,mid+1,right,segtree[pos].r);

}
void search(int l,int r,int cur,int pos){
    if(l == r){cout<<segtree[cur].v<<endl;return;}
    int tmp =segtree[cur].v;
    if(tmp!=0){
        //cout<<"pos"<<l<<" "<<r<<" "<<tmp;
        segtree[segtree[cur].l].v+=tmp;segtree[segtree[cur].r].v+=tmp;
        segtree[cur].v=0;
    }
    int mid = (l+r)>>1;
    if(mid>=pos){
        search(l,mid,segtree[cur].l,pos);
    }
    else search(mid+1,r,segtree[cur].r,pos);

}
int main(){
    int n,m,p,flag=0;
    cin>>n>>m;for(p=1;p<n;p<<=1);
    segtree.resize(2*p);arr.resize(p+1,0);
    build(0,p-1,0);
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            int l,r;long long v;cin>>l>>r>>v;
            add(l,r-1,v,0,p-1,0);
        }else{
            int l;cin>>l;
            search(0,p-1,0,l);
        }
    }
    return 0;
}