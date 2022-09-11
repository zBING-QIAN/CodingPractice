#include<bits/stdc++.h>
using namespace std;

int main(){
    long long  a,b,n;
    cin>>a>>b>>n;if(a<b)swap(a,b);
    long long l=a,r = (a>b)?a*n:b*n;
    while(l<r){
        long long mid = (l+r)>>1,tmp = n%(mid/b);
        if(n/(mid/b)<(mid/a) || (tmp==0 && n/(mid/b)==(mid/a)))r = mid;
        else l = mid+1; 
    }
    cout<<l<<endl;
    return 0;
}