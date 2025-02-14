#include <bits/stdc++.h>
using namespace std;


class MajorityChecker {
public:
    map<int,vector<int>> rec;
    vector<vector<int>> cand;
    MajorityChecker(vector<int>& arr) {
        int n = arr.size();
        vector<int> nxt(2e4+1,0),remain(2e4+1,0);
        cand.resize(n,vector<int>());
        for(int i=0;i<n;i++){
            if(rec.find(arr[i])!=rec.end()){
                remain[arr[i]] = max(0,remain[arr[i]]-(i-rec[arr[i]].back()-1));
            }
            
            remain[arr[i]]++;
            rec[arr[i]].push_back(i);
            int next = max(nxt[arr[i]],i);
            for(;next<i+remain[arr[i]]&&next<n;next++){
                cand[next].push_back(arr[i]);
            }
            nxt[arr[i]]=next;

        }
    }
    
    int query(int left, int right, int threshold) {
        for(auto &c:cand[right]){
            // search 
            
            // if(left==6&&right==9&&threshold==3)cout<<c<<endl;
            auto &arr = rec[c];
            if(arr.size()<threshold)continue;
            int l = 0,r = arr.size();
            // find right pos
            while(l<r){
                int mid = (l+r)>>1;
                if(arr[mid]<=right){
                    l=mid+1;
                }else{
                    r=mid;
                }
            }
            l-=threshold;
            if(l>=0&&arr[l]>=left){return c;}
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */