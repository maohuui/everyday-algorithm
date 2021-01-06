#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <set>
using namespace std;

//给出两个有序的整数数组 和 ，请将数组 合并到数组 中，变成一个有序的数组

//========================
void mergeTwoArray01(vector<int>& v1, vector<int>& v2)
{
    int size1 = v1.size();
    int size2 = v2.size();

    int min_size = min(size1, size2);
    
    int i = 0;
    int j = 0;
    vector<int> result;
    cout << " ----min_size--- " << min_size << endl;

    while(i < min_size && j < min_size)
    {
        cout <<  i << ";" << j << endl;
        while(v1[i] <= v2[j] && i < min_size)
        {
            result.push_back(v1[i]);
            i++;
        }
        cout <<  i << ";" << j << endl;
        while (v2[j] <= v1[i] && j < min_size)
        {
            result.push_back(v2[j]);
            j++;
        }
        cout <<  i << ";" << j << endl;
    }
    cout << " ----min_size--- " << min_size << endl;
    cout <<  i << ";" << j << endl;

    while(i<size1)
    {
        result.push_back(v1[i]);
        i++;
    }
    cout <<  i << ";" << j << endl;
    while(j<size2)
    {
        result.push_back(v2[j]);
        j++;
    }
    cout << "[";
    int k = 0;
    while(k<result.size())
    {
        cout << result[k];
        k++;
        if(k<result.size())
            cout << ",";
    }
    cout <<"]" << endl;
}

void test01(vector<int>& v1, vector<int>& v2)
{
    mergeTwoArray01(v1, v2);
}

//==================
void mergeTwoArray02(int A[], int m, int B[], int n)
{
    int i=m-1,j=n-1;
    int k=m+n-1;
    while(i>=0 && j>=0)
    {
        if(A[i]>B[j]) A[k--]=A[i--];
        else A[k--]=B[j--];
    }
    while(i>=0)
    {
        A[k--]=A[i--];
    }
    while(j>=0)
    {
        A[k--]=B[j--];
    }
    
    cout << "[";
    int z = 0;
    k=m+n;

    while(z<k)
    {
        cout << A[z];
        z++;
        if(z<k)
            cout << ",";
    }
    cout <<"]" << endl;
}


int main()
{
    srand((unsigned int)time(NULL));

    //1. 生成随机数组
    vector<int> v1 = {1};
    vector<int> v2 = {2};
    //test01(v1, v2);

    int A[5] = {1};
    int B[5] = {2};
    mergeTwoArray02(A,1,B,1);

    return 0;
}