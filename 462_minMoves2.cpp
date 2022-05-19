// https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/
/*
给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最少移动数。

在一步操作中，你可以使数组中的一个元素加 1 或者减 1 。
*/
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        const int nsize = nums.size();
        std::sort(nums.begin(),nums.end()); 
        int mid = nums[(int)nsize/2];
        int count = 0;
        for(int j=0; j<nsize; ++j){
            count+=abs(nums[j]-mid);
        }
        return count;
    }
};