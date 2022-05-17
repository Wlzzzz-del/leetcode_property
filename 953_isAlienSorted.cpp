// https://leetcode.cn/problems/verifying-an-alien-dictionary/
/*
某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
    std::map<char, int> mp;
    bool isAlienSorted(std::vector<std::string>& words, std::string order) {
        const int len = order.size();
        const int lenw = words.size();
        bool flag = true;

        for(int i=0; i<len; ++i){
            mp[order[i]]=i;
        }
        for(int j=0; j+1<lenw; ++j){
            flag = judge(words[j],words[j+1]);
            if(!flag)return false;
        }
        return true;
    }
    bool judge(std::string a, std::string b){
        int len = 0;
        while(len<a.size()&&len<b.size()){
            if(mp[a[len]]<mp[b[len]])return true;
            else if(mp[a[len]]>mp[b[len]])return false;
            else if(mp[a[len]]==mp[b[len]])++len;
        }
    }
};