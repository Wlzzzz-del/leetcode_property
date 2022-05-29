// https://leetcode.cn/problems/validate-ip-address/submissions/
/*
给定一个字符串 queryIP。如果是有效的 IPv4 地址，返回 "IPv4" ；如果是有效的 IPv6 地址，返回 "IPv6" ；如果不是上述类型的 IP 地址，返回 "Neither" 。

有效的IPv4地址 是 “x1.x2.x3.x4” 形式的IP地址。 其中 0 <= xi <= 255 且 xi 不能包含 前导零。例如: “192.168.1.1” 、 “192.168.1.0” 为有效IPv4地址， “192.168.01.1” 为无效IPv4地址; “192.168.1.00” 、 “192.168@1.1” 为无效IPv4地址。

一个有效的IPv6地址 是一个格式为“x1:x2:x3:x4:x5:x6:x7:x8” 的IP地址，其中:

1 <= xi.length <= 4
xi 是一个 十六进制字符串 ，可以包含数字、小写英文字母( 'a' 到 'f' )和大写英文字母( 'A' 到 'F' )。
在 xi 中允许前导零。
例如 "2001:0db8:85a3:0000:0000:8a2e:0370:7334" 和 "2001:db8:85a3:0:0:8A2E:0370:7334" 是有效的 IPv6 地址，而 "2001:0db8:85a3::8A2E:037j:7334" 和 "02001:0db8:85a3:0000:0000:8a2e:0370:7334" 是无效的 IPv6 地址。
*/
#include <iostream>
#include <string>
#include <vector>

class Solution {
private:
    std::string ip6="IPv6";
    std::string ip4="IPv4";
    std::string nei="Neither";
public:
    std::string validIPAddress(std::string queryIP) {
        //valid_IPv4
        if(valid_IPv4(queryIP))return ip4;
        else if(valid_IPv6(queryIP))return ip6;
        else return nei;
    }
private:
    bool valid_IPv4(std::string IP){
        int pos=0;
        int temp=0;
        std::string num;
        int ball = IP.size();
        int aall = 0;

        for(int i=0;i<4;++i){
        pos = IP.find('.');
        if(pos==0)return false;
        num = IP.substr(0,pos);
        IP = IP.substr(pos+1,IP.size()-num.size());
        aall += num.size()+1;
        if(num[0]=='0')return false;
        int nsize = num.size();
        for(int j=0;j<nsize;++j){
            if(!isdigit(num[j]))return false;
        }
        temp = std::stoi(num);
        // 缺少前置0判断
        if(temp<0||temp>255)return false;
        }
        std::cout<<aall<<std::endl;
        std::cout<<ball<<std::endl;
        if(ball!=aall)return false;

        return true;
    }

    bool valid_IPv6(std::string IP){
        int pos=0;
        std::string num;
        int ball = IP.size();
        int aall = 0;

        for(int i=0;i<8;++i){
        pos = IP.find(':');
        if(pos==0)return false;
        num = IP.substr(0,pos);
        IP = IP.substr(pos+1,IP.size()-num.size());
        aall += num.size()+1;

        int nsize = num.size();
        if(nsize<1||nsize>4)return false;
        std::cout<<num<<std::endl;
        for(int j=0;j<nsize;++j){
            if(!isxdigit(num[j]))return false;
        }
        }
        if(aall!=ball)return false;
        return true;
    }
};

int main(){
    std::string queryIP ="172.16.254.1";
    Solution s;
    std::cout<<s.validIPAddress(queryIP);
    system("pause");
    return 0;
}