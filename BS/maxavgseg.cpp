#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    cin>>n>>d;
    vector<double>arr(n+1);arr[0]= 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(n == 1){cout<<"1 1"<<endl;return 0;}
    double l =0,r = 100;
    int ansl=1,ansr=n;
    for(int t = 0;t<100;t++){
        double mid = (l+r)/2;
        bool tmp = false;
        vector<double> p(n+1);
        vector<int> m(n+1);
        m[0] = 0 ;p[0] = -mid;
        
        for(int i=1;i<=n;i++){
            p[i] = arr[i]-mid+p[i-1];
            m[i] = (p[m[i-1]]>=p[i]) ? i : m[i-1];
            if(i>=d && p[i] >= p[m[i-d]]){
                //cout<<"mid "<<mid<<" l "<<m[i-d]<<" r "<<i<<" "<<p[i]<<" "<<p[m[i-d]]<<" "<<endl;
                tmp = true;ansl = m[i-d],ansr = i;
            }
        }
        if(l ==r)break;
        if(tmp)l = mid;
        else r = mid;
    }cout<<ansl+1<<" "<<ansr<<endl;
    return 0;
}