#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<int> list(row.size(),-1);
        for(int i=0;i<row.size();i++){
            list[row[i]]=i; 
        }
        int ans=0;
        for(int i=0;i<row.size();i+=2){
            if(row[i+1]/2==row[i]/2)continue;
            ans++;
            int tmp=(row[i]%2)?row[i]-1:row[i]+1;
            swap(row[i+1],row[list[tmp]]);
            swap(list[row[i+1]],list[row[list[tmp]]]); 
        }
        return ans;
    }
};