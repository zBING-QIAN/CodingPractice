#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long left=0,right= 1e15;
        long long range_sum = 0;
        vector<long long> power(stations.size());
        for(int i=0;i<stations.size();i++){
            range_sum+=stations[i];
            if(i>r)range_sum-=stations[i-r-1];
            power[i]+=range_sum;
        }
        range_sum=0;
        for(int i=stations.size()-1;i>=0;i--){
            if(i+r+1<stations.size())range_sum-=stations[i+r+1];
            power[i]+=range_sum;
            range_sum+=stations[i];
        }
        while(left<right){
            long long mid = (left+right)>>1;
            long long tmp = 0,add=0;
            queue<long long> que;
            bool good=1;
            for(int i=0;i<power.size();i++){

                long long dif = (mid-power[i]-add>0)?mid-power[i]-add:0;
                add+=dif;tmp+=dif;
                que.push(dif);
                if(que.size()>r*2){add-=que.front();que.pop();}
                if(tmp>k){good=0;break;}
                
            }
            if(good)left=mid+1;
            else right = mid;
        }

        return right-1;
    }
};