#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // {mouse_pos,cat_pos}
    int rec[51][51];  // 2 die, 0 wait, 1 escape 
    void solve(vector<vector<int>> &graph){
        // cout<<m_pos<<" "<<c_pos<<endl;
        int glen = graph.size();
        for(int i=0;i<glen;i++)rec[0][i]=1;
        bool update = false;
        do{
            update = false;
            for(int mpos = 1;mpos<glen;mpos++){
                for(int cpos=1;cpos<glen;cpos++){
                    if(rec[mpos][cpos] != 0){continue;}
                    int die_cnt =0;
                    for(auto &mnxt : graph[mpos]){
                        if(mnxt==cpos){die_cnt++;continue;}
                        int state = 1;
                        for(auto &cnxt : graph[cpos]){
                            if(cnxt==0){continue;}
                            if(rec[mnxt][cnxt]!=1){
                                state = rec[mnxt][cnxt];
                                if(rec[mnxt][cnxt] == 2){die_cnt++;break;}
                            }

                        }
                        if(state==1){
                            update = true;
                            rec[mpos][cpos] = 1;
                            break;
                        }
                       
                    }

                    if(die_cnt==graph[mpos].size()){rec[mpos][cpos]=2;//cout<<m_pos<<" "<<c_pos<<"die\n";
                                                   update = true; }
                }
            }
            
        }while(update);
        
    }
    
    
    int catMouseGame(vector<vector<int>>& graph) {
        for(int i=0;i<51;i++)for(int j=0;j<51;j++)rec[i][j] = (i==j)?2:0;
        solve(graph);
        
        return rec[1][2];
    }
};