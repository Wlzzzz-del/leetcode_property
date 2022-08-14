#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
    struct record{
        int x;
        int y;
        int cherry;
        bool back;
        int tra;
        record(int _x, int _y, int _cherry, bool _back, int _tra):x(_x),y(_y),cherry(_cherry),back(_back),tra(_tra){};
    };
public:
    int dirf[2][2]= {{0,1},{1,0}};
    int dirb[2][2]= {{-1,0},{0,-1}};

    int cherryPickup(vector<vector<int>>& grid) {
        bool back = false;
        int MAX_C = 0;
        const int size = grid.size();
        queue<record> que;
        record r(0,0,0,false,0);

        que.push(r);
        // 没有记录樱桃的变化
        while(!que.empty()){
                record temp = que.front();
                que.pop();
                    for(int j=0;j<2;++j){
                        int _x = temp.back?temp.x+dirb[j][0]:temp.x+dirf[j][0];
                        int _y = temp.back?temp.y+dirb[j][1]:temp.y+dirf[j][1];

                        if(_x<size &&_y<size&&_x>=0&&_y>=0&& grid[_x][_y]!=-1){
                            int cheery = grid[_x][_y]==1&&(!(temp.tra>>(_x*size+_y)&1))? temp.cherry+1 : temp.cherry;
                            int tra = grid[_x][_y]==1&&(!(temp.tra>>(_x*size+_y)&1))? temp.tra|(1<<(_x*size+_y)):temp.tra;

                            bool back = (_x==size-1 && _y==size-1)||(temp.back)?true:false;

                            record a(_x,_y,cheery,back,tra);
                            cout<<"x:"<<_x<<" y:"<<_y<<" cheery:"<<cheery<<" tra:"<<tra<<endl;
                            if(_x==0&&_y==0){MAX_C = max(MAX_C,cheery);continue;}         
                            que.push(a);
                        }
                    }
                }
            return MAX_C;
            }
};