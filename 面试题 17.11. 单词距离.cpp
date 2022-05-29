// https://leetcode.cn/problems/find-closest-lcci/
/*有个内含单词的超大文本文件，给定任意两个不同的单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。
如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?*/
#include <vector>
#include <string>
#include <algorithm>
class Solution {
public:
    int findClosest(std::vector<std::string>& words, std::string word1, std::string word2) {
        // 双指针
        const int len = words.size();
        int p1=INT_MIN;
        int p2=INT_MAX;
        int min_dis = INT_MAX;
        for(int i=0; i<len; ++i){
            if(words[i]==word1)p1=i;
            if(words[i]==word2)p2=i;
            min_dis = std::min(abs(p1-p2),min_dis);
        }
        return min_dis;
    }
};