#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;long long p;cin>>n>>p;
    vector<long long>arr(n*2);
    long long all = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];arr[i+n]=arr[i];all+=arr[i];
    }
    long long sum=0;
    int start = 0;
    long long  anstmp = 1e18,ans = n*(p/all);p %= all;
    for(long long i=0,j=0;i<(n<<1);){
        while(j<2*n&&sum<p){
            sum+=arr[j];j++;
        }
        while(sum>=p){
            if(anstmp>j-i){anstmp = j-i;start = i;}
            sum-=arr[i];
            if(i==j)break;i++;
        }
        if(j==n*2)break;
    }
    start%=n;start++;
    cout<<start<<" "<<anstmp+ans;
    return 0;
}