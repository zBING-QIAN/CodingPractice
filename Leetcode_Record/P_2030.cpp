#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sss(string &s,int k,vector<int>&out,char letter,int rep){
        vector<int> pre(s.size(),-1),post(s.size(),-1);
        int letter_cnt = s[0]==letter;
        set<int> tank;tank.insert(0);
        priority_queue<int,vector<int>,std::greater<int>> pq;
        vector<int> letter_remain(s.size()+1,0);
        for(int i=0;i<s.size();i++)if(s[i]==letter)letter_remain[i]=1;
        for(int i=s.size()-1;i>=0;i--)letter_remain[i]+=letter_remain[i+1];
        
        set<int> no_letter_pos;
        if(s[0]!=letter)no_letter_pos.insert(0);
        for(int i=1;i<k;i++){
            if(s[i]!=letter)no_letter_pos.insert(i);
            pre[i]=i-1;
            post[i-1] = i;
            if(s[i]<s[i-1]){
                pq.push(i-1);
            }
            tank.insert(i);
            if(s[i]==letter)letter_cnt++;
        }
        for(int i=k;i<s.size();i++){
            pre[i]=*tank.rbegin();
            post[pre[i]]=i;
            if(s[i]<s[pre[i]]){ 
                pq.push(pre[i]);
            }
            if(letter_cnt+letter_remain[i]==rep){
                while(pq.size()&&s[pq.top()]==letter){
                    pq.pop();    
                }
                if(pq.size()==0&&s[i]==letter&&no_letter_pos.size())
                    pq.push((*no_letter_pos.rbegin()));
            }
           
            if(pq.size()>0){
                int rp =pq.top();
                pq.pop();
                if(pre[rp]>=0)post[pre[rp]]=post[rp];
                if(post[rp]>=0)pre[post[rp]]=pre[rp];
                if(pre[rp]>=0&&post[rp]>=0&&s[pre[rp]]>s[post[rp]]){
                    pq.push(pre[rp]);
                }
                tank.erase(rp);
                if(s[rp]==letter)letter_cnt--;
                no_letter_pos.erase(rp);
                tank.insert(i);
                if(s[i]==letter)letter_cnt++;
                if(s[i]!=letter)no_letter_pos.insert(i);
                
            }

        }
        for(auto c:tank)out.push_back(c);
    }


    string smallestSubsequence(string s, int k, char letter, int repetition) {
        string ans = "";
        vector<int> idx;
        sss(s,k,idx,letter,repetition);
        int letter_cnt=0;
        // sort(idx.begin(),idx.end());

        for(auto i:idx){ans+=s[i];}return ans;
    }
};