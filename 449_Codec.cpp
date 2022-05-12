// https://leetcode.cn/problems/serialize-and-deserialize-bst/
/*
序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。

*/

#include <iostream>
#include <string>
#include <vector>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
    // Encodes a tree to a single string.
    std::string m_str="";
    std::string b_str="";
    int s_size;
    std::string serialize(TreeNode* root) {
        m_travel(root);// 
        b_travel(root);
        s_size=m_str.size();// 记录字符串长度
        return m_str+b_str;
    }
private:
    void m_travel(TreeNode* node){
        // 中序遍历
        if(node==NULL){m_str+"#";return;}// 用#表示空节点
        m_travel(node->left);
        m_str+=std::to_string(node->val);
        m_travel(node->right);
    }
    void b_travel(TreeNode* node){
        // 后序遍历
        if(node==NULL){b_str+"#";return;}
        b_travel(node->left);
        b_travel(node->right);
        b_str+=std::to_string(node->val);

    }

public:
    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        int s_size = data.size()/2;
        if(s_size==0)return NULL;
        m_str = data.substr(0,s_size);
        b_str = data.substr(s_size,s_size);
        TreeNode* node = decode(0,s_size-1,s_size-1);
        return node;
    }
private:
    TreeNode* decode(int left, int right, int rloc){
        // 在后序遍历中找到根节点
        char root = b_str[rloc];
        if(root == '#')return NULL;
        int val = int(root)-48;
        TreeNode* node = new TreeNode(val);
        if(left == right)return node;
        // 在中序遍历中划分区间
        int mid;
        for(int i=left; i<=right; ++i){
            if(m_str[i] == root)mid = i;
        }
        // 搜索左区间
        node->left = decode(left, mid-1,rloc-2);
        node->right = decode(mid+1, right,rloc-1);
        // 搜索右区间
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

int main(){
    TreeNode* node =new TreeNode(2);
    node->left = new TreeNode(1);
    node->right = new TreeNode(3);

    Codec c;
    std::string str = c.serialize(node);
    TreeNode* node1 = c.deserialize(str);
    std::cout<<node1->left->val;
    system("pause");
    return 0;

}