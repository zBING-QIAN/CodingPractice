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
    TreeNode *recoverFromPreorder(string traversal)
    {

        vector<int> ints, dashes;
        int parseint = 0;
        int prevd = 0;
        for (auto c : traversal)
        {
            if (c == '-')
            {
                if (prevd == 0)
                {
                    ints.push_back(parseint);
                    parseint = 0;
                }
                prevd++;
            }
            else
            {
                if (prevd > 0)
                {
                    dashes.push_back(prevd);
                    prevd = 0;
                }
                parseint *= 10;
                parseint += c - '0';
            }
        }
        if (prevd == 0)
        {
            ints.push_back(parseint);
            parseint = 0;
        }
        TreeNode *rt = new TreeNode(ints[0]);
        vector<TreeNode *> stac;
        stac.push_back(rt);
        for (int i = 1; i < ints.size(); i++)
        {
            TreeNode *tmp = new TreeNode(ints[i]);
            while (dashes[i - 1] < stac.size())
            {
                stac.pop_back();
            }
            if (stac.back()->left == nullptr)
            {
                stac.back()->left = tmp;
            }
            else
            {
                stac.back()->right = tmp;
            }
            stac.push_back(tmp);
        }

        return rt;
    }
};