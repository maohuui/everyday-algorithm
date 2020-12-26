#include <iostream>
using namespace std;

/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。*/
template <typename T>
class stack
{
public:
    stack()
    {
        m_iTop = -1;
        m_iCapacity = 100;
        m_pArray = new T[m_iCapacity];
    }
    stack(int capacity)
    {
        m_iTop = -1;
        m_iCapacity = capacity;
        m_pArray = new T[m_iCapacity];
    }
    ~stack()
    {
        delete[] m_pArray;
    }
    void pop()
    {
        if(m_iTop == -1)
            return;
        m_iTop--;
    }
    void push(T value)
    {
        m_iTop++;
        m_pArray[m_iTop] = value;
    }
    int size()
    {
        return m_iTop+1;
    }
    bool empty()
    {
        if(m_iTop == -1)
            return true;
        else 
            return false;
    }
    T top()
    {
        if(m_iTop == -1)
            return -1;
        return m_pArray[m_iTop];
    }

private:
    int m_iTop;
    int m_iCapacity;
    T* m_pArray;
};

class queue
{
public:
    void push(int node)
    {
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node);
    }
    int pop()
    {
        if(stack1.empty() && stack2.empty())
            return -1;
        if(!stack2.empty())
        {
            int tmp = stack2.top();
            stack2.pop();
            return tmp;
        }
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int tmp = stack2.top();
            stack2.pop();
            return tmp;
        }
        return -1;
    }
    int size()
    {
        return stack1.size()+stack2.size();
    }

    int back()
    {
        if(!stack1.empty())
            return stack1.top();
        else
        {
            while(!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
            return stack1.top();
        }
    }

    int front()
    {
        if(!stack2.empty())
            return stack2.top();
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            return stack2.top();
        }
    }
    bool empty()
    {
        if(stack2.empty() && stack1.empty())
            return true;
        else 
            return false;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

void test()
{
    queue q;

    cout << q.size() << endl;
    cout << q.empty() << endl;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(6);

    cout << " pop: " <<  q.pop() << endl;
    cout << " pop: " <<  q.pop() << endl;
    q.push(7);
    q.push(8);
    cout << " pop: " <<  q.pop() << endl;
    cout << " front: " <<  q.front() << endl;
    cout << " back: " <<  q.back() << endl;

    cout << q.size() << endl;
    cout << q.empty() << endl;
}

int main()
{
    test();
}