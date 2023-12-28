#include <iostream>
using namespace std;
int binarysearch(int a[], int x, int left, int right)//二分搜索
{
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (x == a[middle])
            return middle;
        if (x > a[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }
    if (x > a[middle])
        return middle;
    else
        return middle - 1;
}
void shiftleft(int a[], int s, int t, int k)   //a[s,t]中元素循环左移k个位置
{
    int i, j, temp;
    for (i = 0; i < k; i++)
    {
        temp = a[t];
        for (j = t; j > s; j--)
            a[j] = a[j - 1];
        a[s] = temp;
    }
}
void mergefor(int a[], int k, int n)
{
    int i = 0, j = k;
    int p;
    while (i < j && j < n)
    {
        p = binarysearch(a, a[i], j, n - 1);
        shiftleft(a, i, p, p - j + 1);

        i += p - j + 2;
        j = p + 1;

    }
}
int main()
{
    int a[10] = { 1,5,23,88,4,15,44,55,66,100 };
    int x, temp;
    int i;
    mergefor(a, 4, 10);
    for (i = 0; i < 10; i++)
        cout << a[i] << ' ';
    return 0;
}