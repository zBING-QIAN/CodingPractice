#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    if(a<b)swap(a,b);
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}
void callerr(){int a=2,b=4;cout<<a/(b-4);}

int main(){
    int n;cin>>n;
    vector<long long> arr(n),rec;
    for(int i=0;i<n;i++){scanf("%lld",&arr[i]);if(arr[i]==1){cout<<"1";return 0;}}
    long long fcop=1;
    int ans =n+1;

    int sep1=0,sep2=0;fcop = arr[0];
    
    if(n==1){cout<<"-1";return 0;}
    for(int i=0,j=0;i<n;){
        long long curcop = fcop;
        
        while(j<n&&curcop>1){
            j++;
            if(j>=n)break;
            fcop = gcd(arr[j],fcop);
            if(fcop==1){rec.clear();curcop=1;break;}
            if(rec.size()){
                curcop = gcd(fcop,rec.back());rec.pop_back();
            }else{
                curcop = fcop;
            } 
        }
        if(j>=n)break;
        if(rec.size()){
            while(rec.size()&&gcd(fcop,rec.back())==1){
                rec.pop_back();
            }
            int ad = rec.size();
            ans = min(ans,j-i+1+ad);
        }else{
            int tmp = j-1;rec.push_back(arr[j]);
            while(i<=tmp){
                rec.push_back(gcd(rec.back(),arr[tmp]));//cout<<"check i j "<<i<<" "<<j<<" cop "<<cop<<endl;
                if(rec.back()==1){ans=min(j-tmp+1,ans);break;}//cout<<"ans = "<<ans<<" i j "<<i<<" "<<j<<endl;}
                tmp--;
            }   i = j;fcop = arr[j];
        }
    }
    if(ans>n)cout<<-1;
    else cout<<ans;
    return 0;
}