#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;cin>>N;
   
    vector<double > pos(N),v(N);
    for(int i=0;i<N;i++){
        cin>>pos[i]>>v[i]; 
    }
    double l=0,r=1e9;
    for(int t = 0;t<80;t++){
        double  mid = (l+r)/2;
        double al=-1e9,ar=1e9;
        for(int i=0;i<N;i++){
            al = max(al,pos[i]-v[i]*mid);
            ar = min(ar,pos[i]+v[i]*mid);
            if(al>ar)break;
        }
        if(al>ar){
            l = mid;
        }else {
            r = mid;
        }
    }
    cout<<setprecision(10)<<l<<endl;
    return 0;
}