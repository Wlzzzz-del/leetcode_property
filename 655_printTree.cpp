/*
给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局 。构造此格式化布局矩阵需要遵循以下规则：

树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
矩阵的列数 n 应该等于 2height+1 - 1 。
根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2height-r-1] ，右子节点放置在 res[r+1][c+2height-r-1] 。
继续这一过程，直到树中的所有节点都妥善放置。
任意空单元格都应该包含空字符串 "" 。
返回构造得到的矩阵 res 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/print-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <queue>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
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

struct dfsnode{
    TreeNode* node;
    int lloc;
    int rloc;
    dfsnode(TreeNode* _node, int l, int r):node(_node),lloc(l),rloc(r){}
};

// 先一次广度优先遍历得到高度
// 再根据题意构造树状结构
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height=0;
        queue<TreeNode*> st;
        st.push(root);
        TreeNode* tmp;
        while(!st.empty()){
            int size = st.size();
            for(int i=0; i<size; ++i){
                tmp = st.front();
                st.pop();
                if(tmp->left!=NULL)
                st.push(tmp->left);
                if(tmp->right!=NULL)
                st.push(tmp->right);
            }
            if(size!=0)
            ++height;
        }
        int n = pow(2,height);
        int m = height;
        vector<vector<string>> vec(height,vector<string>(pow(2,height)-1));
        stack<dfsnode> dfst;
        dfst.push(dfsnode(root,0,(n-1)/2));
        vec[0][(n-1)/2] = to_string(root->val);
        while(!dfst.empty()){
            tmp = dfst.top().node;
            int lloc = dfst.top().lloc;
            int rloc = dfst.top().rloc;
            dfst.pop();
            if(tmp->left!=NULL){
                vec[lloc+1][rloc-pow(2,height-lloc-2)] = to_string(tmp->left->val);
                dfst.push(dfsnode(tmp->left,lloc+1,rloc-pow(2,height-lloc-2)));
            }
            if(tmp->right!=NULL){
                vec[lloc+1][rloc+pow(2,height-lloc-2)] = to_string(tmp->right->val);
                dfst.push(dfsnode(tmp->right,lloc+1,rloc+pow(2,height-lloc-2)));
            }
        }

        return vec;
    }
};