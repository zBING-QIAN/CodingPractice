#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find(vector<bool> &seg,int m, int a,int b){
        if(a>b)return 0;//cout<<a<<" "<<b<<" "<<m<<endl;
        a+=m-1;b+=m+1;
        while((a>>1)!=(b>>1)){
            // cout<<a<<" "<<b<<" "<<seg[b^1]<<" "<<seg[a^1]<<endl;
            if(b&1)if(seg[b^1])return 1;
            if(~a&1)if(seg[a^1])return 1;
            a>>=1;b>>=1;
        }
        return 0;
    }

    bool check(int a, int b,int c,int d, int n,vector<vector<int>> &cnt,vector<bool> &seg,int m){
        int _c = n-b-1,_d=n-a-1,_a=n-d-1, _b = n-c-1;
        //check fix area by segtree
        int fix_a = (_a<a)?_a:max(b+1,_a),fix_b = (_b>b)?_b:min(_b,a-1);
        int fix_c = (_c<c)?_c:max(d+1,_c),fix_d = (_d>d)?_d:min(_d,c-1);
        // cout<<"case "<<fix_a<<" "<<fix_b<<" "<<fix_c<<" "<<fix_d<<endl;
        for(int i=0;i<26;i++){
            if(fix_b>=fix_a&&cnt[i][fix_b+1]-cnt[i][fix_a]>cnt[i][d+1]-cnt[i][c]){return 0;}

            // cout<<fix_a<<" "<<fix_b<<" "<<cnt[i][fix_b+1]-cnt[i][fix_a]<<" "<<cnt[i][d+1]-cnt[i][c]<<endl;
            if(fix_d>=fix_c&&cnt[i][fix_d+1]-cnt[i][fix_c]>cnt[i][b+1]-cnt[i][a]){return 0;}

            // cout<<fix_c<<" "<<fix_d<<" "<<cnt[i][fix_d+1]-cnt[i][fix_c]<<" "<<cnt[i][b+1]-cnt[i][a]<<endl;
            int left_cnt = cnt[i][b+1]-cnt[i][a];
            if(fix_b>=fix_a){
                if(fix_a<a&&fix_b>b)left_cnt = cnt[i][fix_b+1]-cnt[i][fix_a];
                else left_cnt+=cnt[i][fix_b+1]-cnt[i][fix_a];
            }
            int right_cnt = cnt[i][d+1]-cnt[i][c]; 
            if(fix_d>=fix_c){
                if(fix_d>d&&fix_c<c)right_cnt=cnt[i][fix_d+1]-cnt[i][fix_c];
                else right_cnt+=cnt[i][fix_d+1]-cnt[i][fix_c];
            }
            // cout<<left_cnt<<" "<<right_cnt<<endl;
            if(left_cnt!=right_cnt)return 0;

        }
        // cout<<"check find\n";
        if(find(seg,m,0,min(a,_a)-1))return 0;
        if(find(seg,m,max(b,_b)+1,n/2-1))return 0;
        if(find(seg,m,min(b,_b)+1,max(a,_a)-1))return 0;

        // cout<<"end find\n";
        return 1;
    }


    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.size(),m=1;while(m<n)m<<=1;
        vector<bool> ans,seg((m<<1),0);
        for(int i =0;i<n;i++)seg[m+i] = (s[i]!=s[n-i-1]);
        
        for(int i=m-1;i>0;i--)seg[i] =  seg[(i<<1)]|seg[(i<<1)^1];
        vector<vector<int>> cnt(26,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                cnt[j][i+1] = cnt[j][i]+(s[i]-'a'==j);
            }
        }
        
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0],b=queries[i][1],c=queries[i][2],d=queries[i][3];
            ans.push_back(check(a,b,c,d,n,cnt,seg,m));
        }

        return ans;
    }
};