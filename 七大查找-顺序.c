//顺序查找C语言实现
//基本思路：用顺序结构存储数据（数组、链表），从前到后依次查询目标值，
//            如果发现则返回查找到的值，否则返回0.
//时间复杂度O(n) 
#include<stdio.h>

int FindBySeq(int *ListSeq, int ListLength, int KeyData);

int main()
{
    int TestData[5] = { 34, 35, 26, 89, 56 };
    int retData = FindBySeq(TestData, 5, 89);
    printf("retData: %d\n", retData);
    return 0;
}

int FindBySeq(int *ListSeq, int ListLength, int KeyData)
{
    int tmp = 0;
    int length = ListLength;
    for (int i = 0; i < ListLength; i++)
    {
        if (ListSeq[i] == KeyData)
            return i;
    }
    return 0;
}
