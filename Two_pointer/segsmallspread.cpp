#include<bits/stdc++.h>
using namespace std;
void callerr(){int a=2,b=4;cout<<a/(b-4);}
int main(){
    int n;long long s;cin>>n>>s;
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    if(s==0){cout<<n<<endl;return 0;}
    long long ans = 0;
    map<long long ,int> rec;
    rec[arr[0]]=1;
    for(int i=0,j=0;i<n;){
        long long big = rec.rbegin()->first,small = rec.begin()->first;
        while(j<n&&big-small<=s){
            j++;if(j==n)break;
            //big=max(big,arr[j]);small=min(small,arr[j]);
            if(rec.find(arr[j])==rec.end())rec[arr[j]]=1;
            else rec[arr[j]]++;
            big = rec.rbegin()->first,small = rec.begin()->first;
        }
        while(i<j&&(j==n||big-small>s)){
            ans+=j-i;  
            rec[arr[i]]--;
            if(rec[arr[i]]==0){
                rec.erase(arr[i]);
                // if(rec.size()>0){
                    
                //     if(big==arr[i])big = rec.rbegin()->first;
                //     if(small==arr[i])small = rec.begin()->first;    
                // }
                // else big = small;
            }i++;
            if(rec.size()>0)big = rec.rbegin()->first,small = rec.begin()->first;
        
        }
    }
    cout<<ans;
    return 0;
}