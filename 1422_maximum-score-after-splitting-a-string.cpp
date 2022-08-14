#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        const int size = s.size();
        int score = INT_MIN;
        for(int i=0; i<size; ++i){
            int tmp=0;
            int step = 0;
            while(step<size){
                if(step<=i && s[step]=='0')++tmp;
                if(step>i && s[step]=='1')++tmp;
                ++step;
            }
            score = max(score,tmp);
        }
        return score;
    }
};

class Solution1{
    public:
    int maxScore(string s){
        const int size = s.size();
        int score = INT_MIN;
        vector<int> vec(size);
        for(int i=1; i<=size; ++i){// 这个范围一开始没有写等号，少记录了一个前缀和
            vec[i] = vec[i-1]+(s[i-1]=='1'?1:0);// 记录前缀1的数量
        }
        for(int i=1; i<size; ++i){
            int a = i-vec[i];// 左侧数的个数减去左侧1的个数等于左侧0的个数
            int b = vec[size] - vec[i];// 1的总数减去左侧1的数量等于右侧1的数量
            score = max(score, a+b);
        }
        return score;
    }
};

int main(){
    Solution1 s;
    cout<<s.maxScore("1111")<<endl;
    system("pause");
    return 0;
}