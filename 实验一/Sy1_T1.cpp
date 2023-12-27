#include<iostream>
using namespace std;
#define n 10

int main() {
    int x;
    cout << "输入要查找的数：" << endl;
    cin >> x;
    int a[n];
    cout << "输入" << n << "个已排列的数" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int low = 0;
    int high = n - 1;
    int m = 0, j = 0, mid;
    //二分查找
    while (low <= high)
    {
        m++;
        mid = (low + high) / 2;
        if (x == a[mid])
        {
            cout << "i=" << mid << "j=" << mid << endl;
            break;
        }
        if (x > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    //当未找到时
    if (x < a[0])
    {
        cout << "i=" << -1 << "j=" << 0 << endl;
    }
    if (x > a[n - 1])
    {
        cout << "i=" << n - 1 << "j=" << n << endl;
    }
    if (x > a[mid] && x < a[n - 1])
    {
        cout << "i=" << mid << "j=" << mid + 1 << endl;
    }
    if (a[0] < x && x < a[mid])
    {
        cout << "i=" << mid - 1 << "j=" << mid << endl;
    }
    return 0;
}