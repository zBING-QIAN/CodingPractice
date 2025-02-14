#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(int a){
        vector<int> out(6,0);
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                out[i*3+j]=a%10;
                a/=10;
            }
        }
        return out;
    }
    int encode(vector<int> &board){
        int out=0;
        
        for(int j=5;j>=0;j--){
            out*=10;
            out+=board[j];
        }
        
        return out;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {      
        map<int,int> rec;
        vector<int> que;
        int target=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                target*=10;target+=board[i][j];
            }
        }
        // cout<<"target "<<target<<endl;
        int d = 123450,flag = 0;
        rec[d] = 0;
        que.push_back(d);
        while(que.size()>flag){
            if(rec.find(target)!=rec.end())return rec[target];
            // cout<<que[flag]<<endl;
            auto b = decode(que[flag]);
            int cur = rec[que[flag]];
            int p = 0;
            for(int i=0;i<6;i++){
                if(b[i]==0){p=i;break;}
            }
            if(p<3){
                auto tmp = b;
                swap(tmp[p],tmp[p+3]);
                int o = encode(tmp);
                if(rec.find(o)==rec.end()){
                    rec[o] = cur+1;
                    que.push_back(o);
                }
            }

            if(p>=3){
                auto tmp = b;
                swap(tmp[p],tmp[p-3]);
                int o = encode(tmp);
                if(rec.find(o)==rec.end()){
                    rec[o] = cur+1;
                    que.push_back(o);
                }
            }

            if((p%3)>0){
                auto tmp = b;
                swap(tmp[p],tmp[p-1]);
                int o = encode(tmp);
                if(rec.find(o)==rec.end()){
                    rec[o] = cur+1;
                    que.push_back(o);
                }
            }
            
            if((p%3)<2){
                auto tmp = b;
                swap(tmp[p],tmp[p+1]);
                int o = encode(tmp);
                if(rec.find(o)==rec.end()){
                    rec[o] = cur+1;
                    que.push_back(o);
                }
            }

            
            flag++;

        }
        
        return -1;
    }
};