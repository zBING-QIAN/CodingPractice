#include<bits/stdc++.h>
using namespace std;
int m,n,p;
vector<long long > seg_sum,seg_pre,seg_suf,seg_maxsum;
void add(int a,long long v){
    long long maxsum =(v>0)?v:0;
    long long  pre = maxsum,suf = maxsum;
    for(a+=p;a;a>>=1){
        seg_sum[a] = v; 
        seg_pre[a] = pre;
        seg_suf[a] = suf;
        seg_maxsum[a] = maxsum;
        int tmp =a-(a&1);
        maxsum = max(max(seg_maxsum[tmp],seg_maxsum[tmp+1]),seg_pre[1+tmp]+seg_suf[tmp]);
        pre = max(seg_pre[tmp],seg_sum[tmp]+seg_pre[tmp+1]);
        suf = max(seg_suf[tmp+1],seg_sum[tmp+1]+seg_suf[tmp]);
        v = seg_sum[a]+seg_sum[a^1];
    }
}



int main(){
    cin>>m>>n;
    for(p=1;p<m;p<<=1);
    seg_suf.resize(2*p),seg_maxsum.resize(2*p),seg_sum.resize(2*p),seg_pre.resize(2*p);
    for(int i=0;i<m;i++){
        cin>> seg_sum[p+i];
        seg_maxsum[p+i]=seg_pre[p+i]=seg_suf[p+i]=(seg_sum[p+i]>0)?seg_sum[p+i]:0;
    }
    for(int i=p-1;i;i--){
        int tmp = i*2;
        seg_sum[i] = seg_sum[tmp]+seg_sum[tmp+1];
        seg_pre[i] = max(seg_pre[tmp],seg_sum[tmp]+seg_pre[tmp+1]);
        seg_suf[i] = max(seg_suf[tmp+1],seg_sum[tmp+1]+seg_suf[tmp]);
        seg_maxsum[i] = max(max(seg_maxsum[tmp],seg_maxsum[tmp+1]),seg_pre[tmp+1]+seg_suf[tmp]);
      
    }
    cout<<seg_maxsum[1]<<endl;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        cout<<seg_maxsum[1]<<endl;
    }
    return 0;
}