#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> stac_h,stac_x;stac_h.push_back(height[0]),stac_x.push_back(0);
        int ans = 0;
        for(int i=1;i<height.size();i++){
            while(stac_h.size()&&stac_h.back()<=height[i]){
                int bottom =stac_h.back();
                stac_h.pop_back(),stac_x.pop_back();
                if(stac_h.size()==0)break;
                int h = min(height[i],stac_h.back())-bottom;
                int len = i-stac_x.back()-1;
                ans += h*len;
            }
            if(stac_h.size()==0||height[i]<stac_h.back()){stac_h.push_back(height[i]);stac_x.push_back(i);}
        }
        return ans;
    }
};