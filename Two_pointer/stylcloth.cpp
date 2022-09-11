#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    vector<int> arr[4];
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> maxheap;
    int total = 0;
    for(int i=0;i<4;i++){
        cin>>n;arr[i].resize(n);
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }sort(arr[i].begin(),arr[i].end());total += arr[i].size();
    }
    int ans[4],cur[4],dif = 1e9,small=1e9,big=0;
    for(int i=0;i<4;i++){ans[i] = cur[i] = 0;big = max(big,arr[i][0]);small = min(small,arr[i][0]);if(arr[i].size()>1)maxheap.push({arr[i][1],i});}
    dif = big-small;
    while(maxheap.size()){
        
        int tmp = maxheap.top()[1];//cout<<"top "<<maxheap.top()[0]<<endl;
        big = max(big,arr[tmp][++cur[tmp]]);
        small = arr[0][cur[0]];
        for(int j=1;j<4;j++){
            small = min(small,arr[j][cur[j]]);
        }
        if(big-small<dif){dif = big-small;for(int j=0;j<4;j++)ans[j]=cur[j];}
        maxheap.pop();//cout<<"heap size "<<maxheap.size()<<endl;
        //cout<<cur[tmp]<<" "<<arr[tmp].size()<<endl;
        if(cur[tmp]+1<arr[tmp].size())maxheap.push({arr[tmp][cur[tmp]+1],tmp});
    }
    for(int i=0;i<4;i++)cout<<arr[i][ans[i]]<<" ";
    return 0;
}