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
void quickSort(vector<int>& s, int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;  
            if(i < j) 
                s[i++] = s[j];
            
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;  
            if(i < j) 
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1); // 递归调用 
        quickSort(s, i + 1, r);
    }
    PrintVector(s);
}
int quickSort_findValue(vector<int>& s, int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;  
            if(i < j) 
                s[i++] = s[j];
            
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;  
            if(i < j) 
                s[j--] = s[i];
        }
        s[i] = x; //交换基准
        //quickSort(s, l, i - 1); // 递归调用 
        //quickSort(s, i + 1, r);
        return i;
    }
}
/*
O（n）的算法。思路是利用快排的思想，以最后一个元素为基准，将数组一分为二，左边小于基准，右边大于基准，完成一趟分割，

基准的下标为index，这时，包括基准在内，左边有index+1个最小元素，若index+1=k，显然符合题意，直接将这index+1个元素输出即可，若不等于：

1.index>k-1，则前k个元素的右端点应该在基准的左边，所以更新查找范围的右端点，重新在左侧找；

2.index<k-1，则前k个最小元素包括基准，且其右端点在基准的右边，所以更新查找范围的左端点，重新在右侧找。


*/

vector<int> test01(vector<int>& input, int k)
{
    vector<int>result;

    if(input.empty() || k>input.size() || k < 0)
    {
        cout << " 非法输入 " << endl;
        return result;
    }

    int len = input.size();
    int start = 0;
    int end = len-1;

    int index = quickSort_findValue(input, start, end);

    while(index != k-1)
    {
        if(index>k-1)
            end = index-1;
        else
            start = index+1;
        index = quickSort_findValue(input, start, end);
    }
    for(int i = 0; i<k;i++)
        result.push_back(input[i]);
    return result;
}

int main()
{
    srand((unsigned int)time(NULL));

    //1. 生成随机数组
    vector<int> v;
    GenerateRandomNum(v, 10, 100, 10);
    PrintVector(v);

    //2. 输入K
    int k;
    cout << " 请输入K：";
    cin >> k;

    //3.算法
    vector<int> res = test01(v, k);
    PrintVector(res);

    return 0;
}
