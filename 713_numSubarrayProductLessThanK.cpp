// https://leetcode-cn.com/problems/subarray-product-less-than-k/
// 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目
#include <iostream>
#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        const int size = nums.size();
        int all = 1;
        int j=0;
        int ret=0;
        int count = 0;
        for(int i=0; i<size; i++){
            all *= nums[i];
            while(i>j && all >= k){
                all /= nums[j];
                j++;
            }
            ret += i-j+1;
        }
        return ret;
        }
};

class Solution1{
    public:
    int numSubarrayProductLessThanK(std::vector<int> vec, int k){
        int len = vec.size();
        int all = 1;
        int count = 0;
        int j=0;
        for(int i=0;i<len; ++i){
            all *= vec[i];
            // 移动j指针
            while(all>=k && j<i){
                std::cout<<vec[j]<<" ";
                std::cout<<all<<std::endl;
                all /= vec[j];
                ++j;
            }
            count += i-j+1;
        }
        return count;
    }
};
int main(){
    Solution1 s;
    // std::vector<int> vec({10,9,10,4,3,8,3,3,6,2,10,10,9,3});
    std::vector<int> vec({10,5,2,6});
    s.numSubarrayProductLessThanK(vec,100);
    system("pause");
}