// https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/
/*
给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。

例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

返回这些数字之和。题目数据保证答案是一个 32 位 整数。
*/
/**
 * Definition for a binary tree node.
 */
#include <iostream>
#include <stack>
#include <math.h>
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
    // 后序遍历
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* root, int val){
        if(root==nullptr)return 0;
        val = (val<<1)|root->val;
        if(root->left==nullptr && root->right==nullptr)return val;
        return dfs(root->left,val)+dfs(root->right,val);
    }
};
