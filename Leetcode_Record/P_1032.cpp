#include <bits/stdc++.h>
using namespace std;

class StreamChecker {
public:
    struct ACauto{
        bool isword;
        vector<int> nxt;
        int fp;
        ACauto(){isword = 0;nxt.resize(26,0);fp = 0;}

    };

    vector<ACauto> arr;
    int now = 0;
  

    StreamChecker(vector<string>& words) {
        arr.push_back(ACauto());
        for(auto &w:words){
            int cur = 0;
            for(auto c:w){
                if(arr[cur].nxt[c-'a']==0){
                    arr[cur].nxt[c-'a'] = arr.size();
                    arr.push_back(ACauto());     
                }  
                cur = arr[cur].nxt[c-'a'];
            }
            arr[cur].isword = 1;
        }   
        vector<int> que;que.push_back(0);
        for(int t=0;t<que.size();t++){
            int cur= que[t];
            for(int i=0;i<arr[cur].nxt.size();i++){
                int to = arr[cur].nxt[i];
                if(to==0)continue;
                int fp = arr[cur].fp;
                while(fp&&arr[fp].nxt[i]==0){
                    fp = arr[fp].fp;
                }
                if(to != arr[fp].nxt[i])arr[to].fp = arr[fp].nxt[i];
                arr[to].isword |= arr[arr[to].fp].isword;
                que.push_back(to);
            }
        }
    }
    
    bool query(char letter) {
        // cout<<"letter "<<letter<<endl;
        while(now>0&&arr[now].nxt[letter-'a']==0){
            // cout<<now<<" ";
            now = arr[now].fp;
        }
        now = arr[now].nxt[letter-'a'];
        // cout<<" end "<<now<<endl;
        return arr[now].isword;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */