/*
对数组进行离散化
输入:6
1 9999 100000 15 999 2

输出:
1 1
2 2
15 3
999 4
9999 5
100000 6
*/
#include <algorithm>
#include <iostream>
using namespace std;

int a[200000+10];
int main(){
    int n;
    cin>>n;
    for(int i=1 ; i<=n; ++i){
        scanf("%d", &a[i]);
    }

// 对数组进行排序 注意左闭右开区间
    sort(a+1,a+n+1);

// 去重 unique返回一个迭代器,指向数组去重后不重复的序列中最后一个元素的下一个元素的位置
    int len = unique(a+1,a+n+1)-(a+1);

    for(int i=1; i<=len ;++i){
        cout<< a[i]<< ' ';
// lower_bound 在有序数组中查找大于等于a[i]的第一个数的下标
        a[i] = lower_bound(a+1, a+n+1, a[i])-a;
        cout<< a[i]<< '\n';
    }

    system("pause");
    return 0;

}