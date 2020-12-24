#include <iostream>
using namespace std;


/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

//========================递归
int jumpFloor01(int number) 
{
    if(number == 1)
        return 1;
    if(number == 2)
        return 2;

    return jumpFloor01(number-1) + jumpFloor01(number-2);
}
void test01(int n)
{
    cout << " jumps way: " << jumpFloor01(n) << endl;
}

int main()
{
    int n;
    cout << " input the number : " ;
    cin >> n;

    test01(n);
}