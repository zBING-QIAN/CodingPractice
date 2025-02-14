#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find_head(vector<int> &set,int a){
        vector<int> chain;
        int ha=a;
        while(set[ha] != ha){chain.push_back(ha);ha = set[ha];}
        for(auto &tmp:chain)set[tmp] = ha;
        return ha;
    }

    void merge(vector<int> &set,int a,int b){
        int ha = find_head(set,a);
        int hb = find_head(set,b);
        set[hb] = ha;
    }


    int containVirus(vector<vector<int>>& isInfected) {
        int h=isInfected.size(),w=isInfected[0].size();
        
        int ans = 0;
        while(1){
            // mark set
            vector<vector<int>> rec(h,vector<int>(w,-1));
            vector<int> set;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(isInfected[i][j]==1){
                        rec[i][j] = set.size();
                        set.push_back(set.size());
                    }else if(isInfected[i][j]==-1){
                        rec[i][j] = -2;
                    }
                }
            }
            // cout<<"mark end\n";
            // merge set
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(rec[i][j]>=0){
                        if(i>0&&rec[i-1][j]>=0){
                            merge(set,rec[i][j],rec[i-1][j]);
                        }
                        if(j>0&&rec[i][j-1]>=0){
                            merge(set,rec[i][j],rec[i][j-1]);
                        }
                        if(i<h-1&&rec[i+1][j]>=0){
                            merge(set,rec[i][j],rec[i+1][j]);
                        }
                        if(j<w-1&&rec[i][j+1]>=0){
                            merge(set,rec[i][j],rec[i][j+1]);
                        }
                    }
                }
            }

            // cout<<"merge end\n";
            // calc set wall
            map<int,int> wall_cnt,expand_cnt;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    // if(rec[i][j]>=0)cout<<find_head(set,rec[i][j])<<" ";
                    // else cout<<rec[i][j]<<" ";
                    map<int,int> expand_set;
                    if(isInfected[i][j]==0){
                        if(i>0&&rec[i-1][j]>=0){
                            int tmp = find_head(set,rec[i-1][j]);
                            expand_set[tmp]++;
                        }
                        if(j>0&&rec[i][j-1]>=0){
                            int tmp = find_head(set,rec[i][j-1]);
                            expand_set[tmp]++;
                        }
                        if(i<h-1&&rec[i+1][j]>=0){
                            int tmp = find_head(set,rec[i+1][j]);
                            expand_set[tmp]++;
                        }
                        if(j<w-1&&rec[i][j+1]>=0){
                            int tmp = find_head(set,rec[i][j+1]);
                            expand_set[tmp]++;
                        }
                    }
                    for(auto &[s,c]:expand_set){expand_cnt[s]++;wall_cnt[s]+=c;}
                }//cout<<endl;
            }

            // cout<<"wall end\n";
            // pick largest
            int max_id=-1,max_cnt = 0;
            for(auto [id,cnt]:expand_cnt){
                if(max_cnt <cnt){max_id = id;max_cnt = cnt;}
            }
            if(max_id == -1||max_cnt ==0)break;
            // cout<<ans<<" "<<wall_cnt[max_id]<<" " <<max_id<<endl;
            ans+=wall_cnt[max_id];
            // cout<<"max_cnt end\n";
            //block inf area or expand
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(isInfected[i][j]==0){
                        if(i>0&&rec[i-1][j]>=0){
                            if(find_head(set,rec[i-1][j])!=max_id){
                                isInfected[i][j] = 1;continue;
                            }
                        }
                        if(i<h-1&&rec[i+1][j]>=0){
                            if(find_head(set,rec[i+1][j])!=max_id){
                                isInfected[i][j] = 1;continue;
                            }
                        }
                        if(j>0&&rec[i][j-1]>=0){
                            if(find_head(set,rec[i][j-1])!=max_id){
                                isInfected[i][j] = 1;continue;
                            }
                        }
                        if(j<w-1&&rec[i][j+1]>=0){
                            if(find_head(set,rec[i][j+1])!=max_id){
                                isInfected[i][j] = 1;continue;
                            }
                        }
                    }
                    if(isInfected[i][j]==1&&find_head(set,rec[i][j])==max_id){
                        isInfected[i][j] = -1;
                    }
                }
            }
            // cout<<"isInfected end\n";
        }
        return ans;
        
    }
};