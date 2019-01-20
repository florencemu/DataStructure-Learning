int removeDuplicates(int* nums, int numsSize) {
  
    if(numsSize<= 2){ 
        return numsSize; } 
    int count = 1;
    int k=1;
    for(int i = 1; i < numsSize; i++){ 
        if(nums[i] == nums[i-1]) { 
            if(count < 2) {
                nums[k++] = nums[i]; count++; 
            } 
        }
        else {
            count = 1; nums[k++] = nums[i]; 
        } 
    } 
    return k; 
}

