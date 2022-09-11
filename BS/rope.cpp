#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    double r=1e8,l=0;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<100;i++){
        double mid = (l+r)/2;
        long long sum = 0;
        for(int j = 0;j<n;j++){
            sum+=floor(arr[j]/mid);
        }
        if(sum>=k){
            l = mid;
        }
        else {
            r = mid;
        }
    } 
    cout<<setprecision(10)<<l<<endl;
    return 0;
}