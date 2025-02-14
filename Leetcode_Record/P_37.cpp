#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<vector<bool>>> choice;
    vector<pair<int,int>> loc;
    bool dfs(int id,vector<vector<char>> &board){
        if(id == loc.size())return true;
        int x = loc[id].first,y=loc[id].second;
        int row9 = (x/3)*3,col9 = (y/3)*3;
        for(int i=0;i<9;i++){
            vector<int>r,c,d;
            if(choice[x][y][i]){
                for(int j=0;j<9;j++){
                    if(choice[x][j][i]){choice[x][j][i]=0;c.push_back(j);}
                    if(choice[j][y][i]){choice[j][y][i]=0;r.push_back(j);}
                    if(choice[row9+j/3][col9+j%3][i]){
                        choice[row9+j/3][col9+j%3][i] = 0;d.push_back(j);
                    }
                }
                board[x][y] = '1'+i;
                if(dfs(id+1,board))return true;
                else {
                    board[x][y] = '.';
                    for(auto j :c){
                        choice[x][j][i]=1;}
                    for(auto j :r){
                        choice[j][y][i]=1;}
                    for(auto j :d){
                            choice[row9+j/3][col9+j%3][i] = 1;
                    }
                }
            }
            
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        choice.resize(9,vector<vector<bool>>(9,vector<bool>(9,1)));
        for(int i=0;i<9;i++)for(int j=0;j<9;j++){
            if(board[i][j] != '.'){
                for(int k=0;k<9;k++){
                    choice[i][k][board[i][j]-'1'] = 0;
                    choice[k][j][board[i][j]-'1'] = 0;
                    choice[(i/3)*3+k/3][(j/3)*3+k%3][board[i][j]-'1']=0;
                }
            }else {loc.push_back({i,j});}
        }
        dfs(0,board);
    }
};