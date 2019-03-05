void moveZeroes(int* nums, int numsSize) {
    int yes=0;
    int a;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==0){
            yes++;
        }
        else{
            a=nums[i-yes];
            nums[i-yes]=nums[i];
            nums[i]=a;
        }

    }
}
