#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a,int b){
        if(a<b)swap(a,b);
        while(b){
            a%=b;swap(a,b);
        }
        return a;
    }

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int b=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            b = gcd(numsDivide[i],b);
            if(b==1)break;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()&&nums[i]<=b;i++){
            if((b%nums[i])==0)return i;
        }
        return -1;
    }
};