#include <iostream>
#include <string.h>
#include <vector>
using namespace std;



/*
给定一个数组arr，返回子数组的最大累加和
例如，arr = [1, -2, 3, 5, -2, 6, -1]，所有子数组中，[3, 5, -2, 6]可以累加出最大的和12，所以返回12.
[要求]
时间复杂度为O(n)O(n)，空间复杂度为O(1)O(1)

*/

int maxsumofSubarray(vector<int>& arr) 
{
    int sum = arr[0];
    int ret = 0;
    for(int i = 1; i<arr.size(); i++)
    {
        sum += arr[i];
        cout << "arr[i]: " << arr[i] << " sum: ";
        cout << sum << endl;
        if(ret < sum)
            ret = sum;
        if(sum < 0 || sum < arr[i])
            sum = arr[i];
    }
    return ret;
}

int main()
{
    vector<int> v = {1, -2, -3, 5, 2, 6, -1};
    int ret = maxsumofSubarray(v);
    cout << ret << endl;

    return 0;
}