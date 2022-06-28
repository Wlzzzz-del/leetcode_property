#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

/*
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int size = nums.size();
        map<int ,int> mp;
        int i=0;
        int j=1;
        for(int i=0;i<size;++i){
            ++mp[nums[i]];
        }
        auto ite = mp.rbegin();
        while(ite!=mp.rend()){
            if(j<size){
                nums[j]=ite->first;
                --ite->second;
                j+=2;
            }
            else{
                nums[i]=ite->first;
                --ite->second;
                i+=2;
            }
            if(ite->second==0)++ite;
        }

    }
};
*/

class Solution{
public:
    void wiggleSort(vector<int> &nums){
        const int size = nums.size();
        vector<int> _arr;
        sort(nums.begin(),nums.end());
        int x = floor(size/2);
        if(size%2){// 奇数
            _arr.push_back(nums[0]);
            for(int i=1;i+x<size;++i){
                _arr.push_back(nums[i]);
                _arr.push_back(nums[i+x]);
            }
        }
        else{// 偶数
        for(int j=0;j+x<size;++j){
            _arr.push_back(nums[j+x]);
            _arr.push_back(nums[j]);
        }
        }
        nums = _arr;
        auto ite= nums.begin();
        while(ite!=nums.end()){
            cout<<*ite;
            ++ite;
        }

    }
};

int main(){
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(1);
    Solution s;
    s.wiggleSort(vec);
    system("pause");
    return 0;
}