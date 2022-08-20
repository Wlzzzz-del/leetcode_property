#include <iostream>
#include <vector>
#include <algorithm>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        const int size = nums.size();
        return build_tree(0,size-1,nums);
    }

    int findidx(int left, int right, vector<int>& nums){
        int tmp=left;
        int val=nums[left];
        for(int i=left+1;i<=right;++i){
            if(nums[i]>val){
                tmp = i;
                val = nums[i];
            }
        }
        return tmp;
    }

    TreeNode* build_tree(int left, int right,vector<int>& nums){
        TreeNode* tmp;
        if(left>right){
            return nullptr;
        }
        else{
            // 找到最大值元素的下标
            int idx = findidx(left,right,nums);
            tmp = new TreeNode(nums[idx]);
            tmp->left = build_tree(left,idx-1,nums);
            tmp->right = build_tree(idx+1,right,nums);
            return tmp;
        }
    }
};

int main(){
    Solution s;
    vector<int> vec({3,2,1,6,0,5});
    s.constructMaximumBinaryTree(vec);
}