//插值查找-C语言实现
//基本思路：二分查找改进版，只需改一行代码。
//        mid=low+(key-a[low])/(a[high]-a[low])*(high-low)
//时间复杂度O(log2(log2n))

#include<stdio.h>
int insertSearch(int *sortedSeq, int seqLength, int keyData);

int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int location;
    int target = 4;
    location = insertSearch(array, 9, target);
    printf("%d\n", location);
    return 0;
}

int insertSearch(int *sortedSeq, int seqLength, int keyData)
{
    int low = 0, mid, high = seqLength - 1;

    while (low <= high)
    {
        mid = low + (keyData - sortedSeq[low]) / (sortedSeq[high] - sortedSeq[low]);
        if (keyData < sortedSeq[mid])
        {
            high = mid - 1;//是mid-1，因为mid已经比较过了
        }
        else if (keyData > sortedSeq[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
