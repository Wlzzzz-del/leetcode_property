// https://leetcode.cn/problems/di-string-match/
/*
由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:

如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。
*/
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> diStringMatch(std::string s) {
        // 贪心算法
        const int n = s.size();
        std::vector<int> num(n+1);
        int Max = n,Min =0;
        for(int i=0; i<n; ++i){
            num[i]= s[i]=='I'?Min++:Max--;
        }
        num[n]=Min;
        return num;
    }
};