#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <set>
using namespace std;

/*
请实现有重复数字的有序数组的二分查找。
输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加一。
输入
    5,4,[1,2,4,4,5]
返回值
    3
说明
    输出位置从1开始计算 
*/

// 找等于value的值
int find_equal_value(vector<int>&array, int start, int end, int value)
{
    if(start > end)
        return array.size()+1;

    int mid = start + (end-start)/2;
    if(value == array[mid])
    {
        return mid+1;
    }
    else if(value < array[mid])
    {
        return find_equal_value(array, start, mid-1, value);
    }
    else
    {
        return find_equal_value(array, mid+1, end, value);
    }
}
int equal_bound_01(int n, int v, vector<int>& a) 
{
    return find_equal_value(a, 0, n-1, v);
}

// 找第一个大于等于value的值
int find_upper_value(vector<int>&array, int start, int end, int value)
{
    if(start > end)
        return array.size()+1;

    if(array[start] >= value)
        return start+1;
    int mid = start + (end-start)/2;

    if(array[mid] == value)
        return mid+1;

    else if(array[mid] > value)
    {
        return find_upper_value(array, start+1, mid, value);
    }
    else
    {
         return find_upper_value(array, mid+1, end, value);
    }
}

int upper_bound_01(int n, int v, vector<int>& a) 
{
    return find_upper_value(a, 0, n-1, v);
}

int main()
{
    int n;
    cout << " please input num of array : " << endl;
    cin >> n;

    int value;
    cout << " please input find the value : " << endl;
    cin >> value;

    vector<int> array;
    cout << "<---------- input value :---------->" << endl;
    for(int i  =0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        array.push_back(tmp);
    }

    cout << "<------- the result: ----> " << upper_bound_01(n, value, array) << endl;

    return 0;
}