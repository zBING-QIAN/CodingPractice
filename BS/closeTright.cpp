#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<k;i++){
        int tmp,l=0,r=n-1;cin>>tmp;
        while(l<r){
            int mid = (l+r)>>1;
            //cout<<arr[mid]<<" "<<tmp<<endl;
            if(arr[mid]>=tmp)r = mid;
            else l = mid+1;
        }
       
       // cout<<arr[l]<<endl;
        if(arr[l]<tmp)l++; 
        
        l++;
        cout<<l<<endl;

    }

    return 0;
}