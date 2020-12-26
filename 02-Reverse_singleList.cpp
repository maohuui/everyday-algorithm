<<<<<<< HEAD
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

void PrintVector(vector<int> input)
{
    for(vector<int>::iterator it = input.begin(); it!= input.end(); it++)
    {
        cout << *it << " ";
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

//========================
ListNode* ReverseList(ListNode* pHead)
{
    if(pHead ==  NULL)
        return NULL;
    ListNode* pNew = pHead;
    ListNode* pLast = pHead->next;
    ListNode* tmp;
    if(pLast == NULL)
    {
        return pHead;
    }

    //pHead->next = NULL;

    while(pNew != NULL )
    {
        tmp = pLast->next;
        pLast->next = pNew;
        pNew = pLast;
        if(tmp == NULL)
            break;
        pLast = tmp;
    }
    pHead->next = NULL;
    return pLast;
}

void test01(vector<int>& v)
{
    ListNode* head = createNode(v);
    PrintList(head);

    cout << "======1======== " << endl;
    ListNode* newHead = ReverseList(head);
    PrintList(newHead);

    releaseNode(newHead);
}

//=======================

void test02()
{

}
//=====================

void test03()
{

}

int main()
{
    srand((unsigned int)time(NULL));

    //1. 生成随机数组
    vector<int> v;
    GenerateRandomNum(v, 10, 100, 1);
    PrintVector(v);

    test01(v);


    return 0;
}
=======
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

void PrintVector(vector<int> input)
{
    for(vector<int>::iterator it = input.begin(); it!= input.end(); it++)
    {
        cout << *it << " ";
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

//========================
ListNode* ReverseList01(ListNode* pHead)
{
    if(pHead ==  NULL)
        return NULL;
    ListNode* pNew = pHead;
    ListNode* pLast = pHead->next;
    ListNode* tmp;
    if(pLast == NULL)
    {
        return pHead;
    }

    //pHead->next = NULL;

    while(pNew != NULL )
    {
        tmp = pLast->next;
        pLast->next = pNew;
        pNew = pLast;
        if(tmp == NULL)
            break;
        pLast = tmp;
    }
    pHead->next = NULL;
    return pLast;
}

void test01(vector<int>& v)
{
    ListNode* head = createNode(v);
    PrintList(head);

    cout << "======1======== " << endl;
    ListNode* newHead = ReverseList01(head);
    PrintList(newHead);

    releaseNode(newHead);
}

//======================= reverse
ListNode* ReverseList02(ListNode* pHead)
{
    vector<int> cV ;
    ListNode* pTmp = pHead;
    while(pTmp != NULL)
    {
        int tmp = pTmp->value;
        cV.push_back(tmp);
        pTmp = pTmp->next;
    }

    reverse(cV.begin(), cV.end());
    cout << "-------------------\n" << endl;
    PrintVector(cV);

    ListNode* pNew = createNode(cV);
    return pNew;
}
void test02(vector<int>& v)
{
    ListNode* pNode = createNode(v);
    ListNode* pNew  = ReverseList02(pNode);

    cout << "-------------------\n" << endl;
    PrintList(pNew);

    releaseNode(pNode);
    releaseNode(pNew);
}
//=====================边遍历边反转
ListNode* ReverseList03(ListNode* pHead)
{
    ListNode* tmp = pHead->next;
    if(tmp == NULL)
    {
        cout << " one node " << endl;
        return pHead;
    }

    ListNode* newNode = NULL;

    while( pHead != NULL)
    {
        pHead->next = newNode;
        newNode = pHead;
        if(tmp == NULL)
            break;
        pHead = tmp;
        tmp = tmp->next;
    }
    return pHead;
}

void test03(vector<int>& v)
{
    if(v.size() == 0)
    {
        cout << " No node " << endl;
    }
    ListNode* pNode = createNode(v);
    ListNode* pNew  = ReverseList03(pNode);

    cout << "-------------------\n" << endl;
    PrintList(pNew);

    releaseNode(pNew);
}

int main()
{
    srand((unsigned int)time(NULL));

    //1. 生成随机数组
    vector<int> v;
    GenerateRandomNum(v, 10, 100, 10);
    PrintVector(v);

    test03(v);

    return 0;
}
>>>>>>> a970f60f3ef3026cc68f51217b6d53abfb18b63d
