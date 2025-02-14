#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0;
        int l=0,r=fruits.size()-1;
        while(l<r){
            int mid = (l+r)>>1;
            if(fruits[mid][0]<startPos)l = mid+1;
            else r = mid;
        }
        int start = l,end  =l;
        if(fruits[start][0]>=startPos)start--;
        else end++;
        for(;end>=0&&end<fruits.size()&&fruits[end][0]<=startPos+k;end++){
            ans += fruits[end][1];
        }
        end--;
        int anstmp = ans;
        for(;start>=0;start--){
            while(end>start&&fruits[end][0]-fruits[start][0]+(startPos-fruits[start][0]) >k){
                anstmp-=fruits[end][1];end--;
                assert(anstmp>=0); 
            }
            if(startPos<=fruits[end][0]){
                anstmp += fruits[start][1];
                // cout<<start<<" "<<end<<" "<<anstmp<<endl;
                ans = max(ans,anstmp);
            }else break;
        }
        
        start = l,end  =l;
        
        if(fruits[start][0]>=startPos)start--;
        else end++;
        anstmp = 0;
        for(;start>=0&&fruits[start][0]+k>=startPos;start--){
            anstmp += fruits[start][1];
        }
        ans = max(ans,anstmp);
        start++;
        for(;end<fruits.size();end++){
            while(end>start&&fruits[end][0]-fruits[start][0]+(fruits[end][0]-startPos) >k){
                anstmp-=fruits[start][1];start++;
                assert(anstmp>=0); 
            }
            if(startPos>=fruits[start][0]){
                anstmp += fruits[end][1];
                // cout<<start<<" "<<end<<" "<<anstmp<<endl;
                ans = max(ans,anstmp);
            }else break;
        }
        return ans;
    }
};