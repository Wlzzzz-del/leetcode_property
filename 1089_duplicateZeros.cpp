/*
https://leetcode.cn/problems/duplicate-zeros/
给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。

注意：请不要在超过该数组长度的位置写入元素。

要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。
*/
#include <iostream>
#include <vector>
using namespace std;

/* 重新构建数组的偷懒做法 */
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        const int len = arr.size();
        vector<int> temp;
        for(int i=0; i<len; ++i){
            if(temp.size()==len)break;
            if(arr[i]==0 && temp.size()+2<=len){temp.push_back(0);temp.push_back(0);}
            else{temp.push_back(arr[i]);}
        }
        arr=temp;
    }
};


/* 模拟栈的做法 */
class Solution1 {
public:
    void duplicateZeros(vector<int>& arr) {
        const int len = arr.size();
        int j=0,i=0;
        for(; i<len; ++i){
            if(j>len-1)break;
            arr[i]==0?j+=2:j++;
        }
        i--;
        j--;
        if(j==len){j--;arr[j--]=0;i--;}

        while(i>=0 && j>=0){
            std::cout<<"i:"<<i<<endl;
            std::cout<<"j:"<<j<<endl;
            if(arr[i]==0){
                arr[j]=0;
                if(j>0)
                arr[j-1]=0;
                j -=2;
            }
            else{
                arr[j]=arr[i];
                j--;
            }
            i--;
        }
    }
};

int main(){
    Solution1 s1;
    int arr[8]={8,4,5,0,0,0,0,7};
    std::vector<int> vec;
    for(int i=0; i<8 ;++i){
        vec.push_back(arr[i]);
    }
    s1.duplicateZeros(vec);
    auto ite = vec.begin();
    while(ite!=vec.end()){
        std:cout<<*ite<<",";
        ++ite;
    }

    system("pause");
    return 0;
}