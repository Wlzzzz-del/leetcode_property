// https://leetcode.cn/problems/one-away-lcci/
/*
面试题 01.05. 一次编辑
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
*/
#include <stack>
#include <string>
#include <iostream>

class Solution {
public:
    bool oneEditAway(std::string first, std::string second) {
        const int fsize = first.size();
        const int ssize = second.size();
        int div = abs(fsize-ssize);
        if(div>=2)return false;
        else if(div==1){
            std::string longstr = fsize>ssize? first:second;
            std::string shortstr = fsize>ssize? second:first;
            int i=0,j=0,cnt=0;
            while(j<longstr.size()){
                if(longstr[j]==shortstr[i])++i;
                else ++cnt;
                ++j;
            }
            if(cnt <= 1)return true;
        }
        else if(div==0){
            int count = 0;
            for(int i=0; i<fsize; ++i){
                if(first[i]==second[i])++count;
            }            
            if(count<=1)return true;
        }
        return false;
    }
};

int main(){
    Solution s1;
    std::string long_str = "pales";
    std::string short_str = "pal";
    if(s1.oneEditAway(long_str, short_str))std::cout<<"true";
    else std::cout<<"false";
    system("pause");
    return 0;
}