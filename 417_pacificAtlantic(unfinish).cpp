// https://leetcode.cn/problems/pacific-atlantic-water-flow/
/* 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可流向大西洋 。*/

// 用两个map来记录,某个方格是否能到达大西洋或者太平洋
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        typedef std::pair<int, int> node;
        const int n = heights.size();
        const int m = heights[0].size();

        std::unordered_map<int, int> taipin ;
        std::unordered_map<int, int> daxi;
        std::queue<node>;
    }
} ;