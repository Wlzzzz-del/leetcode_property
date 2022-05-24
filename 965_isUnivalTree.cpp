// https://leetcode.cn/problems/univalued-binary-tree/
/*
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。
*/
#include <iostream>

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
    bool is_same = true;
    int val;
    bool isUnivalTree(TreeNode* root) {
        val = root->val;
       travel(root);
       return is_same;
    }
    void travel(TreeNode* node){
        if(!is_same)return;
        if(node==NULL)return;
        if(val==node->val)is_same=true;
        else is_same=false;
        travel(node->left);
        travel(node->right);
    }

};