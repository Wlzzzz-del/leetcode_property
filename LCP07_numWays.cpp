// https://leetcode-cn.com/problems/chuan-di-xin-xi/
/*
小朋友 A 在和 ta 的小伙伴们玩传信息游戏，游戏规则如下：

有 n 名玩家，所有玩家编号分别为 0 ～ n-1，其中小朋友 A 的编号为 0
每个玩家都有固定的若干个可传信息的其他玩家（也可能没有）。传信息的关系是单向的（比如 A 可以向 B 传信息，但 B 不能向 A 传信息）。
每轮信息必须需要传递给另一个人，且信息可重复经过同一个人
给定总玩家数 n，以及按 [玩家编号,对应可传递玩家编号] 关系组成的二维数组 relation。返回信息从小 A (编号 0 ) 经过 k 轮传递到编号为 n-1 的小伙伴处的方案数；若不能到达，返回 0。

示例 1：

输入：n = 5, relation = [[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]], k = 3

输出：3

解释：信息从小 A 编号 0 处开始，经 3 轮传递，到达编号 4。共有 3 种方案，分别是 0->2->0->4， 0->2->1->4， 0->2->3->4。

示例 2：

输入：n = 3, relation = [[0,2],[2,1]], k = 2

输出：0

解释：信息不能从小 A 处经过 2 轮传递到编号 2

*/
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>

class Solution {
public:
    int numWays(int n, std::vector<std::vector<int>>& relation, int k) {
        // 广度优先搜索
        std::unordered_map<int, std::vector<int>> adj_mp;
        std::queue<int> que;
        int temp;
        int step=0;
        int count=0;
        int start=0,end=INT_MIN;
        const int size = relation.size();
        for(int i=0; i<size; ++i){
            adj_mp[relation[i][0]].push_back(relation[i][1]);
            end = relation[i][1]>end?relation[i][1]:end;
        }

        que.push(start);
        while(!que.empty()){
            int len = que.size();
            for(int i=0; i<len; ++i){
                temp = que.front();
                que.pop();
                if(temp==end && step == k) ++count;
                for(int j=0; j<adj_mp[temp].size(); ++j){
                    que.push(adj_mp[temp][j]);// 进队
                }
                std::cout<<std::endl;
            }
            if(step == k)break;
            ++step;
        }
        return count;
    }
};

class Solution1{
public:
    // 深度优先搜索
    std::unordered_map<int, std::vector<int>> adj_mp;// 邻接链表
    int start=0, end=INT_MIN, count=0, kk;
    int numWays(int n, std::vector<std::vector<int>>& relation, int k) {
        // 深度优先搜索
        kk = k;
        const int size = relation.size();
        // 初始化邻接链表
        for(int i=0; i<size; ++i){
            adj_mp[relation[i][0]].push_back(relation[i][1]);
            end = relation[i][1]>end?relation[i][1]:end;
        }
        dfs_visit(0,0);
        return count;
    }
    void dfs_visit(int node ,int k){
        if(k==kk){
            if(node==end)++count;
        return;}
        int size = adj_mp[node].size();
        for(int i=0; i<size; ++i){
            dfs_visit(adj_mp[node][i], k+1);
        }
    }
};

int main(){
    Solution s1;
    std::vector<std::vector<int>> vec({{0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4}});
    std::cout<<s1.numWays(5,vec,3);
    system("pause");
}