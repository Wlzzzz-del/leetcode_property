// https://leetcode.cn/problems/delete-columns-to-make-sorted/
/*
给你由 n 个小写字母字符串组成的数组 strs，其中每个字符串长度相等。

这些字符串可以每个一行，排成一个网格。例如，strs = ["abc", "bce", "cae"] 可以排列为：

abc
bce
cae
你需要找出并删除 不是按字典序升序排列的 列。在上面的例子（下标从 0 开始）中，列 0（'a', 'b', 'c'）和列 2（'c', 'e', 'e'）都是按升序排列的，而列 1（'b', 'c', 'a'）不是，所以要删除列 1 。

返回你需要删除的列数。

*/
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int minDeletionSize(std::vector<std::string>& strs) {
        const int asize = strs.size();
        const int ssize = strs[0].size();
        int count = 0;
        std::vector<char> vec(ssize,'a');
        for(int i=0; i<asize; ++i){
            for(int j=0; j<ssize; ++j){
                if(vec[j]!=' '&& char(strs[i][j])>=vec[j]){
                    vec[j]=char(strs[i][j]);
                }
                else if(vec[j]!=' '){
                    ++count;
                    vec[j]=' ';
                }
            }
        }
        return count;
    }
};