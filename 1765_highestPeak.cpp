// https://leetcode.cn/problems/map-of-highest-peak/
/*
给你一个大小为 m x n 的整数矩阵 isWater ，它代表了一个由 陆地 和 水域 单元格组成的地图。

如果 isWater[i][j] == 0 ，格子 (i, j) 是一个 陆地 格子。
如果 isWater[i][j] == 1 ，格子 (i, j) 是一个 水域 格子。
你需要按照如下规则给每个单元格安排高度：

每个格子的高度都必须是非负的。
如果一个格子是 水域 ，那么它的高度必须为 0 。
任意相邻的格子高度差 至多 为 1 。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）
找到一种安排高度的方案，使得矩阵中的最高高度值 最大 。

请你返回一个大小为 m x n 的整数矩阵 height ，其中 height[i][j] 是格子 (i, j) 的高度。如果有多种解法，请返回 任意一个 。

*/
#include <iostream>
#include <vector>
#include <queue>
class Solution {
    int adj[4][2]={{1,0},{-1,0},{0,-1},{-1,0}};
    const int a_size = 4;
public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater) {
        typedef std::pair<int, int> loc;// pair表示横纵坐标
        loc temp;
        int cur_h = 0;
        std::queue<loc> que;
        const int w_col = isWater.size();
        const int w_row = isWater[0].size();
        std::vector<std::vector<int>> high(w_col,std::vector<int>(w_row,-1));

        for(int i=0; i<w_col; ++i){
            for(int j=0; j<w_row; ++j){
                if(isWater[i][j])
                {
                    high[i][j]=0;
                    que.push(loc(i,j));// 水域入队
                }
            }
        }

        // 不知道怎么存储每种情况, 可能不用存储。。
        while(!que.empty()){
            temp = que.front();
            que.pop();
            int col = temp.first;
            int row = temp.second;
            for(int j=0;j<a_size; ++j){
                // 更新新坐标
                int new_col = col+adj[j][0];
                int new_row = row+adj[j][1];
                if(new_col>=0 && new_col<w_col && new_row>=0 && new_row<w_row && high[new_col][new_row])
                { 
                    if(high[new_col][new_row]==-1){

                    }
                    que.push(loc(new_col,new_row));
                }
            }
        }
        return high;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> vec(2,std::vector<int>(2));
    s.highestPeak(vec);
    system("pause");
    return 0;
}