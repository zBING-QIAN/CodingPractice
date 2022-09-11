#include<bits/stdc++.h>
using namespace std;

int main(){
    double c;
    cin>>c;
    double l =0,r= 10000000;
    for(int i=0;i<100;i++){
        double mid = (l+r)/(double)2;
        if(mid*mid+sqrtl(mid)>=c)r = mid;
        else l = mid;
    }
    cout<<setprecision(10)<<l<<endl;
    return 0;
}