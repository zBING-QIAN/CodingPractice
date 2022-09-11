#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,p;cin>>n>>m;
    for(p=1;p<n;p<<=1);
    vector<vector<int> > seg(2*p,vector<int>());
    vector<int>ans_list(m+1,0);
    vector<array<int,4>>query;
    for(int i = 0;i < m;i++){
        int op;cin>>op;
        if(op==1){
            int a,b;cin>>a>>b;query.push_back({op,a,b,0});
        }else {
            int a,b,c;cin>>a>>b>>c;query.push_back({op,a,b,c});
        }
    }
    query.push_back({2,0,n,1000000009});
    vector<int> record(m+1,m);
    for(int i=m;i>=0;i--){
        //cout<<"deal with"<<i<<endl;
        if(query[i][0]==1){
            int a = query[i][1],v = query[i][2];
            for(int l = 0,r = p-1,pos=1;;){
                int left = 0,right = seg[pos].size()-1;
                while(left<right){
                    int tmp = (right+left)>>1;
                    if(query[seg[pos][tmp]][3]>=v){
                        if(record[a]>seg[pos][tmp])record[a] = seg[pos][tmp];
                        left = tmp+1;
                    }else {
                        if(record[a]<seg[pos][tmp])break;
                        right = tmp;
                    }
                }
                if(left==right&&query[seg[pos][left]][3]>=v)record[a] = min(record[a],seg[pos][left]);
                if(l==r)break;
                int mid =(l+r)>>1;
                if(mid<a){
                    
                    l = mid+1;pos = (pos<<1)+1;
                }else {

                    r = mid;pos <<=1;
                }

            }
           // cout<<"ith "<<i<<" house break at "<<record[a]<<endl;
            ans_list[record[a]]++;record[a] = i;
        }
        else {
            int a = query[i][1],b = query[i][2],v = query[i][3];
            for(a+=p-1,b+=p;a^b^1;a>>=1,b>>=1){
                if(~a&1){
                    while(seg[a^1].size()&&query[seg[a^1].back()][3]<=v)seg[a^1].pop_back();
                    seg[a^1].push_back(i);
                }
                if(b&1){
                    while(seg[b^1].size()&&query[seg[b^1].back()][3]<=v)seg[b^1].pop_back();
                    seg[b^1].push_back(i);
                }
            }
        }
    }
    for(int i=0;i<m;i++)if(query[i][0]==2)cout<<ans_list[i]<<endl;
    return 0;
}