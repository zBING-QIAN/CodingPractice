#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    bool bl,br,lazy;//or assign
    int b,s;
    node(){l=-1,r=-1,bl=br=lazy = b = s =0;}
};
int Coun=0;
long long ans;
vector<node> seg;
void add(int l,int r,bool v,int left,int right,int cur){
    if(seg[cur].l==-1){seg[cur].l=seg.size();seg.push_back(node());}
    if(seg[cur].r==-1){seg[cur].r=seg.size();seg.push_back(node());}
    if(left>=l&&right<=r){
        seg[cur].lazy = true;
        seg[cur].br = seg[cur].bl = v;
        if(v){seg[cur].b = right-left+1;seg[cur].s = 1;return;}
        else {seg[cur].b = seg[cur].s = 0;return;}return;
    }
    if(seg[cur].lazy){
        seg[seg[cur].r].lazy = seg[seg[cur].l].lazy=true;
        seg[seg[cur].l].bl = seg[seg[cur].l].br = seg[seg[cur].r].bl = seg[seg[cur].r].br = seg[cur].bl;
        seg[seg[cur].l].b = seg[seg[cur].r].b = (seg[cur].b)>>1;
        seg[seg[cur].l].s = seg[seg[cur].r].s = seg[cur].s;
        seg[cur].lazy = 0;
    }
    int mid= (left+right)>>1;
    if(mid>=l)add(l,r,v,left,mid,seg[cur].l);
    if(mid<r)add(l,r,v,mid+1,right,seg[cur].r);

    seg[cur].b = seg[seg[cur].l].b+seg[seg[cur].r].b;
    //cout<<"debug "<<left<<" "<<right<<"  l br:"<<seg[seg[cur].l].br<<" r bl:"<<seg[seg[cur].r].bl;
    seg[cur].s = seg[seg[cur].l].s+seg[seg[cur].r].s-(seg[seg[cur].l].br&seg[seg[cur].r].bl);
    seg[cur].bl = seg[seg[cur].l].bl;seg[cur].br = seg[seg[cur].r].br;
}


int main(){
    int m,p,n = 1000001;cin>>m;
    for(p=1;p<n;p<<=1);
    seg.push_back(node());
    for(int i=0;i<m;i++){
        char op;cin>>op;
        int x,l;cin>>x>>l;x+=(n>>1);
        add(x,x+l-1,(op=='B'),0,p-1,0);
        cout<<seg[0].s<<" "<<seg[0].b<<endl;
    }
    return 0;
}