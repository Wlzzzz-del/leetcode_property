#include <vector>
#include <math.h>
#include <iostream>

class Solution {
public:
    // 枚举法超时
    int countPrimes(int n) {
        std::vector<int> tb(n);
        if(n==1||n==0)return 0;
        int cnt=0;
        for(int i=2; i<n; ++i){
            bool isprime = true;
            for(int j=2; j*j<=i; ++j){
                if(i%j==0){
                isprime = false;
                break;}
            }
            if(isprime)++cnt;
        }
        return cnt;
    }
};

class Solution{
    public:
    // 埃氏筛
    int countPrimes(int n){
        std::vector<int> tb(n,1);
        int cnt = 0;
        for(int i=2;i<n;++i){
            if(tb[i]){
                ++cnt;
                if((long long)i*i<n){
                for(int j=i*i;j<n;j+=i){
                    tb[j]=0;
                }
                }
            }
        }
        return cnt;
    }
};