/*
请你帮忙给从 1 到 n 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。

让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。

由于答案可能会很大，所以请你返回答案 模 mod 10^9 + 7 之后的结果即可。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/prime-arrangements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <math.h>

const int MOD = 1e9 + 7;
class Solution {
public:
    int numPrimeArrangements(int n) {
        int snum=0;
        int hnum=0;
        long result;
        for(int i=1; i<=n; ++i){
            if(isPrime(i)) ++snum;
            else ++hnum;
        }
        return (arr(snum)*arr(hnum))%MOD;
    }
    long arr(int num){
        long res = 1;
        for(int i=num; i>0; --i){
            res*=i;
            res%=MOD;
        }
        return res;
    }
        bool isPrime(int n) {
        if (n == 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};