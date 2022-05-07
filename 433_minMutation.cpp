// https://leetcode-cn.com/problems/minimum-genetic-mutation/
/*
基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。

给你两个基因序列 start 和 end ，以及一个基因库 bank ，
请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
class Solution {
    // 广度优先搜索
public:
    int minMutation(std::string start, std::string end, std::vector<std::string>& bank) {
        int result = INT_MAX;
        int route = 0;
        std::unordered_map<std::string ,int> mp;
        std::queue<std::string> queue;
        const int len = bank.size();
        for(int i=0; i<len; i++){
            mp[bank[i]]=1;
        }
        if(mp[end]==0)return -1;// end不在库中
        queue.push(start);

        while(!queue.empty()){
            int sz = queue.size();
            for(int j=0; j<sz; j++){
            std::string str = queue.front();
            queue.pop();
            std::cout<<str<<std::endl;
            std::cout<<mp[str]<<std::endl;
            if(end==str && result>route)result = route;
            int str_len = str.size();
            for(int i=0; i<str_len ; ++i){
                std::string temp = str;
                if(mp[temp.replace(i,1,"A")]==1 &&temp != str){queue.push(temp);++mp[temp];}
                if(mp[temp.replace(i,1,"C")]==1 &&temp != str){queue.push(temp);++mp[temp];}
                if(mp[temp.replace(i,1,"G")]==1 &&temp != str){queue.push(temp);++mp[temp];}
                if(mp[temp.replace(i,1,"T")]==1 &&temp != str){queue.push(temp);++mp[temp];}
            }// 加一个计数器
            }
            ++route;//route的递增有问题，不应该按出入队列来.
        }
        if(result==INT_MAX)return -1;
        return result;
    }
};

int main(){
    std::vector<std::string > vec({"AACCGGTA","AACCGCTA","AAACGGTA"});
    Solution s;
    std::cout<<s.minMutation("AACCGGTT","AACCGCTA",vec);
    system("pause");
    return 0;

}