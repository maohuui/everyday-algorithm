#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <set>
using namespace std;

/*
将两个有序的链表合并为一个新链表，要求新的链表是通过拼接两个链表的节点来生成的，且合并后新链表依然有序。
*/

struct ListNode
{
    int value;
    ListNode* next;
    ListNode(int tmp)
    {
        value = tmp;
        next = NULL;
    }
};
//打印List
void PrintList(ListNode* pHead)
{
    while(pHead != NULL)
    {
        cout << pHead->value << " ";
        pHead = pHead->next;
    }
    cout << endl;
}

//创建list
ListNode* createNode(vector<int> &input)
{
    if(input.size() < 1)
        return NULL;
    ListNode* pHead  = new ListNode(input[0]);
    ListNode* tmp = pHead;

    for(int i = 1; i< input.size(); i++)
    {
        ListNode* newNode = new ListNode(input[i]);
        tmp->next = newNode;

        tmp = tmp->next;
    }
    return pHead;
}

//释放list
void releaseNode(ListNode* pHead)
{
    if(pHead == NULL)
        return;
    while(pHead != NULL)
    {
        ListNode* tmp = pHead->next;
        delete pHead;
        pHead  = tmp;
    }
    pHead = NULL;
}
//=========================================
void test01(vector<int>& v1, vector<int>& v2)
{
    ListNode* l1 = createNode(v1);
    ListNode* l2 = createNode(v2);


    releaseNode(l1);
    releaseNode(l2);
}

//==============================

int main()
{
    srand((unsigned int)time(NULL));

    //1. 生成随机数组
    vector<int> v1 = {1, 4, 6};
    vector<int> v2 = {2, 3, 6};

    return 0;
}