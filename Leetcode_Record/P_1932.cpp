#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool dfs(TreeNode *rt, set<int> &order)
    {
        // cout<<rt->val<<endl;
        if (rt->left)
        {
            if (dfs(rt->left, order) == 0)
                return 0;
        }
        if (order.size() && (*order.rbegin() >= rt->val))
            return 0;
        order.insert(rt->val);
        if (rt->right)
        {
            if (dfs(rt->right, order) == 0)
                return 0;
        }
        return 1;
    }
    TreeNode *canMerge(vector<TreeNode *> &trees)
    {
        map<int, TreeNode *> rts;
        for (auto t : trees)
        {
            rts[t->val] = t;
        }
        map<int, TreeNode *> leaf;
        for (auto t : trees)
        {
            if (t->left)
            {
                if (leaf.count(t->left->val))
                    return 0;
                leaf[t->left->val] = t->left;
            }
            if (t->right)
            {
                if (leaf.count(t->right->val))
                    return 0;
                leaf[t->right->val] = t->right;
            }
        }
        for (auto t : leaf)
        {
            auto it = rts.find(t.first);
            if (it != rts.end())
            {
                t.second->left = it->second->left;
                t.second->right = it->second->right;
            }
            rts.erase(t.first);
        }
        if (rts.size() != 1)
            return 0;
        set<int> order;
        if (dfs(rts.begin()->second, order) == 0 || order.size() != leaf.size() + 1)
            return 0;
        return rts.begin()->second;
    }
};