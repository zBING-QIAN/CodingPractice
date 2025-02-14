#include <bits/stdc++.h>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    
    pair<int,int> dfs(TreeNode *rt){
        pair<int, int> r = {0,0},l={0,0};
        if(rt->left){
            l = dfs(rt->left);
        }
        if(rt->right){
            r = dfs(rt->right);
        }
        // cout<<r.first+l.first<<" "<<r.second<<" "<<l.second<<endl;
        if(r.second==2||l.second==2)return {r.first+l.first+1,1};
        if(r.second==1||l.second==1)return {r.first+l.first,0};
        return {r.first+l.first,2};
    }
    
    
    int minCameraCover(TreeNode* root) {
        pair<int,int> ans = dfs(root);//cout<<ans.first<<" "<<ans.second<<endl;
        if(ans.second==2)ans.first++;
        return ans.first;
    }
};