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