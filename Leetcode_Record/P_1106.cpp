#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void run(string &expr,int start,int &end,bool &rt){
        char op=0;
        for(int i=start;i<expr.size();i++){
            if(expr[i] == '|'||expr[i] == '&'||expr[i] == '!'){
                op=expr[i];
            }else if(expr[i]=='t'||expr[i]=='f'){
                end= i;rt=(expr[i]=='t')?1:0;
                return;
            }else if(expr[i]==','||expr[i]=='('){
                bool v;
                int tmp = i;
                run(expr,i+1,i,v);
                if(expr[tmp]=='('){
                    rt = v;
                }
                if(op == '|'){
                    rt |=v;
                }
                else if(op == '&'){
                    rt &=v;
                }
                else if(op == '!'){
                    rt = !v;
                }
                else {
                    assert(0);
                }

            }else if(expr[i]==')'){
                end = i;
                return;
            }
        }

    }



    bool parseBoolExpr(string expression) {
        bool ans;
        int end;
        run(expression,0,end,ans);
        return ans;
    }
};