//时间复杂度O(log2n) 
#include <stdio.h>  
#include <stdlib.h>  
#define MAXN 20  

/*
*产生斐波那契数列
* */
void Fibonacci(int *f)
{
    int i;
    f[0] = 1;
    f[1] = 1;
    for (i = 2; i < MAXN; ++i)
        f[i] = f[i - 2] + f[i - 1];
}

/*
* 查找
* */
int Fibonacci_Search(int *a, int key, int n)
{
    int i, low = 0, high = n - 1;
    int mid = 0;
    int k = 0;
    int F[MAXN];
    Fibonacci(F);
    while (n > F[k] - 1)          //计算出n在斐波那契中的数列  
        ++k;
    for (i = n; i < F[k] - 1; ++i) //把数组补全  
        a[i] = a[high];
    while (low <= high)
    {
        mid = low + F[k - 1] - 1;  //根据斐波那契数列进行黄金分割  
        if (a[mid] > key)
        {
            high = mid - 1;
            k = k - 1;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
            k = k - 2;
        }
        else
        {
            if (mid <= high) //如果为真则找到相应的位置  
                return mid;
            else
                return -1;
        }
    }
    return 0;
}

int main()
{
    int a[MAXN] = { 5, 15, 19, 20, 25, 31, 38, 41, 45, 49, 52, 55, 57 };
    int k, res = 0;
    printf("请输入要查找的数字:\n");
    scanf("%d", &k);
    res = Fibonacci_Search(a, k, 13);
    if (res != -1)
        printf("在数组的第%d个位置找到元素:%d\n", res + 1, k);
    else
        printf("未在数组中找到元素:%d\n", k);
    return 0;
}
