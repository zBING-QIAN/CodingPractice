#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long s,cursum=0;cin>>n>>s;
    int minlen=0;
    long long ans =0;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){scanf("%lld",&arr[i]);}
    for(;minlen<n&&cursum<s;minlen++)cursum+=arr[minlen];
    if(cursum<s){cout<<0<<endl;return 0;}
    for(int i=0,j=minlen;i<n;){
        while(j<n&&cursum<s){cursum+=arr[j];j++;}
        while(i<j&&cursum>=s){
            ans+=n-j+1;
            cursum-=arr[i];i++;
        }
        if(j==n)break;
    }
    cout<<ans<<endl;
    return 0;
}