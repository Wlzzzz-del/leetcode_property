/*
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
*/
#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> largestValues(TreeNode* root) {
        // bfs
        vector<int> max_val;
        queue<TreeNode*> que;
        TreeNode* tmp;
        que.push(root);
        while(!que.empty()){
            int len = que.size();
            int max_ = INT_MIN;
            for(int i=0; i<len; ++i){
                tmp = que.front();
                que.pop();
                max_ = max(max_,tmp->val);
                if(tmp->left)que.push(tmp->left);
                if(tmp->right)que.push(tmp->right);
            }
            max_val.push_back(max_);
        }
        return max_val;
    }
};

class Solution{
public:
    vector<int> largestValues(TreeNode* root) {
        // dfs
        if(root)travel(root,0);
        return max_val;
    }
private:
    vector<int> max_val;
    void travel(TreeNode* node, int height){
        if(max_val.size()==height)max_val.push_back(node->val);
        else max_val[height]=max(max_val[height],node->val);
        if(node->left)travel(node->left, height+1);
        if(node->right)travel(node->right, height+1);
    }
};