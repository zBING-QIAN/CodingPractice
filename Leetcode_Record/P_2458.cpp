#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode *rt,map<TreeNode*,int> &dp){
        int deep = 0;
        if(rt->left){
            deep = max(deep,dfs(rt->left,dp));
        }
        if(rt->right){
            deep = max(deep,dfs(rt->right,dp));
        }
        dp[rt] = deep+1;
        
        return deep+1;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        map<TreeNode*,int> dp;
        map<int,int> rec;
        dfs(root,dp);

        vector<TreeNode*> que,nxt_que;
        vector<int> ans;
        
        que.push_back(root);
        int flag = 0,level=-1;
        while(que.size()){
            auto cur = que[flag];
            if(cur->left){nxt_que.push_back(cur->left);}
            if(cur->right){nxt_que.push_back(cur->right);}
            flag++;
            if(flag==que.size()){
                sort(que.begin(),que.end(),[&](auto a,auto b){
                    return dp[a]>dp[b];
                });
                if(que.size()>1)rec[que[0]->val] = level+dp[que[1]];
                else rec[que[0]->val] = level;
                for(int i=1;i<que.size();i++){               
                    rec[que[i]->val] = level+dp[que[0]];
                }
                // for(int i=0;i<que.size();i++){cout<<que[i]->val<<" "<<rec[que[i]->val]<<" |   ";}cout<<endl;
                level++;
                que = nxt_que;nxt_que.clear();flag=0;
            }
        }

        for(auto q:queries){
            ans.push_back(rec[q]);
        }
        return ans;
    }
};