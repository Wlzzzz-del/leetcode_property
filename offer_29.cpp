#include <iostream>
#include <vector>
/*https://leetcode.cn/problems/4ueAj6/*/
/*
给定循环单调非递减列表中的一个点，写一个函数向这个列表中插入一个新元素 insertVal ，使这个列表仍然是循环升序的。

给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。

如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。

如果列表为空（给定的节点是 null），需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。
*/
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head==NULL){
            Node* p = new Node(insertVal);
            p->next = p;
            return p;
        }       
        Node* i = head;
        Node* j = head->next;
        // 就单个节点
        if(i==j){
            Node* p = new Node(insertVal,i);
            i->next = p;
            return head;
        }
        while(j!=head){
            if(i->val<=insertVal && j->val>=insertVal){
                break;
            }
            if(i->val>j->val && (insertVal>i->val || insertVal<j->val)){
                break;
            }
            i = i->next;
            j = j->next;
        }
        Node* p = new Node(insertVal,p);
        i->next = p;
        return head;
    }
};

/*
总结:
只考虑了链中间的情况，忘记考虑到链尾和链头的情况。
*/