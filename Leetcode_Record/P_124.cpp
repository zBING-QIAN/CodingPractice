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
    int ans = -1e9;
    int dfs(TreeNode *cur){
        
        int tmp = 0;
        if(cur->left){
            tmp = max(0,dfs(cur->left));
        }

        if(cur->right){
            int rtmp = max(0,dfs(cur->right));
            ans =  max(ans,rtmp+cur->val+tmp);
            tmp = max(rtmp,tmp)+cur->val;
        }else {
            ans= max(ans,cur->val+tmp);
            tmp += cur->val;
        }
        return tmp;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};