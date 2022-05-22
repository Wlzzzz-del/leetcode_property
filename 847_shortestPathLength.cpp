// https://leetcode.cn/problems/shortest-path-visiting-all-nodes/
/*
存在一个由 n 个节点组成的无向连通图，图中的节点按从 0 到 n - 1 编号。

给你一个数组 graph 表示这个图。其中，graph[i] 是一个列表，由所有与节点 i 直接相连的节点组成。

返回能够访问所有节点的最短路径的长度。你可以在任一节点开始和停止，也可以多次重访节点，并且可以重用边。

*/
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <math.h>
class Solution {
struct Tr{
    int cur;// 当前节点编号
    int tra;// 已经遍历过的节点
    int path;// 路径长度
    Tr(int cur,int tra,int path):cur(cur),tra(tra),path(path){}
};// 三元组
public:

    int shortestPathLength(std::vector<std::vector<int>>& graph) {

        std::queue<Tr> que;
        const int nsize = graph.size();
        const int end = pow(2,nsize)-1;// 节点已经全部遍历的状态
        int res;
        std::vector<std::vector<bool>> seen(nsize,std::vector<bool>(1<<nsize,false));// 记录遍历过的状态
        // 各个节点入队
        for(int i=0; i<nsize; ++i){
        Tr ini(i,pow(2,i),0);// 初始三元组
        que.push(ini);
        }

        while(!que.empty()){
            Tr node = que.front();
            que.pop();

            if(node.tra == end){res = node.path;break;}// bfs保证一定是最短路径

            int esize = graph[node.cur].size();
            for(int i=0; i<esize; ++i){
                int temp = graph[node.cur][i];
                if((node.tra <<temp)==1)continue;// 判断是否访问过

                int tra = node.tra|(1<<temp);// 左移temp位取或
                if(tra>end)continue;
                if(!seen[temp][tra]){
                Tr new_node(temp, tra, node.path+1);
                seen[temp][tra]=true;

                que.push(new_node);
                }
            }
        }    
        return res;
    }
};