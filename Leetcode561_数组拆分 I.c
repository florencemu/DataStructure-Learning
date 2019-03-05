//快速排序

void my_qsort(int* nums, int l, int r) { 
    if(l<r) {
        int i=l+1;//左端点，从基准值的下一个开始比较 
        int j=r;//右端点 
        while(i<j) { 
            if(*(nums+i)>*(nums+l)){
                //若右边数据比关键值大，则把该值放到右端点（交换该值与右端点值） 
             int temp=*(nums+j); 
             *(nums+j)=*(nums+i); 
                *(nums+i)=temp; 
                j--;
                //右端点右移 
            } 
                else//如果没有比他更小的,就选择下一个继续比较 
                { i++; } } 
 //若左边数据比关键值小，则把该值放到左端点（交换该值与左端点值） 
        if(*(nums+i)>=*(nums+l)) 
        { i--; } 
        int temp=*(nums+i); 
        *(nums+i)=*(nums+l); 
        *(nums+l)=temp;
        my_qsort(nums, l, i-1);//递归调用 
        my_qsort(nums, i+1, r); } } 

int arrayPairSum(int* nums, int numsSize) { 
    my_qsort(nums, 0, numsSize-1); 
    int sum=0; 
    for(int i=0; i<numsSize; i+=2) { 
        sum+=*(nums+i); 
    } 
    return sum; }

