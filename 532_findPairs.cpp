#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
/***
 * 
给定一个整数数组和一个整数 k，你需要在数组里找到 不同的 k-diff 数对，并返回不同的 k-diff 数对 的数目。

这里将 k-diff 数对定义为一个整数对 (nums[i], nums[j])，并满足下述全部条件：

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
注意，|val| 表示 val 的绝对值。
https://leetcode.cn/problems/k-diff-pairs-in-an-array/submissions/
***/

// 暴力法
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        const int size = nums.size();
        int temp = 99;
        map<int, int> mp;
        int count = 0;
        for(int i=0; i<size; ++i){
            for(int j=i+1; j<size; ++j){
                int vi = nums[i];
                int vj = nums[j];
                if(abs(vi-vj)==k && mp.find(vj*temp+vi)==mp.end()&&mp.find(vi*temp+vj)==mp.end() ){
                    ++mp[vi*temp+vj];
                    ++mp[vj*temp+vi];
                    ++count;
                }
            }
        }
        return count;
    }
};

//  排序加双指针
class Solution1 {
public:
    int findPairs(vector<int>& nums, int k) {
        int const size = nums.size();
        map<int, int>mp;
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        int count = 0;
        while(i<size && j<size){
            int gap = abs(nums[i]-nums[j]);
            if(gap>k)++i;
            else if(gap<k)++j;
            else if(gap == k&& mp[nums[i]+size*nums[j]]==0 && mp[nums[j]+size*nums[i]]==0){
                ++mp[nums[i]+size*nums[j]];
                ++count;
                ++i;
            }
            else{++i;}
        }
        return count;
    }
};