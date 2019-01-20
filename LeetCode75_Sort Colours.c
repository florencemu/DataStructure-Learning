void sortColors(int* nums, int numsSize) {
    int b=0,c=0,d=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==0) b++;
        else if(nums[i]==1) c++;
        else if(nums[i]==2) d++;
    }
    for(int j=0;j<b;j++) nums[j]=0;
    for(int j=b;j<b+c;j++) nums[j]=1;
    for(int j=b+c;j<numsSize;j++) nums[j]=2;
    
}
