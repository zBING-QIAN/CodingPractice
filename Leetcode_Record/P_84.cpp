#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        vector<int> x,y;x.push_back(0);y.push_back(heights[0]);
        int ans = 0;
        for(int i=1;i<heights.size();i++){
            int prex = i;
            while(y.size()>0&&y.back()>heights[i]){
                int tmp = (i-x.back())*y.back();//cout<<i<<" "<<x.back()<<" "<<y.back()<<" "<<tmp<<endl;
                ans = max(tmp,ans);prex = x.back();y.pop_back();x.pop_back();
            }
            x.push_back(prex);y.push_back(heights[i]);
            
            
            
        }
        return ans;
    }
};