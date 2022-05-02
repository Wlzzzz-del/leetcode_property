// leetcode 1305 两颗二叉搜索树中的所有元素
// https://leetcode.cn/problems/all-elements-in-two-binary-search-trees/

#include <iostream>
#include <vector>
#include <algorithm>
// definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    // 暴力排序
public:
    std::vector<int> vec;
    void travel(TreeNode* root){
        if(root == NULL){return;}
        vec.push_back(root->val);
        travel(root->left);
        travel(root->right);
    }
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        travel(root1);
        travel(root2);
        std::sort(vec.begin(),vec.end(),cmp);
        return vec;
    }
    static bool cmp(int a, int b){
        return a<b;
    }
};

class Solution1{
    // 中序遍历-归并排序
    typedef std::vector<int> _vec;
public:
    void travel(_vec &arr,TreeNode* root){
        if(root == NULL){return;}
        travel(arr, root->left);
        arr.push_back(root->val);
        travel(arr, root->right);
    }

    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
        _vec arr1,arr2,arr3;
        travel(arr1, root1);
        travel(arr2, root2);
        int len1 = arr1.size();
        int len2 = arr2.size();
        int i=0,j=0;

        while(i<len1 || j<len2){
            int a = i<len1?arr1[i]:INT_MAX;
            int b = j<len2?arr2[j]:INT_MAX;
            if(a>b){
                arr3.push_back(b);
                j++;
            }
            else{
                arr3.push_back(a);
                i++;
            }
        }
        return arr3;
    }
};