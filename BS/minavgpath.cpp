#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<vector<array<double,2>>> road;
vector<int> record;
double Kroad(double k){
    vector<double> rec(n,1e9);rec[0] = 0;
    vector<int> dis(n,0),pre(n,-1);pre[0] = 0;
    for(int i=1;i<n;i++){
        int s = road[i].size();
        for(int j=0;j<s;j++){
            double tmp = road[i][j][1] - k;
            int from = road[i][j][0];
            if(pre[from]!=-1&&rec[from]+tmp<rec[i]){
                rec[i] = rec[from]+tmp;
                dis[i] = dis[from]+1;
                pre[i] = from;
            }
        }
        if(i == n-1&&rec[i]<=0){
            int a = i;ans = dis[i];
            while(a){
                record[dis[a]] = a;
                a = pre[a];
            }
            return k+rec[i]/dis[i];
        }
        
    }
    return k+1;
}

int main(){
    cin>>n>>m;road.resize(n);record.resize(n,0);
    double l = 0,r = 100;
    for(int i=0;i<m;i++){
        double buf1,buf2,buf3;cin>>buf1>>buf2>>buf3;
        road[buf2-1].push_back({buf1-1,buf3});
    }
    for(int i=0;i<80;i++){
        double mid = (l+r)/2.0;
        double s = Kroad(mid);
        if(s<=mid)r = s;
        else l = mid;
    }
    cout<<ans<<endl;
    if(ans)
        for(int i=0;i<=ans;i++)
            cout<<record[i]+1<<" ";

    return 0;
}