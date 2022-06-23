/*
给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。
https://leetcode.cn/problems/substring-with-concatenation-of-all-words/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
    // 朴素哈希表
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> mp;
        map<string ,int> t_mp;
        std::vector<int> loc;
        const int size = words.size();// 有几个单词
        const int len = words[0].size();// 单个单词长度
        const int slen = size*len;// 包含单词的句子长度
        const int alen = s.size();// s的长度
        int start = 0;
        for(int i=0; i<size; ++i){
            ++mp[words[i]];
        }
        while(start+slen<=alen){
            cout<<start<<endl;
            for(int i=0;i<slen;i+=len){
                string temp = s.substr(start+i, len);
                cout<<temp<<endl;
                ++t_mp[temp];
            }
            if(mp==t_mp)loc.push_back(start);
            t_mp.clear();
            ++start;
        }
        return loc;
    }
};


int main(){
    string s="wordgoodgoodgoodbestword";
    vector<string> words;
    words.push_back("word");
    words.push_back("good");
    words.push_back("best");
    words.push_back("good");
    Solution s1;
    s1.findSubstring(s,words);
    system("pause");
    return 0;
}