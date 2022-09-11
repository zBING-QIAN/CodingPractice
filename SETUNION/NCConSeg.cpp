#include<bits/stdc++.h>
using namespace std;
vector<array<int,2>> oper;
vector<array<int,3>> qry;
vector<int> team;
vector<int> epoch;
vector<int> ans;
vector<vector<vector<int>>> checkpoint;

int leader(int a,vector<int> &rec){
    rec.push_back(a);
    if(team[a] != a){
        team[a] = leader(team[a],rec);
    }else{
        rec.push_back(a);
    }
    return team[a];
}
void rollback(){
    for(int t=checkpoint.back().size()-1;t>=0;t--){
        vector<int> *vec = &checkpoint.back()[t];
        int s = vec->size()-1;
        for(int i=0;i<s;i++){
            team[(*vec)[i]] = (*vec)[i+1];
        }
    }checkpoint.pop_back();
    epoch.pop_back();
}
void solve(int l,int r,bool addnew=true){
    if(addnew){checkpoint.push_back(vector<vector<int>>());epoch.push_back(epoch.back());}
    for(int i=l;i<r;i++){
        checkpoint.back().push_back(vector<int>());
        checkpoint.back().back().reserve(20);   //important
        int t1 = leader(oper[i][0],checkpoint.back().back());
        checkpoint.back().push_back(vector<int>());
        checkpoint.back().back().reserve(20);   //important
        int t2 = leader(oper[i][1],checkpoint.back().back());
        if(t1!=t2){
            team[t1] = t2;epoch.back()--;
        }
    }
    //cout<<l<<" "<<r<<" result : "<<epoch.back()<<endl;
}


int main(){
    int m,n,k,a,b;
    cin>>n>>m;
    oper.push_back({0,0});
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        oper.push_back({a,b});
    }
    cin>>k;
    for(int t=0;t<k;t++){
        scanf("%d %d",&a,&b);
        qry.push_back({a,b+1,t});
    }
    int sqm = (int)sqrt(m);
    //cout<<"sqm : "<<sqm<<endl;
    sort(qry.begin(),qry.end(),[sqm](auto a,auto b){
        int t1 =a[0]/sqm,t2 = b[0]/sqm; 
        return (t1<t2)||(t1==t2&&a[1]<b[1]);
    });
    ans.resize(k,n);team.resize(n+1);
    for(int i=0;i<=n;i++)team[i] = i;
    checkpoint.push_back(vector<vector<int>>());
    epoch.push_back(n);
    for(int i=0,j=0;i<k;i++){
        //cout<<"qry :"<<qry[i][2]<<" : "<<qry[i][0]<<" "<<qry[i][1]<<endl;
        while(qry[i][0]>=j*sqm){j++;while(checkpoint.size()>1)rollback();}
        if(qry[i][1]>sqm*(j)){
            if(checkpoint.size()>1){solve(qry[i-1][1],qry[i][1]);}
            else solve((j)*sqm,qry[i][1]);
            solve(qry[i][0],(j)*sqm);
            ans[qry[i][2]] = epoch.back();
            //cout<<qry[i][2]<<" "<<ans[qry[i][2]]<<endl;
            rollback();
        }else{
            solve(qry[i][0],qry[i][1]);
            ans[qry[i][2]] = epoch.back();
            while(i<k-1&&(qry[i+1][0]<=qry[i][0]&&qry[i][1]<=qry[i+1][1])){
                i++;
                //cout<<"modify :"<<qry[i][0]<<" "<<qry[i][1]<<endl;
                solve(qry[i][0],qry[i-1][0],false);
                solve(qry[i-1][0],qry[i][1],false);
                ans[qry[i][2]] = epoch.back();
            }
            //cout<<qry[i][2]<<" "<<ans[qry[i][2]]<<endl;
            rollback();            
        }
    }

    for(int i=0;i<k;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}