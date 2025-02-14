#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> idx(nums1.size());for(int i=0;i<nums1.size();i++)idx[i]=i;
        vector<int> qidx(queries.size());for(int i=0;i<queries.size();i++)qidx[i]=i;
        sort(idx.begin(),idx.end(),[&](auto &a,auto &b){return nums1[a]<nums1[b];});
        sort(qidx.begin(),qidx.end(),[&](auto &a,auto &b){return queries[a][1]<queries[b][1];});
        vector<pair<int,int>> contour,cand;
        contour.push_back({nums1[idx.back()],0});
        
        for(int i=idx.size()-1;i>=0;i--){
            if(contour.back().second<nums2[idx[i]]){
                if(contour.back().first>nums1[idx[i]]){
                    contour.push_back({nums1[idx[i]],nums2[idx[i]]});

                }else{
                    assert(contour.back().first==nums1[idx[i]]);
                    contour.back().second = nums2[idx[i]];

                }
            }
        }
        cand.push_back({contour[0].first,contour[0].first+contour[0].second});
        for(int i=1;i<contour.size();i++){
            if(contour[i].first+contour[i].second>cand.back().second)cand.push_back({contour[i].first,contour[i].first+contour[i].second});
        }
        reverse(cand.begin(),cand.end());
        reverse(contour.begin(),contour.end());
        vector<int> jumper(contour.size(),-1),stac;
        // build jumper
        for(int i=contour.size()-1;i>=0;i--){
            while(stac.size()&&contour[stac.back()].second+contour[stac.back()].first<=contour[i].second+contour[i].first){
                jumper[stac.back()] = i;stac.pop_back();
            }
            stac.push_back(i);
        }
        // cout<<"contour size "<<contour.size()<<" cand size "<<cand.size()<<endl;
        vector<int> ans(queries.size(),-1);
        for(auto i:qidx){
            while(cand.size()&&queries[i][1]>cand.back().second-cand.back().first){
                // cout<<"contour size "<<contour.size()<<" cand size "<<cand.size()<<endl;
                cand.pop_back();
                contour.pop_back();
                if(contour.size()==0)break;
                // cout<<queries[i][1]<<" "<<cand.back().second<<" "<<cand.back().first<<endl;
                vector<pair<int,int>> tmp;
                for(int j = contour.size()-1; j>=0 &&(cand.size()==0||contour[j].first>cand.back().first);j = jumper[j]){   // need a jumper to reduce complexity
                    tmp.push_back({contour[j].first,contour[j].first+contour[j].second});
                }
                while(tmp.size()){cand.push_back(tmp.back());tmp.pop_back();}
            }
            // if(cand.size())cout<<queries[i][1]<<" "<<cand.back().second<<" "<<cand.back().first<<endl;
            // 
            //binary search
            int l=0,r=cand.size();
            while(l<r){
                int mid = (l+r)>>1;
                if(cand[mid].first<queries[i][0]){
                    l = mid+1;
                }else {
                    r =mid;
                }
            }
            if(r<cand.size()){
                // cout<<cand[r].first<<" "<<cand[r].second<<endl;
                ans[i] = cand[r].second;
            }
        }
        return ans;
    }
};