#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string out = to_string(root->val)+" ";
        if(root->left){out += "("+serialize(root->left)+")";}
        else out+="e";
        if(root->right){out+= "("+serialize(root->right)+")";}
        else out+="e";
        return out;
    }
    TreeNode *build(char *s,int len, int &i){
        int val = 0;
        bool neg = s[i]=='-';
        if(neg)i++;
        for(;i<len;i++){
            if(s[i] == ' ')break;
            val*=10;val+=s[i]-'0';
        }
        if(neg)val = -val;
        TreeNode *cur = new TreeNode(val);
        i++;
        if(s[i]=='('){
            i++;
            cur->left=build(s,len,i);
        }
        i++;
        if(s[i]=='('){
            i++;
            cur->right=build(s,len,i);    
        }
        i++;
        return cur;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return 0;
        int i=0;
       return build(&data[0],data.size(),i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));