#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> bar;
    void setup(int n){
        bar.resize(n+1,1);
        for(int i=1;i<=n;i++){
            bar[i] = bar[i-1]*i;
        }
    }
    string solve(int n,int k,vector<char> clist){
        string ans = "";k--;
        for(int i=1;i<n;i++){
            if(bar[n-i]<=k){
                int l = k/bar[n-i];
                if(l>n-i)l=n-i;cout<<k<<" "<<l<<" "<<n-i<<endl;
                k -= l*bar[n-i];
                // cout<<k<<endl;
                // assert(l<n-i+1);
                for(int p=i+l-1;p>=i;p--)swap(clist[p],clist[p-1]); for(auto c : clist)cout<<c<<" ";cout<<endl;
            }
        }
        for(auto c : clist)ans+=c;//{ans+=c;cout<<c<<" ";}cout<<endl;
        return ans;
    }
    string getPermutation(int n, int k) {
        setup(n);
        vector<char> clist;for(int i=0;i<n;i++)clist.push_back('1'+i);
        return solve(n,k,clist);
    }
};