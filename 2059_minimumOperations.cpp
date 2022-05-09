// https://leetcode.cn/problems/minimum-operations-to-convert-number/
/*
给你一个下标从 0 开始的整数数组 nums ，该数组由 互不相同 的数字组成。另给你两个整数 start 和 goal 。

整数 x 的值最开始设为 start ，你打算执行一些运算使 x 转化为 goal 。你可以对数字 x 重复执行下述运算：

如果 0 <= x <= 1000 ，那么，对于数组中的任一下标 i（0 <= i < nums.length），可以将 x 设为下述任一值：

x + nums[i]
x - nums[i]
x ^ nums[i]（按位异或 XOR）
注意，你可以按任意顺序使用每个 nums[i] 任意次。使 x 越过 0 <= x <= 1000 范围的运算同样可以生效，但该该运算执行后将不能执行其他运算。

返回将 x = start 转化为 goal 的最小操作数；如果无法完成转化，则返回 -1 。

*/
#include <iostream>
#include <vector>
#include <queue>

class Solution {
    // 广度优先搜索
public:
    int minimumOperations(std::vector<int>& nums, int start, int goal) {
        const int nsize = nums.size();
        std::vector<int> vec(1001);
        int min = INT_MAX;        
        int count = 0;
        int temp;
        std::queue<int> que;
        que.push(start);
        while(!que.empty()){
            int qsize = que.size();
            for(int i=0; i<qsize; ++i){
                temp = que.front();
                que.pop();
                if(temp == goal && count<min)min = count;
                if(temp<0 || temp >1000)continue;
                if(vec[temp]==1)continue;
                vec[temp]=1;
                for(int j=0; j<nsize; ++j){
                    que.push(temp+nums[j]);
                    que.push(temp-nums[j]);
                    que.push(temp^nums[j]);
                }
            }
            ++count;
        }
        if(min==INT_MAX)min=-1;
        return min;
    }
};