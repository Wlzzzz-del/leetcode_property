#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// 哈希
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        const int size = target.size();
        map<int, int> mp1;
        map<int, int> mp2;
        for(int i=0;i<size;++i){
            ++mp1[target[i]];
            ++mp2[arr[i]];
        }
        auto ite1 = mp1.begin();
        auto ite2 = mp2.begin();
        while(ite1!=mp1.end() && ite2!=mp2.end()){
            if(ite1->first != ite2->first )return false;
            if(ite1->second != ite2->second)return false;
        }
        return true;
    }
};

// 桶计数
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> vec(1000);
        const int size = target.size();
        for(int i=0;i<size;++i){
            ++vec[target[i]];
            --vec[arr[i]];
        }
        for(int i=0;i<1000;++i){
            if(vec[i]!=0)return false;
        }
        return true;
    }
};

// 排序
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        const int size = target.size();
        for(int i=0; i<size; ++i){
            if(target[i]!=arr[i])return false;
        }
        return true;
    }
};