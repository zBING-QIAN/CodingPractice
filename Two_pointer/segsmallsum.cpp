#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long s;cin>>n>>s;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)scanf("%lld",&arr[i]);
    int maxlen=0;
    long long cursum=0;
    for(int i=0,j=0;j<n;){
        while(j<n&&cursum+arr[j]<=s){cursum+=arr[j];j++;}
        if(j-i>maxlen)maxlen=j-i;
        while(j<n&&arr[j]+cursum>s){
            cursum-=arr[i];i++;
            if(j<i)j=i,cursum=0;
        }
    }
    cout<<maxlen<<endl;
    return 0;
}