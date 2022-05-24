// https://leetcode.cn/problems/cut-off-trees-for-golf-event/
/* 你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 m x n 的矩阵表示， 在这个矩阵中：

0 表示障碍，无法触碰
1 表示地面，可以行走
比 1 大的数 表示有树的单元格，可以行走，数值表示树的高度
每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。

你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 1（即变为地面）。

你将从 (0, 0) 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 -1 。

可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。

*/
#include <vector>
#include <iostream>
#include <queue>
#include <math.h>

class Solution {
public:
    struct node{
        int step;// 步数
        int cut;// 是否砍过
        int x;// 位置
        int y;
        node(int step, int cut, int x,int y):step(step),cut(cut),x(x),y(y){}
    };
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int cutOffTree(std::vector<std::vector<int>>& forest) {
        const int mlen = forest.size();
        const int nlen = forest.size();
        int end=0;
        for(int i=0; i<mlen; ++i){
            for(int j=0;j<nlen;++j){
                if(forest[i][j]>1)
                end+= 1<<(i*nlen+j);// 记录树的位置
            }
        }

        std::queue<node> que;
        node ini(0,0,0,0);
        que.push(ini);
        while(!que.empty()){
            node cur = que.front();
            que.pop();
            if(cur.cut==end)return cur.step;
            for(int i=0; i<4; ++i){
                int new_x = cur.x+dir[i][0];
                int new_y = cur.y+dir[i][1];
                if(new_x<mlen && new_x>=0 && new_y<nlen && new_y>=0){
                    if(forest[new_x][new_y]==0)continue;
                    else if(forest[new_x][new_y]==1){
                        node new_(cur.step+1,cur.cut,new_x,new_y);
                        que.push(new_);
                    }
                    else if(forest[new_x][new_y]>1){
                    }
                }
            }
        }
        
    }
};