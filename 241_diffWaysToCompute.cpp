/*
给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。

生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/different-ways-to-add-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    std::vector<int> result;
    vector<int> diffWaysToCompute(string expression) {
        int num=0;
        int index=0;
        const int size = expression.size();
        // 考虑是否全为数字
        for(int i=0; i<size; ++i){
            if(!issym(expression[i]))
            {
                num=num*10+(int)(expression[i]-'0');
                ++index;
                break;
            }
        }
        if(index==size-1){result.push_back(num);return result;}



        for(int i=0;i<size;++i){
            if(issym(expression[i])){
                vector<int> result1 = diffWaysToCompute(expression.substr(0,i));
                vector<int> result2 = diffWaysToCompute(expression.substr(i+1));
                for(int j=0; j<result1.size(); ++j){
                    for(int k=0; k<result2.size(); ++k){
                        result.push_back(caculate(result1[j],result2[k],expression[i]));
                    }
                }
            }
        }
        return result;
    }

    int caculate(int a, int b, char sym){
        if(sym == '+')return a+b;
        if(sym == '*')return a*b;
        if(sym == '-')return a-b;
    }
    bool issym(char sym){
        if(sym=='*' || sym=='+' || sym=='-')return true;
        else return false;
    }
};