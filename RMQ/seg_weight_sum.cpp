#include<bits/stdc++.h>
using namespace std;

vector<long long >seg_v,seg_wsum,lazy;
long long ans;

void add(int l,int r,long long v,int left,int right,int cur){
    if(l<=left&&r>=right){
        lazy[cur] +=v;return;
    }
    int ln=cur<<1,rn=(cur<<1)+1, mid = (right+left)>>1;
    long long wide=((right-left+1)>>1),rwide = (((long long)(right+mid+1))*(right-mid))>>1 ,lwide = (((long long)(left+mid))*(mid-left+1))>>1 ;
    if(lazy[cur]!=0){
        lazy[ln]+=lazy[cur],lazy[rn]+=lazy[cur];
        lazy[cur] = 0;
    }
    
    if(mid>=l)add(l,r,v,left,mid,ln);
    if(mid<r)add(l,r,v,mid+1,right,rn);
    
    seg_v[cur] = seg_v[ln]+seg_v[rn] +lazy[ln]*wide+lazy[rn]*wide;
    seg_wsum[cur] = seg_wsum[ln]+seg_wsum[rn]+lazy[ln]*lwide+lazy[rn]*rwide;
}
void search(int l,int r,int left,int right,int cur){
    if(left>=l&&right<=r){
        long long wwide  = (((long long )(left+right))*(right-left+1))>>1,wide = right-left+1;
        ans+=seg_wsum[cur]+lazy[cur]*wwide-(seg_v[cur]+lazy[cur]*wide)*(l-1);
        return;
    }
    int ln=cur<<1,rn=(cur<<1)+1, mid = (right+left)>>1;
    long long wide=((right-left+1)>>1),rwide = (((long long)(right+mid+1))*(right-mid))>>1 ,lwide = (((long long)(left+mid))*(mid-left+1))>>1 ;
    if(lazy[cur]!=0){
        lazy[ln]+=lazy[cur],lazy[rn]+=lazy[cur];
        lazy[cur] = 0;
    }
    if(mid>=l)search(l,r,left,mid,ln);
    if(mid<r)search(l,r,mid+1,right,rn);
    seg_v[cur] = seg_v[ln]+seg_v[rn] +lazy[ln]*wide+lazy[rn]*wide;
    seg_wsum[cur] = seg_wsum[ln]+seg_wsum[rn]+lazy[ln]*lwide+lazy[rn]*rwide;
}


int main(){
    int n,m,p;cin>>n>>m;n++;for(p=1;p<n;p<<=1);
    seg_v.resize(p*2,0),seg_wsum.resize(p*2,0),lazy.resize(p*2,0);
    for(int i=1;i<n;i++){
        cin>>seg_v[i+p];seg_wsum[i+p] = seg_v[i+p]*i;
    }
    for(int i=p-1;i;i--){
        seg_v[i] = seg_v[i<<1]+seg_v[(i<<1)+1];
        seg_wsum[i] = seg_wsum[i<<1]+seg_wsum[(i<<1)+1];
    }
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            int l,r,v;cin>>l>>r>>v;
            add(l,r,v,0,p-1,1);

        }else{
            int l,r;cin>>l>>r;ans = 0;
            search(l,r,0,p-1,1);
            cout<<ans<<endl;
        }

    }
    return 0;
}