#include<bits/stdc++.h>
using namespace std;
vector<int> team;
vector<int> epoch;
vector<vector<vector<int>>> checkpoint;
map<int,int>ans;
int leader(int a,vector<int> &rec){
    rec.push_back(a);
    if(team[a]!=a){
        team[a] = leader(team[a],rec);
    }else {
        rec.push_back(a);
    }
    return team[a];
}
void join(int a,int b){
    checkpoint.back().push_back(vector<int>());
    int t1 = leader(a,checkpoint.back().back());
    checkpoint.back().push_back(vector<int>());
    int t2 = leader(b,checkpoint.back().back());
    if(t1!=t2){
        team[t2] = t1;epoch.back()--;
    }
}
void rollback(){
    for(int t=checkpoint.back().size()-1;t>=0;t--){
        vector<int> *tmp = &checkpoint.back()[t];
        int s = tmp->size()-1;
        for(int i=0;i<s;i++)team[(*tmp)[i]] = (*tmp)[i+1];
    }checkpoint.pop_back();epoch.pop_back();
}
void solve(int l,int r,vector<array<int,4>> &oper){
    epoch.push_back(epoch.back());
    checkpoint.push_back(vector<vector<int>>());
    if(l==r-1){//cout<<"l r "<<l<<" "<<r<<endl;
        bool output = false;
        for(auto op : oper){
            if(op[0]<=l&&op[1]>=r){
                if(op[2]!=-1){join(op[2],op[3]);}//cout<<op[0]<<" "<<op[1]<<" join "<<op[2]<<" "<<op[3]<<endl;
            }
            //cout<<op[0]<<" "<<op[1]<<" "<<op[2]<<" "<<op[3]<<endl;
            if(op[2]==-1&&op[0]==l){
                output = true;
            }
        }
        if(output)ans[l] = epoch.back();
        rollback();
        return;
    }
    
    vector<array<int,4>> opertmp;
    for(auto op : oper){
        if(op[0]<=l&&op[1]>=r){
            if(op[2]!=-1){join(op[2],op[3]);}//cout<<op[0]<<" "<<op[1]<<" join "<<op[2]<<" "<<op[3]<<endl;
        }else if((op[0]<r&&op[0]>=l)||(op[1]<=r&&op[1]>l)){
            opertmp.push_back(op);
        }
    }//cout<<"l r "<<l<<" "<<r<<" epoch "<<epoch.back()<<endl;
    int mid = (l+r)>>1;
    solve(l,mid,opertmp);
    solve(mid,r,opertmp);
    rollback();
}

int main(){
    vector<array<int,4>> oper;
    int n,m,a,b;
    char op[2];
    cin>>n>>m;
    map<array<int,2>,int> rec;
    team.resize(n+1);
    
    epoch.push_back(n);
    checkpoint.push_back(vector<vector<int>>());
    for(int i=0;i<=n;i++)team[i] = i;
    for(int i=0;i<m;i++){
        scanf("%s",op);
        if(op[0]=='?'){
            oper.push_back({i,i,-1,-1});
        }
        else{
            scanf("%d %d",&a,&b);
            if(a>b)swap(a,b);
            if(op[0]=='+'){
                rec[{a,b}] = i;
            }else{
                oper.push_back({rec[{a,b}],i,a,b});
                rec.erase({a,b});
            }
        }
    }
    for(auto item :rec){
        oper.push_back({item.second,m,item.first[0],item.first[1]});
    }rec.clear();
    //cout<<"oper size"<<oper.size()<<"  ";
    // for(int i=0;i<oper.size();i++){
    //     for(int j=0;j<4;j++)cout<<oper[i][j]<<" ";cout<<endl;
    // }
    if(n==1){
        for(int i=0;i<oper.size();i++){
            if(oper[i][2]==-1)printf("%d\n",1);
        }
        return 0;
    }
    solve(0,m,oper);
    for(auto tmp :ans){
        printf("%d\n",tmp.second);
    }
    return 0;
}