#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> edge(n,vector<int>());
        for(auto &e:edges){
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        vector<int> first(n,-1),second(n,-1),third(n,-1);
        for(int i=0;i<n;i++){
            for(auto to:edge[i]){
                if(first[i] == -1)first[i]=to;
                else if(second[i]==-1)second[i] = to;
                else if(third[i] == -1)third[i] =to;
                else {
                    if(scores[third[i]]<scores[to])third[i] = to;
                }
                if(third[i]>=0&&scores[third[i]]>scores[second[i]])swap(third[i],second[i]);
                if(second[i]>=0&&scores[second[i]]>scores[first[i]])swap(first[i],second[i]);
                    
            }
        }
        int ans = -1;
        for(auto &e:edges){
            int a= e[0],b = e[1];
            int a1,b1;
            a1 = first[a];
            b1 = first[b];
            // cout<<a<<" a "<<first[a]<<" "<<second[a]<<" "<<third[a]<<endl;
            // cout<<b<<" b "<<first[b]<<" "<<second[b]<<" "<<third[b]<<endl;
            if(a!=b1&&b!=a1&&a1!=b1&&a1>=0&&b1>=0){
                
                // cout<<a1<<" "<<b1<<" "<<scores[a]<<" "<<scores[b]<<" "<<scores[a1]<<" "<<scores[b1]<<endl;
                int ans_tmp = scores[a]+scores[b]+scores[a1]+scores[b1];
                ans = max(ans_tmp,ans);
            }
            b1=second[b];
            if(a!=b1&&b!=a1&&a1!=b1&&a1>=0&&b1>=0){
                // cout<<a1<<" "<<b1<<" "<<scores[a]<<" "<<scores[b]<<" "<<scores[a1]<<" "<<scores[b1]<<endl;
                int ans_tmp = scores[a]+scores[b]+scores[a1]+scores[b1];
                ans = max(ans_tmp,ans);
            }
            b1 = third[b];
            if(a!=b1&&b!=a1&&a1!=b1&&a1>=0&&b1>=0){
                // cout<<a1<<" "<<b1<<" "<<scores[a]<<" "<<scores[b]<<" "<<scores[a1]<<" "<<scores[b1]<<endl;
                int ans_tmp = scores[a]+scores[b]+scores[a1]+scores[b1];
                ans = max(ans_tmp,ans);
            }
            a1 = second[a];
            b1 = first[b];
            if(a!=b1&&b!=a1&&a1!=b1&&a1>=0&&b1>=0){
                // cout<<a1<<" "<<b1<<" "<<scores[a]<<" "<<scores[b]<<" "<<scores[a1]<<" "<<scores[b1]<<endl;
                int ans_tmp = scores[a]+scores[b]+scores[a1]+scores[b1];
                ans = max(ans_tmp,ans);
            }
            b1=second[b];
            if(a!=b1&&b!=a1&&a1!=b1&&a1>=0&&b1>=0){
                // cout<<a1<<" "<<b1<<" "<<scores[a]<<" "<<scores[b]<<" "<<scores[a1]<<" "<<scores[b1]<<endl;
                int ans_tmp = scores[a]+scores[b]+scores[a1]+scores[b1];
                ans = max(ans_tmp,ans);
            }
            b1 = third[b];
            if(a!=b1&&b!=a1&&a1!=b1&&a1>=0&&b1>=0){
                // cout<<a1<<" "<<b1<<" "<<scores[a]<<" "<<scores[b]<<" "<<scores[a1]<<" "<<scores[b1]<<endl;
                int ans_tmp = scores[a]+scores[b]+scores[a1]+scores[b1];
                ans = max(ans_tmp,ans);
            }
            a1 = third[a];
            b1 = first[b];
            if(a!=b1&&b!=a1&&a1!=b1&&a1>=0&&b1>=0){
                // cout<<a1<<" "<<b1<<" "<<scores[a]<<" "<<scores[b]<<" "<<scores[a1]<<" "<<scores[b1]<<endl;
                int ans_tmp = scores[a]+scores[b]+scores[a1]+scores[b1];
                ans = max(ans_tmp,ans);
            }
            b1=second[b];
            if(a!=b1&&b!=a1&&a1!=b1&&a1>=0&&b1>=0){
                // cout<<a1<<" "<<b1<<" "<<scores[a]<<" "<<scores[b]<<" "<<scores[a1]<<" "<<scores[b1]<<endl;
                int ans_tmp = scores[a]+scores[b]+scores[a1]+scores[b1];
                ans = max(ans_tmp,ans);
            }
            b1 = third[b];
            if(a!=b1&&b!=a1&&a1!=b1&&a1>=0&&b1>=0){
                // cout<<a1<<" "<<b1<<" "<<scores[a]<<" "<<scores[b]<<" "<<scores[a1]<<" "<<scores[b1]<<endl;
                int ans_tmp = scores[a]+scores[b]+scores[a1]+scores[b1];
                ans = max(ans_tmp,ans);
            }
        }
        return ans;
    }
};