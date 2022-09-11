#include<bits/stdc++.h>
using namespace std;

struct node{
    int l,r;
    bool lazy;
    long long v,sum,maxpref;
    node(){l=r=-1;v = sum = lazy = maxpref = 0;}
};
vector<node> seg;
void build(int l,int r,int cur){
    if(l==r){
       return;
    }
    int mid = (l+r)>>1;
    seg[cur].l = seg.size();seg.push_back(node());
    seg[cur].r = seg.size();seg.push_back(node());
    build(l,mid,seg[cur].l);
}
void add(int l,int r,long long v,int left,int right,int cur){
    if(seg[cur].l==-1){seg[cur].l = seg.size();seg.push_back(node());}
    if(seg[cur].r==-1){seg[cur].r = seg.size();seg.push_back(node());}
    if(left>=l&&right<=r){
        seg[cur].v = v;
        seg[cur].sum = v*(right-left+1);
        seg[cur].maxpref = (v>0)?seg[cur].sum:0;
        seg[cur].lazy = true;
        return;
    }
    if(seg[cur].lazy){
        seg[seg[cur].l].lazy = seg[seg[cur].r].lazy = true;
        seg[cur].lazy = false;
        seg[seg[cur].l].v = seg[seg[cur].r].v = seg[cur].v;
        seg[seg[cur].l].sum = seg[seg[cur].r].sum = seg[cur].sum>>1;
        if(seg[cur].v>0){
            seg[seg[cur].l].maxpref = seg[seg[cur].r].maxpref = seg[cur].sum>>1;
        }else {
            seg[seg[cur].l].maxpref = seg[seg[cur].r].maxpref = 0;
        }
    }
    int mid = (left+right)>>1;
    if(mid >= l){add(l,r,v,left,mid,seg[cur].l);}
    if(mid<r) {add(l,r,v,mid+1,right,seg[cur].r);}
    seg[cur].maxpref = max(seg[seg[cur].l].maxpref,seg[seg[cur].l].sum+seg[seg[cur].r].maxpref);
    seg[cur].sum = seg[seg[cur].l].sum+seg[seg[cur].r].sum;
}
void seg_search(int left,int right,int cur,long long v){
    //cout<<left<<" "<<right<<" "<<seg[cur].maxpref<<" "<<seg[cur].sum<<endl;
    if(left==right){ printf("%d\n",left-1);return;}
    if(seg[cur].lazy){
        long long tmp = v/seg[cur].v;printf("%d\n",left+tmp-1);
        return;
    }
        int mid = (left+right)>>1;
    if(seg[seg[cur].l].maxpref<=v){
        seg_search(mid+1,right,seg[cur].r,v-seg[seg[cur].l].sum);
    }else{
        seg_search(left,mid,seg[cur].l,v);
    }
}
//debug
int main(){
    int n,p=1<<31;cin>>n;seg.push_back(node());
    char op;int l,r,v;
    while(true){
        cin>>op;
        if(op=='E')break;
        else if(op == 'I'){
            scanf("%d %d %d",&l,&r,&v);
            add(l,r,v,0,p-1,0);

        }else if(op == 'Q'){
            scanf("%d",&l);
            
            if(seg[0].maxpref<=l){
                printf("%d\n",n);
            }else {
                
                seg_search(0,p-1,0,l);
            }
        }

    }
    return 0;
}