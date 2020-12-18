/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
时间限制：C/C++ 1秒，其他语言2秒 空间限制：C/C++ 64M,其他语言128M
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

//=====================================方法一：快速排序
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

//=====================================方法二：堆
/* https://www.cnblogs.com/chengxiao/p/6129630.html
    采用大堆
大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]  
小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2] 

1. 构建堆：将给定无序序列构造成一个大堆（一般升序采用大堆，降序采用小堆)。
          此时从最后一个非叶子结点开始（叶结点自然不用调整，第一个非叶子结点 arr.length/2-1=5/2-1=1），从左至右，从下至上进行调整。
          找到第二个非叶节点，进行调整


2. 调整堆 将堆顶元素与末尾元素进行交换，使末尾元素最大。然后继续调整堆，再将堆顶元素与末尾元素交换，得到第二大元素。如此反复进行交换、重建、交换。

总结：
　　a.将无需序列构建成一个堆，根据升序降序需求选择大顶堆或小顶堆;

　　b.将堆顶元素与末尾元素交换，将最大元素"沉"到数组末端;

　　c.重新调整结构，使其满足堆定义，然后继续交换堆顶元素与当前末尾元素，反复执行调整+交换步骤，直到整个序列有序。

*/
class BigHeapSort
{
public:
    BigHeapSort(vector<int>& arr)
    {
        int len = arr.size();
        //最后一个非叶子节点len/2-1
        for(int i = len/2-1; i >= 0; i--)
        {
            adjustHeap(arr, i, len);
        }
        for(int j = len-1; j > 0;j--)
        {
            swap(arr,0, j);
            adjustHeap(arr, 0, j);
        }
    }
   void adjustHeap(vector<int>& arr,int i,int length){
        int temp = arr[i];//先取出当前元素i
        for(int k=i*2+1;k<length;k=k*2+1){//从i结点的左子结点开始，也就是2i+1处开始
            if(k+1<length && arr[k]<arr[k+1]){//如果左子结点小于右子结点，k指向右子结点
                k++;
            }
            if(arr[k] >temp){//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
                arr[i] = arr[k];
                i = k;
            }else{
                break;
            }
        }
        arr[i] = temp;//将temp值放到最终的位置
    }
};

vector<int> test02(vector<int>& input, int k)
{
    vector<int>result;

    if(input.empty() || k>input.size() || k < 0)
    {
        cout << " 非法输入 " << endl;
        return result;
    }
    BigHeapSort bS(input);
    PrintVector(input);

    result.assign(input.begin(), input.begin()+k);
    return result;
}

//=====================================对数器
vector<int> test03(vector<int>& input, int k)
{
    vector<int>result;

    if(input.empty() || k>input.size() || k < 0)
    {
        cout << " 非法输入 " << endl;
        return result;
    }
    sort(input.begin(), input.end());
    result.assign(input.begin(), input.begin()+k);
    return result;
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

    vector<int> res = test02(v, k);
    PrintVector(res);

    vector<int> res_abs = test03(v, k);
    PrintVector(res_abs);

    int len1 = res.size();
    int len2 = res_abs.size();
    if(len1 != k || len2 != k || len1 != len2)
    {
        cout << " error " << endl;
        return -1;
    }
    for(int i = 0; i<len2; i++)
    {
        if(res[i] != res_abs[i])
        {
            cout << " error in " << i << endl;
            break;
        }
    }

    return 0;
}
