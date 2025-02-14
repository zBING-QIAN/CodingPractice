#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    string reduce(string board,int pos){
        int len = board.size();
        for(int i=pos,j=pos,cnt = 1;;){
            int l=i-1,r=j+1;
            while(l>=0 &&board[l]==board[i]){l--;cnt++;}
            while(r<len&&board[r]==board[j]){r++;cnt++;}
            if(cnt>=3){
                i=l,j=r;
            }
                   
            if(j-i>3){ 
                if(cnt<3||i<0||j>=len||board[i]!=board[j]){
                    return board.substr(0,i+1)+board.substr(j);
                }
                cnt=2;
               
            }else return board;
        }
        return "";
    }


    int findMinStep(string board, string hand) {
        int ans = 0;
        sort(hand.begin(),hand.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(board+"#"+hand);
        while(q.size()>0){
            int n = q.size();
            for(int i=0;i<n;i++){
                string cur = q.front();
                q.pop();
                int tmp = cur.find("#");
                string b = cur.substr(0,tmp);
                string h = cur.substr(tmp+1);
                for(int j=0;j<b.size();j++){
                    for(int k=0;k<h.size();k++){
                        if(b[j]!=h[k])
                            if(j>0&&b[j]!=b[j-1])continue;
                            
                        string newboard = reduce(b.substr(0,j)+h[k]+b.substr(j),j);
                        string newhand = h.substr(0,k)+h.substr(k+1);
                        if(newboard=="")return ans+1;
                        string newstate = newboard+"#"+newhand;
                        if(visited.find(newstate)==visited.end()){visited.insert(newstate);q.push(newstate);}
                    }

                }

            }
            ans++;
        }




        return -1;
    }
};
