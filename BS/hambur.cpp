#include<bits/stdc++.h>
using namespace std;

int main(){
    string recp;cin>>recp;
    long long nb,ns,nc,pb,ps,pc,money,rb=0,rs=0,rc=0;
    for(int i=0;i<recp.size();i++){
        if(recp[i]=='B')rb++;
        else if(recp[i]=='S')rs++;
        else if(recp[i]=='C')rc++;
    }
    cin>>nb>>ns>>nc>>pb>>ps>>pc>>money;
    if(rs == 0)ps=0;if(rc == 0)pc=0;if(rb == 0)pb=0;
    long long l=0,r = 1e13;
    while(l<r){
        long long mid = (l+r)>>1;
        long long tmp = 0;
        long long tmpb = (mid*rb-nb)*pb;
        long long tmpc = (mid*rc-nc)*pc;
        long long tmps = (mid*rs-ns)*ps;
        if(tmpb>0)tmp+=tmpb;
        if(tmpc>0)tmp+=tmpc;
        if(tmps>0)tmp+=tmps;
        if(tmp<=money)l = mid+1;
        else r = mid;
    }
    cout<<r-1;
    return 0;
}