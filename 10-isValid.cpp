#include <iostream>
#include <string.h>
#include <stack>
using namespace std;


/*
给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。
*/
//========================方法一：stack
bool judge(char a, char b)
{
    if(a == '(' && b == ')')
        return true;
    else if(a == '[' && b == ']')
        return true;
    else if(a == '{' && b == '}')
        return true;
    else 
        return false;
}

bool isValid01(string s)
{
    stack<char> st;
    if(s.size() < 2 || s.size()%2  == 1)
        return false;
    for(int i =0; i<s.size(); i++)
    {
        char c = s[i];
        
        if(c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else if(c == ')' || c == '}' || c == ']')
        {
            if(st.empty())
                return false;
            char top = st.top();
            if(judge(top, c) == false)
                return false;
            st.pop();
        }
    }
    if(st.empty())
        return true;
    else 
        return false;
}
//========================方法二：
bool isValid02(string s)
{

}


int main()
{
    string s;
    s = "{[[]]}";

    cout << isValid01(s) << endl;

    return 0;
}