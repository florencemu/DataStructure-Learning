int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int i=0;
    int sum1=0,sum2=0;
    for(i;i<numsSize;i++){
        if(nums[i]==0) 
        {
            if(sum2==0||sum1>sum2) sum2=sum1;
            sum1=0;
        }
        else sum1++;
    }
    if(sum1>sum2) sum2=sum1;
    if(numsSize==1&&nums[0]==1) sum2=1;
    if(numsSize==2)
    {
        if(nums[0]==1&&nums[1]==0) sum2=1;
        else if(nums[0]==1&&nums[1]==1) sum2=2;
	}
    if((i==numsSize-1)&&nums[i]==1&&sum2==0) sum2=1;
    return sum2;    
}
