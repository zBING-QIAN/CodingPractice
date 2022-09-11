#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,s;cin>>n>>s;
    vector<int> arr(n);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    long long ans = 0;
    for(int i=0,j=0;i<n;i++){
        while(j<n&&arr[j]-arr[i]<=s){
            j++;
        }if(j==n)break;
        if(arr[j]-arr[i]>s){ans+=(long long)(n-j);}    
    }
    cout<<ans;
    return 0;
}