int pivotIndex(int* nums, int numsSize) 
{
    int n=numsSize;
    if(0==n)
    {
        return -1;
    }
    int left=0;
    int right=0;
    for(int i=1;i<n;i++)
    {
        right+=nums[i];
    }
    if(left==right)
    {
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        left+=nums[i-1];
        right-=nums[i];
        if(left==right)
        {
            return i;
        }
    }
    return -1;
}
