// https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
/*
给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。请你找出所有出现 两次 的整数，并以数组形式返回。

你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。

*/

#include <vector>
#include <iostream>
#include <unordered_map>
class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        // 暴力哈希
        const int size = nums.size();
        std::unordered_map<int ,int> mp;
        std::vector<int> result;
        for(int i=0; i<size; i++){
            ++mp[nums[i]];
        }
        auto ite = mp.begin();
        while(ite != mp.end()){
            if(ite->second==2)result.push_back(ite->first);
            ++ite;
        }
        return result;
    }
};
class Solution1 {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        const int size = nums.size();
        std::vector<int> vec;
        int temp;
        for(int i=0; i<size; i++){
            while(nums[nums[i]-1]!=nums[i]){
            temp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = temp;
            }
        }
        for(int i=0; i<size; i++){
            if(nums[i]-1!=i)vec.push_back(nums[i]);
        }
        return vec;
    }
};

int main(){
    Solution1 s;
    std::vector<int> vec({4,3,2,7,8,2,3,1});
    s.findDuplicates(vec);
    system("pause");
}