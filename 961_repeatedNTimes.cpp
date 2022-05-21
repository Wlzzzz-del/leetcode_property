#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int repeatedNTimes(std::vector<int>& nums) {
       std::map<int ,int> mp;
       const int size = nums.size();
       for(int i=0;i<size;++i){
           ++mp[nums[i]];
       }
       auto ite = std::max_element(mp.begin(),mp.end(),cmp);
       return ite->first;
    }
    static bool cmp(std::pair<int, int> p1, std::pair<int, int> p2){
        return p1.second<p2.second;
    }
};