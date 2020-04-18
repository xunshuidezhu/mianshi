#include <algorithm>
#include <iostream>
using namespace std;

void perm(int arr[], int len)
{
    if (len < 2)
        return;
    int i, j, temp;
    do {
        //输出当前序列
        perm(arr, len - 1);
        printf("\n");
        i = j = len - 1;
        //向前查找第一个变小的元素
        while (i > 0 && arr[i] < arr[i - 1])
            --i;
        temp = i;
        if (i == 0)
            break;
        //先后查找第一个比arr[i-1]大的元素
        while (temp + 1 < len && arr[temp + 1] > arr[i - 1])
            ++temp;
        swap(arr[i - 1], arr[temp]); //交换两个值
        reverse(arr + i, arr + len); //逆序
    } while (true);
}

int main()
{
    int arr[] = { 1, 2, 3, 4 };
    perm(arr, 4);
    [&](){for (auto i : arr) {cout << i << "  "; cout << endl;};}();
}