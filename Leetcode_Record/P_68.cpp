#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<int> buf;
        int cur_len=0;
        for(int i=0;i<=words.size();i++){
            auto &w = words[i];
            if(i==words.size()||cur_len+w.size()+(buf.size()>0)>maxWidth){
                bool left = (i==words.size())||(buf.size()==1);
                int space_num = maxWidth-cur_len+buf.size()-1;
                // cout<<space_num<<" "<<cur_len<<" "<<buf.size()<<endl;
                int sp_avg = (left)?0:space_num/(buf.size()-1);
                int rm_cnt = (left)?space_num:space_num%(buf.size()-1);
                string cur=words[buf[0]];
                for(int j=1;j<buf.size();j++){
                    for(int k =0;k<sp_avg+(rm_cnt>0);k++)cur+=" ";
                    rm_cnt--;
                    
                    cur+=words[buf[j]];
                    
                }
                for(int k=0;k<rm_cnt;k++)cur+=" ";
                ans.push_back(cur);
                buf.clear();cur_len=0;
            }
            if(i<words.size()){
                buf.push_back(i);
                cur_len+=w.size();
                if(buf.size()>1)cur_len++;
            }
        }
        return ans;
    }
};