/*
线段树:
线段树用于快速求解数字区间元素的和。
https://www.bilibili.com/video/BV1cb411t7AM?spm_id_from=333.337.search-card.all.click&vd_source=5ee2c54de9936b8b62b14ab50979b490
*/

#include <stdio.h>
#include <iostream>

void build_tree(int arr[], int tree[],int node, int start, int end){
    // param:
    // arr    给定的已知数组
    // tree   线段树数组
    // node   当前节点位置
    // start  开始的区间
    // end    结束的区间
    if(start == end)
    {
        tree[node]=arr[start];
        return;
    }

    int mid = (start+end)/2;
    int left_node = node*2+1;
    int right_node = node*2+2;

    build_tree(arr, tree, left_node, start, mid);
    build_tree(arr, tree, right_node, mid+1, end);

    tree[node] = tree[left_node]+tree[right_node];
}

void update_tree(int arr[], int tree[],int node, int start, int end, int index, int val){
    // param:
    // arr    给定的已知数组
    // tree   线段树数组
    // node   当前节点位置
    // start  开始的区间
    // end    结束的区间
    // index  修改的节点编号
    // val    修改的值
    if(start == end){
        arr[index] = val;
        tree[node] = val;
    }
    else{
    int mid = (start+end)/2;
    int left_node = node*2+1;
    int right_node = node*2+2;
    if(index>=start  && index<=mid){
        update_tree( arr, tree, left_node, start, mid, index, val);
    }
    else{
        update_tree( arr, tree, right_node, mid+1, end, index, val);
    }
    tree[node]=tree[left_node]+tree[right_node];
    }
}

int querytree(int arr[], int tree[], int node, int start, int end, int L, int R){
    // param:
    // arr    给定的已知数组
    // tree   线段树数组
    // node   当前节点位置
    // start  开始的区间
    // end    结束的区间
    // L      查询区间的左边界
    // val    查询区间的右边界
    if(L>end || R<start)return 0;
    else if(start==end || (L<start&&R>end) )return tree[node];
    else{
    int mid = (start+end)/2;
    int left_node  =  2*node+1;
    int right_node = 2*node+2;
    int sum_left = querytree(arr, tree, left_node, start, mid, L, R);
    int sum_right = querytree(arr, tree, right_node, mid+1, end, L, R);
    return sum_left+sum_right;
    }
}

int main(){
    int arr[] = {1,3,5,7,9,11};
    int size = 6;
    int tree[100] = {0};
    build_tree(arr,tree,0,0,size-1);
    update_tree(arr,tree,0,0,size-1,4,6);

    for(int i=0; i<size; ++i){
        printf("tree[%d]=%d\n",i,tree[i]);
    }

    printf("querytree:%d",querytree(arr,tree,0,0,size-1,2,5));
    system("pause");
    return 0;
}