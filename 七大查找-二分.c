//二分查找-C语言实现
//基本思路：将排序好的数据存放到数组里（不能是链表）
//        这只前中后标签，与中间元素比，若小于就将后变为原来的中
//        继续计算中，比较，循环，直至等于中，或循环结束。
//时间复杂度O(log2n) 
#include<stdio.h>
int binsearch(int *sortedSeq, int seqLength, int keyData);

int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int location;
    int target = 4;
    location = binsearch(array, 9, target);
    printf("%d\n", location);
    return 0;
}

int binsearch(int *sortedSeq, int seqLength, int keyData)
{
    int low = 0, mid, high = seqLength - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;//奇数，无论奇偶，有个值就行
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
