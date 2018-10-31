#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//堆调整算法
void HeapAdjust(int num[],int i,int length)
{
    //定义max保存以num[i]为根的最小堆中最大值的下标，初始值为i
    int max=i;
    //判断num[i]是否为根结点 （下标i<=length/2-1的结点都是根节点）
    if(i<=length/2-1)
    {
        //判断num[2*i+1]是否在堆内，若在,判断其是否大于num[max]，若大于，将其下标2*i+1赋予给max
        if((2*i+1)<length && num[2*i+1]>num[max])
        {
            max=2*i+1;
        }
        //判断num[2*(i+1)]是否在堆内，若在，判断其是否大于num[max]，若大于，将其下标2*(i+1)赋予给max
        if((2*(i+1))<length && num[2*(i+1)]>num[max])
        {
            max=2*(i+1);
        }
        //若i不等于max，则说明以num[i]为根的最小堆中num[max]是最大值，将num[max]与根结点num[i]交换位置
        if(i!=max)
        {
            num[i]=num[i]^num[max];
            num[max]=num[i]^num[max];
            num[i]=num[i]^num[max];
            //交换后，为防止以num[max]为根结点的最小堆结构发生变换，再次调用堆调整算法
            HeapAdjust(num,max,length);
        }
    }
}
//堆排序算法
void HeapSort(int num[],int length)
{
    int i;
    //找到最后一个非叶子结点，先从最后一个非叶子结点组成的最小堆进行堆调整
    for(i=length/2-1;i>=0;i--)
        //调用调整堆算法将数组从下往上调整为大根堆
        HeapAdjust(num,i,length);
    for(i=length-1;i>0;i--)
    {
        //将数组第一个数和最后一个数换位置
        num[i]=num[i]^num[0];
        num[0]=num[i]^num[0];
        num[i]=num[i]^num[0];
        //继续调用调整堆算法，将剩余数据组成的堆从上往下调整为大根堆
        HeapAdjust(num,0,i);
    }
}
int main()
{
    int i;
    int num[]={8,5,7,12,48,36,4};
    HeapSort(num,sizeof(num)/sizeof(int));
    for(i=0;i<sizeof(num)/sizeof(int);i++)
    {
        printf("%d\t",num[i]);
    }
    printf("\n");
}


