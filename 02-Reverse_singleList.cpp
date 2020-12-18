#include <iostream>
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
        tmp->new = newNode;

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
    ListNode* pLast = pHead;
    while(pHead != NULL)
    {
        ListNode* tmp = pHead->next;
        if(tmp == NULL)
            break;
        pHead->next->next = pHead;
        pHead = pHead->next;
    }
    pLast->next = NULL;
    return pHead;
}

void test01(vector<int>& v)
{
    ListNode* head = createNode(v);
    PrintList(head);

    cout << "============== " << endl;
    head = ReverseList(head);
    PrintList(head);

    releaseNode(head);
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
    GenerateRandomNum(v, 10, 100, 5);
    PrintVector(v);

    test01(v);


    return 0;
}