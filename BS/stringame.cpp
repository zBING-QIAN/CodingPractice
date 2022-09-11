#include<bits/stdc++.h>
using namespace std;

bool isgood(string &t,string &p,string &buf,vector<int> &idx,int len){
    
    for(int i=0;i<=len;i++){t[idx[i]] = '?';}
    int j = 0;
    for(int i=0;i<t.size()&&j<p.size();i++){
        if(t[i]==p[j]){j++;}
    }//cout<<"j : "<<j<<" len :"<<len<<endl;
    for(int i=0;i<=len;i++){t[idx[i]] = buf[idx[i]];}
    return j == p.size();
}




int main(){
    string t,p,buf;
    cin>>t>>p;buf = t;
    vector<int> idx(t.size());
    if(t.size()==p.size()){cout<<t.size();return 0;}
    for(int i=0;i<idx.size();i++){cin>>idx[i];idx[i]--;}
    int l=0,r = idx.size()-1;
    while(l<r){
        int mid = (l+r)>>1;
        if(isgood(t,p,buf,idx,mid)){
            l = mid+1;
        }else r = mid;
    }
    cout<<l;
    return 0;
}