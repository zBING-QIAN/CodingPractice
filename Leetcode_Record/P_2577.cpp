#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct heap{
        vector<array<int,3>> h;
        heap(){
            h.push_back({0,0,0});
        }
        array<int,3> top(){return h[1];}
        void insert(array<int,3> key){
            int par = h.size()>>1,now = h.size();
            h.push_back(key);
            while(par&&h[par]>h[now]){
                swap(h[par],h[now]);
                now = par;par = (now>>1);
            }
        }
        void pop(){
            // swap(h.back(),h[1]);
            h[1] = h.back();
            int now = 1,son = 2;
            while(son<h.size()){
                if(son+1<h.size()&&h[son]>h[son+1])son++;
                if(h[now]>h[son]){
                    swap(h[now],h[son]);
                    now = son;son = now<<1;
                }else {break;}
            }
            h.pop_back();
        }
        int size(){return h.size();}
    };
    
    int minimumTime(vector<vector<int>>& grid) {
        if((grid.size()==1||grid[1][0]>1)&&(grid[0].size()==1||grid[0][1]>1))return -1;
        heap pq;pq.insert({0,0,0});
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0)),rec(grid.size(),vector<int>(grid[0].size(),1e9));
        rec[0][0]=0;
        visited[0][0]=0;
        int flag=  0;
        while(pq.size()>1){
            // cout<<pq.size()<<endl;
            auto [k,x,y] = pq.top();
            // cout<<x<<" "<<y<<" "<<k<<endl;
            if(visited[x][y]==2){pq.pop();continue;}
            visited[x][y] = 2;
            rec[x][y] = k;
            if(x&&visited[x-1][y]==0){
                if(k+1<=grid[x-1][y]){
                    int ktmp = grid[x-1][y];
                    if((k&1)==(grid[x-1][y]&1)){
                        ktmp++;
                    }
                    rec[x-1][y] = ktmp;
                    pq.insert({ktmp,x-1,y});rec[x-1][y] = ktmp;
                }else{
                    if(rec[x-1][y] > k+1){
                        pq.insert({k+1,x-1,y});
                        rec[x-1][y] = k+1;
                    }
                }
            }
            if(x<visited.size()-1&&visited[x+1][y]==0){
                if(k+1<=grid[x+1][y]){
                    int ktmp = grid[x+1][y];
                    if((k&1)==(grid[x+1][y]&1)){
                        ktmp++;
                    }
                    pq.insert({ktmp,x+1,y});rec[x+1][y] = ktmp;
                }else{
                    if(rec[x+1][y] > k+1){
                        pq.insert({k+1,x+1,y});
                        rec[x+1][y] = k+1;
                    }
                }
            }
            if(y&&visited[x][y-1]==0){
                if(k+1<=grid[x][y-1]){
                    int ktmp = grid[x][y-1];
                    if((k&1)==(grid[x][y-1]&1)){
                        ktmp++;
                    }
                    pq.insert({ktmp,x,y-1}); rec[x][y-1] = ktmp;
                }else{
                    if(rec[x][y-1] > k+1){
                        pq.insert({k+1,x,y-1});
                        rec[x][y-1] = k+1;
                    }
                }
            }
            if(y<visited[0].size()-1&&visited[x][y+1]==0){
                if(k+1<=grid[x][y+1]){
                    int ktmp = grid[x][y+1];
                    if((k&1)==(grid[x][y+1]&1)){
                        ktmp++;
                    }
                     rec[x][y+1] = ktmp;
                    pq.insert({ktmp,x,y+1});
                }else{
                    if(rec[x][y+1] > k+1){
                        pq.insert({k+1,x,y+1});
                        rec[x][y+1] = k+1;
                    }
                }
            }
            // if(pq.size()<20){
            //     cout<<"before ";
            //     for(auto [k,x,y]:pq.h){
            //         cout<<k<<" "<<x<<" "<<y<<endl  ;  
            //     }
            // }
            pq.pop();
            // if(pq.size()<20){
            //     cout<<"after ";
            //     for(auto [k,x,y]:pq.h){
            //         cout<<k<<" "<<x<<" "<<y<<endl    ;
            //     }
            // }
        }
        return rec.back().back();
    }
};