// https://leetcode-cn.com/problems/reorder-data-in-log-files/
/*
给你一个日志数组 logs。每条日志都是以空格分隔的字串，其第一个字为字母与数字混合的 标识符 。

有两种不同类型的日志：

字母日志：除标识符之外，所有字均由小写字母组成
数字日志：除标识符之外，所有字均由数字组成
请按下述规则将日志重新排序：

所有 字母日志 都排在 数字日志 之前。
字母日志 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序。
数字日志 应该保留原来的相对顺序。
返回日志的最终顺序。

示例 1：

输入：logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
输出：["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
解释：
字母日志的内容都不同，所以顺序为 "art can", "art zero", "own kit dig" 。
数字日志保留原来的相对顺序 "dig1 8 1 5 1", "dig2 3 6" 。
示例 2：

输入：logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
输出：["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
*/

#include <vector>
#include <iostream>
#include <string>
#include <map>
class Solution {
public:
    std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs) {
        // 重点是对字母日志的排序
        const int log_size = logs.size();
        std::vector<std::string> re;
        std::vector<std::string> num;
        std::map<std::string, std::string> mp;
        for(int i=0; i<log_size; ++i){
            int loc = logs[i].find(' ');
            // 逆转子串
            if(isdigit(logs[i][loc+1]))// 注意可能越界
            num.push_back(logs[i]);
            else{
            std::string str = logs[i].substr(loc+1, logs[i].size()+1)+" "+"a"+logs[i].substr(0, loc+1);
            mp[str] = logs[i];
            }
        }
        auto ite = mp.begin();
        while(ite!=mp.end()){
            re.push_back(ite->second);
            ++ite;
        }
        auto ite1 = num.begin();
        while(ite1!=num.end()){
            re.push_back(*ite1);
            ++ite1;
        }
        return re;
    }
};

int main(){
    std::vector<std::string> logs({"dig1 8 1 5 1","let1 art zero can","dig2 3 6","let2 own kit dig","let3 art zero"});
    Solution s;
    auto vec = s.reorderLogFiles(logs);
    for(int i=0; i<vec.size(); ++i){
        std::cout<<vec[i]<<std::endl;
    }
    system("pause");

}