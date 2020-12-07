/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
时间限制：C/C++ 1秒，其他语言2秒 空间限制：C/C++ 64M,其他语言128M
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
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
void PrintVector(vector<int> input)
{
    for(vector<int>::iterator it = input.begin(); it!= input.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void swap(vector<int> &input, int i, int j)
{
    int tmp = input[i];
    input[i] = input[j];
    input[j] = tmp;
}

//方法一：快速排序
void quickSort(vector<int>& input, int left, int right)
{
    if(left >= right)
        return;

    int base = input[left];
    int i = left;
    int j = right;

    cout << "----------------" << endl;
    cout << " i: " << i << " j: " << j << endl;

    while(i < j)
    {
        while(input[i] <= input[base] && i < j)
        {
            i++;
        }
        //cout << " i: " << i << " j: " << j << endl;

        while(input[j] >= input[base] && i < j)
        {
            j--;
        }
        if(i < j)
        {
            int tmp = input[i];
            input[i] = input[j];
            input[j] = tmp;
        }    
        //swap(input, i, j);
    }

    input[left] = input[i];
    input[i] = base;
    PrintVector(input);
    cout << "----------------" << endl;

    quickSort(input, left, i-1);
    quickSort(input, i+1, right);

}
void test01(vector<int>& input, int k)
{
    quickSort(input, 0, input.size()-1);
}

int main()
{
    srand((unsigned int)time(NULL));

    //1. 生成随机数组
    vector<int> v;
    GenerateRandomNum(v, 10, 100, 5);
    PrintVector(v);

    //2. 输入K
    int k;
    cout << " 请输入K：";
    cin >> k;

    //3.算法
    test01(v, k);

    return 0;
}