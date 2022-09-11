#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;long long s;cin>>n>>s;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)scanf("%lld",&arr[i]);
    long long sum=0,ans =0;
    int tt= 0;
    for(int i=0,j=0;i<n;){
        while(j<n&&sum+arr[j]<=s){sum+=arr[j];j++;}
        while(i<n&&(j==n||sum+arr[j]>s)){
            ans+=j-i;//cout<<i<<" "<<j<<endl;
            sum-=arr[i];
            i++;
            if(i>j){
                j=i;sum=0;
            }
        }
        //tt++;
        //if(tt==100000)callerr();
    }
    cout<<ans<<endl;
    return 0;
}