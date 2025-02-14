#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        set<pair<int,int>> lamp;
        vector<int>ans;
        map<int,set<pair<int,int>>> r,c,d,id;
        for(auto &l : lamps){
            pair<int,int> tmp = {l[0],l[1]};
            lamp.insert(tmp);
            if(r.find(l[0])==r.end())r[l[0]] = set<pair<int,int>>();
            if(c.find(l[1])==c.end())c[l[1]] = set<pair<int,int>>();
            if(d.find(l[0]-l[1])==d.end())d[l[0]-l[1]] = set<pair<int,int>>();
            if(id.find(l[0]+l[1])==id.end())id[l[0]+l[1]] = set<pair<int,int>>();
            r[l[0]].insert(tmp);c[l[1]].insert(tmp);d[l[0]-l[1]].insert(tmp);id[l[0]+l[1]].insert(tmp);
        }
        for(auto &l :queries){
            bool on = 1;
            if(r.find(l[0])==r.end()&&c.find(l[1])==c.end()&&d.find(l[0]-l[1])==d.end()&&id.find(l[0]+l[1])==id.end())on = 0;
            ans.push_back(on);
            for(int i=-1;i<2;i++){
                int x = i+l[0];
                if(x<0||x>=n)continue;
                for(int j=-1;j<2;j++){
                    int y = j+l[1];
                    pair<int,int> tmp = {x,y};
                    if(y<0||y>=n)continue;
                    if(lamp.find(tmp)!=lamp.end()){
                        r[x].erase(tmp);c[y].erase(tmp);d[x-y].erase(tmp);id[x+y].erase(tmp);
                        if(r[x].size()==0)r.erase(x);
                        if(c[y].size()==0)c.erase(y);
                        if(d[x-y].size()==0)d.erase(x-y);
                        if(id[x+y].size()==0)id.erase(x+y);
                        lamp.erase(tmp);
                    }
                }
            }
        }
        return ans;
    }
};