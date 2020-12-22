#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

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

//生成随机数
void GenerateRandomNum(vector<int> &input, int min, int max, int n)
{
	if(min == max)
		max = min + 1;
	if(n < 0)
		n = 1;
    for(int i = 0; i<n; i++)
    {
        int tmp = rand() % (max-min + 1) + min;
        input.push_back(tmp);
    }
}

//创建list
// 生成链表，是否有环，如果有环。如果有环，环在第几个节点上
ListNode* createNode(vector<int> &input, bool hasCycle, int n)
{
    if(input.size() < 1)
        return NULL;
    ListNode* pHead  = new ListNode(input[0]);
    ListNode* tmp = pHead;
    ListNode* pCircle = NULL;

    for(int i = 1; i< input.size(); i++)
    {
        ListNode* newNode = new ListNode(input[i]);
        tmp->next = newNode;

        tmp = tmp->next;
        if(i == n)
            pCircle = newNode;
    }
    if(hasCycle)
    {
        tmp->next = pCircle;
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

void PrintVector(vector<int> input)
{
    for(vector<int>::iterator it = input.begin(); it!= input.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//======================= 快慢指针
bool hasCycle01(ListNode *head) 
{
    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return false;
    ListNode* slow = head;
    ListNode* fast = head->next->next;
    while(fast != NULL)
    {
        if(slow == fast)
            return true;
        slow = slow->next;
        if(fast->next == NULL || fast->next->next == NULL )
            break;
        fast = fast->next->next;
    }
    return false;
}
void test01(vector<int> &input)
{
    ListNode* pHead = createNode(input, true, 3);

    cout << "是否有环： " << hasCycle01(pHead) << endl;

    //releaseNode(pHead);
}

//
bool hasCycle02(ListNode *head) 
{
    
}
void test02(vector<int> &input)
{

}

//
bool hasCycle03(ListNode *head) 
{
    
}
void test03(vector<int> &input)
{

}


int main()
{
    srand((unsigned int)time(NULL));

    //1. 生成随机数组
    vector<int> v;
    GenerateRandomNum(v, 10, 100, 10);
    PrintVector(v);

    test01(v);

    return 0;
}