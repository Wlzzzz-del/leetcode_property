/*
给你一个字符串 sentence 作为句子并指定检索词为 searchWord ，其中句子由若干用 单个空格 分隔的单词组成。请你检查检索词 searchWord 是否为句子 sentence 中任意单词的前缀。

如果 searchWord 是某一个单词的前缀，则返回句子 sentence 中该单词所对应的下标（下标从 1 开始）。如果 searchWord 是多个单词的前缀，则返回匹配的第一个单词的下标（最小下标）。如果 searchWord 不是任何单词的前缀，则返回 -1 。

字符串 s 的 前缀 是 s 的任何前导连续子字符串。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        const int sen_size = sentence.size();
        const int sea_size = searchWord.size();
        int cur=0;
        bool flag = true;
        for(int i=0;i<sen_size;++i){
            if(i==0 || sentence[i-1]==' '){
                ++cur;
                flag = true;
                for(int j=0; j<sea_size; ++j){
                    if(i+j<sen_size && sentence[i+j]!=searchWord[j])flag = false;
                }
                if(flag)return cur;
            }
        }
        return -1;
    }
};