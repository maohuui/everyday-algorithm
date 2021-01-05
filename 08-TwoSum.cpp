
/*
给出一个整数数组，请在数组中找出两个加起来等于目标值的数，
你给出的函数twoSum 需要返回这两个数字的下标（index1，index2），需要满足 index1 小于index2.。注意：下标是从1开始的
假设给出的数组中只存在唯一解
例如：
给出的数组为 {20, 70, 110, 150},目标值为90
输出 index1=1, index2=2
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

//生成随机数: 生成 n个随机数放在 input 
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

//打印vector
void PrintVector(vector<int>& input)
{
    for(vector<int>::iterator it = input.begin(); it!= input.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//======================方法1
vector<int> twoSum01(vector<int>& numbers, int target)
{
    vector<int> res;
    for(int i = 0; i<numbers.size(); i++)
    {
        int temp1 = numbers[i];
        if(temp1 > target)
            continue;
        for(int j = i+1; j<numbers.size(); j++)
        {
            int temp2 = numbers[j];
            if((temp1 + temp2) == target)
            {
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
        }
    }
    return res;
}

void test01(vector<int>& numbers, int target)
{
    vector<int> result = twoSum01(numbers, target);
    PrintVector(result);
}

//======================方法2
vector<int> twoSum02(vector<int>& numbers, int target) {
    // write code here
}

void test02(vector<int>& numbers, int target)
{
    vector<int> result = twoSum02(numbers, target);
    PrintVector(result);
}

int main()
{
    srand((unsigned int)time(NULL));

    //1. 生成随机数组
    vector<int> v = {-3,4,3,90};

    //GenerateRandomNum(v, 1, 10, 3);
    PrintVector(v);

    //2. 输入target
    int target;
    target = 0;
    //cout << " 请输入target：";
    //cin >> target;

    test01(v, target);
    //test02(v, target);


    return 0;
}