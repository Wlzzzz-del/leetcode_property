/*
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。
https://leetcode.cn/problems/find-bottom-left-tree-value/comments/
*/
#include <iostream>
#include <queue>
using namespace std;

//Definition for a binary tree node.
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
    int findBottomLeftValue(TreeNode* root) {
        // 层序遍历
        queue<TreeNode*> que;
        que.push(root);
        int m_left=root->val;
        while(!que.empty()){
            int len = que.size();
            TreeNode* tmp;
            for(int i=0; i<len; ++i){
                if(i==0)m_left=que.front()->val;
                tmp = que.front();
                que.pop();
                if(tmp->left) que.push(tmp->left);
                if(tmp->right)que.push(tmp->right);
            }
        }
        return m_left;
    }
};

class Solution{
public:
    pair<int, int> m_left;
    void dfs(TreeNode* node, int h){
        // dfs
        if(h >m_left.second && !node->left && !node->right){
            m_left.first=node->val;
            m_left.second=h;
            return;
        }
        ++h;
        if(node->left)dfs(node->left,h);
        if(node->right)dfs(node->right,h);
    }
    int findBottomLeftValue(TreeNode* root) {
        m_left.first=0;
        m_left.second=INT_MIN;
        dfs(root,0);
        return m_left.first;
    }
};

class Solution{
public:
    int findBottomLeftValue(TreeNode* root){
        // bfs
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* tmp;
        int val;
        while(!que.empty()){
            tmp = que.front();
            que.pop();
            if(tmp->right)que.push(tmp->right);
            if(tmp->left)que.push(tmp->left);
            val = tmp->val;
        }
        return val;
    }
};