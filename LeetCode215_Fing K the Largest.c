int findKthLargest(int* nums, int numsSize, int k) {
    int tag=0;
    int res=0;
    for(int i=0;i<numsSize-1;i++){
        res=1;        
        for(int j=0;j<numsSize-i-1;j++){
        if(nums[j]>nums[j+1]){
            tag=nums[j];
            nums[j]=nums[j+1];
            nums[j+1]=tag;
            res=0;
        }
        }
        if(res) break;
}
    return nums[numsSize-k];
        
    
}
