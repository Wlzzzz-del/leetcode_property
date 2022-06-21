/*
给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。

所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。
https://leetcode.cn/problems/defanging-an-ip-address/
*/
#include  <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        string str;
        const int size = address.size();
        for(int i=0; i<size; ++i){
            if(address[i]=='.')str+="[.]";
            else str+=address[i];
        }
        return str;
    }
};