#include <bits/stdc++.h>
using namespace std;
class Solution {
public:


    bool isNumber(string s) {
        bool good = 0;
        int state = 0;
        for(int i=0;i<s.size();i++){
            if(state==0){
                if(s[i] == '+'||s[i] == '-'){state = 1;}
                else if(s[i]-'0'>=0&&s[i]-'0'<10){state = 2;good = 1;}
                else if(s[i]=='.')state = 3;
                else if(s[i]=='E'||s[i]=='e')state = -1;
                else state = -1;
            }else
            if(state==1){
                if(s[i] == '+'||s[i] == '-'){state = -1;good = 0;}
                else if(s[i]-'0'>=0&&s[i]-'0'<10){state = 2;good = 1;}
                else if(s[i]=='.')state = 3;
                else if(s[i]=='E'||s[i]=='e'){state = -1;good = 0;}
                else {state = -1;good = 0;}
            }else
            if(state==2){
                if(s[i] == '+'||s[i] == '-'){state = -1;good = 0;}
                else if(s[i]-'0'>=0&&s[i]-'0'<10)state = 2;
                else if(s[i]=='.')state = 3;
                else if(s[i]=='E'||s[i]=='e'){state = 4;good = 0;}
                else {state = -1;good = 0;}
            }else
            if(state==3){
                if(s[i] == '+'||s[i] == '-'){state = -1;good = 0;}
                else if(s[i]-'0'>=0&&s[i]-'0'<10){state = 7;good = 1;}
                else if(s[i]=='.'){state = -1;good = 0;}
                else if(s[i]=='E'||s[i]=='e'){
                    if(good)state = 4;
                    else state = -1;
                    good = 0;
                }
                else {state = -1;good = 0;}
            }else
            if(state==4){
                good = 0;
                if(s[i] == '+'||s[i] == '-'){state = 5;good = 0;}
                else if(s[i]-'0'>=0&&s[i]-'0'<10){state = 6;good = 1;}
                else if(s[i]=='.'){state = -1;good = 0;}
                else if(s[i]=='E'||s[i]=='e'){state = -1;good = 0;}
                else {state = -1;good = 0;}
            }else
            if(state==5){
                good = 0;
                if(s[i] == '+'||s[i] == '-'){state = -1;good = 0;}
                else if(s[i]-'0'>=0&&s[i]-'0'<10){state = 6;good = 1;}
                else if(s[i]=='.'){state = -1;good = 0;}
                else if(s[i]=='E'||s[i]=='e'){state = -1;good = 0;}
                else {state = -1;good = 0;}
            }else
            if(state==6){
                if(s[i] == '+'||s[i] == '-'){state = -1;good = 0;}
                else if(s[i]-'0'>=0&&s[i]-'0'<10){state = 6;}
                else if(s[i]=='.'){state = -1;good = 0;}
                else if(s[i]=='E'||s[i]=='e'){state = -1;good = 0;}
                else {state = -1;good = 0;}
            }else if(state==7){
                if(s[i] == '+'||s[i] == '-'){state = -1;good = 0;}
                else if(s[i]-'0'>=0&&s[i]-'0'<10){state = 7;}
                else if(s[i]=='.'){state = -1;good = 0;}
                else if(s[i]=='E'||s[i]=='e'){
                    if(good)state = 4;
                    else state = -1;
                    good = 0;
                }
                else {state = -1;good = 0;}
            }
            else {good = 0;break;}
            // cout<<i<<" "<<s[i]<<" "<<state<<" "<<good<<endl;
        }
        return good;
    }
};