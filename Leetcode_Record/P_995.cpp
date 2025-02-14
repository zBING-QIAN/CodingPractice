#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setRange(vector<int> &seg,int cur,int left,int right,int l,int r){
        if(left>=l&&right<=r){seg[cur]++;return;}
        int mid = (right+left)>>1;
        if(l<=mid)setRange(seg,cur<<1,left,mid,l,min(mid,r));
        if(r>mid)setRange(seg,(cur<<1)+1,mid+1,right,max(mid+1,l),r);
    }
    int search(vector<int>&seg,int cur){
        int sum = 0;
        while(cur){sum+=seg[cur];cur>>=1;}
        return sum;
    }
    int minKBitFlips(vector<int>& nums, int k) {
        int ans =0,n=1;
        for(;n<nums.size();n<<=1);
        vector<int> seg(n<<1,0);
        for(int i=0;i<nums.size();i++)seg[i+n]=nums[i];
        for(int i=0;i+k-1<nums.size();i++){
            if(search(seg,i+n)&1);
            else {setRange(seg,1,0,n-1,i,i+k-1);ans++;}
        }
        for(int i=nums.size()-k;i<nums.size();i++){
            if(i<0)i=0;
            if(search(seg,i+n)&1)continue;
            else return -1;
        }
        return ans;
    }
};