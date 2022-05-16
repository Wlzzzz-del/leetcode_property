// https://leetcode.cn/problems/successor-lcci/
/*
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。
*/
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* ret = NULL;
    TreeNode* tar = NULL;
    bool flag=false;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        tar = p;
        travel(root);
        return ret;
    }
    void travel(TreeNode* node){
        if(node==NULL)return;
        travel(node->left);

        if(flag){ret = node;flag=false;}
        if(node->val == tar->val){
            flag = true;
        }
        travel(node->right);
    }
    
};