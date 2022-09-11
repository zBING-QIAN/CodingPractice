#include<bits/stdc++.h>
using namespace std;
int n,m,d,ans;
vector<vector<array<int,2>>> road;
vector<int> record;

int Kroad(int k){
    vector<int>rec(n,0),pre(n,-1),dis(n,0),que;que.push_back(0);
    int f = 0;rec[0]=0;
    while(f<que.size()){
        int cur = que[f];
        if(dis[cur]<d){
            int s = road[cur].size();
            for(int i=0;i<s;i++){
                int to =road[cur][i][0];
                if(pre[to] == -1&&road[cur][i][1]<=k){
                    rec[to] = max(road[cur][i][1],rec[cur]);
                    pre[to] = cur;
                    dis[to] = dis[cur]+1;
                    que.push_back(to);
                    if(to==n-1){
                        ans = dis[to];
                        while(to){
                            record[dis[to]] = to;
                            to = pre[to];
                        }
                        return rec[n-1];    
                    }
                }
            }
        }
        f++;
        
    }
    return -1;


}

int main(){
    cin>>n>>m>>d;road.resize(n);record.resize(n,0);
    int l = 0,r = 0;ans = -1;
    for(int i=0;i<m;i++){
        int buf1,buf2,buf3;cin>>buf1>>buf2>>buf3;
        r = max(buf3,r);
        road[buf1-1].push_back({buf2-1,buf3});
    }
    while(l<r){
        int mid = (l+r)>>1;
        int s = Kroad(mid);
        if(s>=0)r = s;
        else l = mid+1;
    }
    Kroad(l);
    cout<<ans<<endl;
    if(ans)
        for(int i=0;i<=ans;i++)
            cout<<record[i]+1<<" ";

    return 0;
}