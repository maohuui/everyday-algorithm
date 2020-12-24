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
//合并两个有序数组
void mergeTwoArray(vector<int>& v1, vector<int>& v2)
{
    int size1 = v1.size();
    int size2 = v2.size();

    int min_size = min(size1, size2);
    
    int i = 0;
    int j = 0;
    vector<int> result;
    cout << " ----min_size--- " << min_size << endl;

    while(i < min_size && j < min_size)
    {
        cout <<  i << ";" << j << endl;
        while(v1[i] <= v2[j] && i < min_size)
        {
            result.push_back(v1[i]);
            i++;
        }
        cout <<  i << ";" << j << endl;
        while (v2[j] <= v1[i] && j < min_size)
        {
            result.push_back(v2[j]);
            j++;
        }
        cout <<  i << ";" << j << endl;
    }
    cout << " ----min_size--- " << min_size << endl;
    cout <<  i << ";" << j << endl;

    while(i<size1)
    {
        result.push_back(v1[i]);
        i++;
    }
    cout <<  i << ";" << j << endl;
    while(j<size2)
    {
        result.push_back(v2[j]);
        j++;
    }
    for(int k=0; k<result.size(); k++)
    {
        cout << result[k] << " " ;
    }
    cout << endl;
}
ListNode* mergeTwoLists01(ListNode* l1, ListNode* l2) 
{

    
}

void test01(vector<int>& v1, vector<int>& v2)
{
    ListNode* l1 = createNode(v1);
    ListNode* l2 = createNode(v2);

    ListNode* newNode = mergeTwoLists01(l1, l2);
    PrintList(newNode);

    releaseNode(l1);
    releaseNode(l2);
}

//==============================
ListNode* mergeTwoLists02(ListNode* l1, ListNode* l2) 
{
    ListNode* tmp1 = l1;
    ListNode* tmp2 = l2;

    ListNode* newNode = NULL;
    if(tmp1 == NULL)
        return tmp2;
    if(tmp2 == NULL)
        return tmp1;
    
    /*
    if(tmp1->value < tmp2->value)
        newNode = tmp1;
    else
        newNode = tmp2;
    */

    while (tmp1 != NULL && tmp2 != NULL)
    {
        
        while (tmp1->value > tmp2->value)
        {
            /* code */
        }
        
    }
    
}

void test02(vector<int>& v1, vector<int>& v2)
{
    ListNode* l1 = createNode(v1);
    ListNode* l2 = createNode(v2);

    ListNode* newNode = mergeTwoLists01(l1, l2);
    PrintList(newNode);

    releaseNode(l1);
    releaseNode(l2);
}

int main()
{
    srand((unsigned int)time(NULL));

    //1. 生成随机数组
    vector<int> v1 = {1, 4, 6, 7, 7, 9};
    vector<int> v2 = {2, 3, 6, 8, 9, 10, 25};

    mergeTwoArray(v1, v2);

    return 0;
}