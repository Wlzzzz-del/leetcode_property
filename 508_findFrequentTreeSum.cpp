#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。

一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/most-frequent-subtree-sum
*/
/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    map<int, int> mp;
    int _max=INT_MIN;
    int travel(TreeNode* node){
        int lval = node->left?travel(node->left):0;
        int rval = node->right?travel(node->right):0;
        int new_sum = node->val+lval+rval;
        _max = max(new_sum,_max);
        ++mp[new_sum];
        return new_sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> list;
        travel(root);
        for(auto ite = mp.begin();ite!=mp.end();++ite){
            if(ite->second==_max)list.push_back(ite->first);
        }
        return list;
    }
};

int main(){
    TreeNode* p = new TreeNode(1);
    Solution s1;
    vector<int> vec = s1.findFrequentTreeSum(p);
    auto ite = vec.begin();
    while(ite!=vec.end()){
        std::cout<<*ite;
    }
    system("pause");
    return 0;
}