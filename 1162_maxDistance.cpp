// https://leetcode.cn/problems/as-far-from-land-as-possible/
/*
你现在手里有一份大小为 n x n 的 网格 grid，上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地。

请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的，并返回该距离。如果网格上只有陆地或者海洋，请返回 -1。

我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - x1| + |y0 - y1| 。

*/
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

class Solution1{
    // 多源bfs
    // 从每个陆地开始计算海洋距离
public:
    typedef std::pair<int, int> loc;
    int farest = -1;
    int adj[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
    int n,m;
    static inline int MDIS(loc l1, loc l2){return abs(l1.first-l2.first)+abs(l1.second-l2.second);}

    int maxDistance(std::vector<std::vector<int>>& grid) {
        std::unordered_map<int, int> mp;
        std::queue<loc> que;
        n = grid.size();
        m = grid[0].size();
        loc temp;
        // 所有陆地板块插入队列
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1){que.push(loc(i,j));mp[i*n+j]=0;}// 陆地距离从1开始
            }
        }

        while(!que.empty()){
            temp = que.front();
            que.pop();
            int val = mp[temp.first*n+temp.second];
            for(int j=0; j<4; j++)
            {
                int new_col = temp.first+adj[j][0];
                int new_row = temp.second+adj[j][1];

                if(mp.count(new_col*n+new_row))continue;// 已经被记录过
                if(new_col>=0 && new_col<n && new_row>=0 && new_row<m )
                {
                    que.push(loc(new_col,new_row));
                    mp[new_col*n+new_row] = val+1;
                    farest = farest>(val+1)? farest:val+1;
                }
            }
        }
        return farest;
    }
};

class Solution {
    // 单源bfs->超时做法
    // 从每个海洋开始找最近的陆地
public:
    typedef std::pair<int, int> loc;
    int farest = INT_MIN;
    static inline int MDIS(loc l1, loc l2){return abs(l1.first-l2.first)+abs(l1.second-l2.second);}
    int adj[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
    int IND = 7;
    int n,m;

    int maxDistance(std::vector<std::vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==0)
                farest = std::max(bfs(i,j,grid),farest);
            }
        }
        return farest;
    }
    int bfs(int x,int y,const std::vector<std::vector<int>>& grid){
        std::unordered_map<int, int> mp;
        std::queue<loc> que;
        loc start = loc(x,y);
        que.push(start);
        loc temp;

        while(!que.empty()){
            int qsize = que.size();
            for(int i=0; i<qsize; ++i){
                temp = que.front();
                mp[IND*temp.first+temp.second]=1;// 标记该格子访问过
                que.pop();
                // 更新最大距离
                if(grid[temp.first][temp.second]==1){return MDIS(start,temp);}
                for(int j=0; j<4; ++j){
                    int new_col = adj[j][0]+temp.first;
                    int new_row = adj[j][1]+temp.second;
                    if(mp[new_col*IND+new_row]==0 && new_col>=0 && new_col<n && new_row>=0 && new_row<m ){
                        que.push(loc(new_col,new_row));
                    }
                }
            }
        }
        return -1;
    }
};