/*方法一：
每次都把最后一个元素取出，前面元素往后移，循环k次。*/
void rotate(int* nums, int numsSize, int k) {
    int temp=0;
   
    for(int i=0;i<k;i++){
        temp=nums[numsSize-1];
        for(int j=numsSize-2;j>=0;j--){
            nums[j+1]=nums[j];
        }
        nums[0]=temp;
    }
}

/*方法二：
反转n-k个元素，再反转后k个元素，在全部反转，但应注意numsSize<k这种情况。*/
void re(int* nums, int start ,int end){
    
    while(start<end){
        int temp=nums[start];
        nums[start++]=nums[end];
        nums[end--]=temp;
    }
}

void rotate(int* nums, int numsSize, int k) {
    
    if(numsSize<k){
        k=k%numsSize;
    re(nums,0,numsSize-k-1);
    re(nums,numsSize-k,numsSize-1);
    re(nums,0,numsSize-1);
    }else{
        
    re(nums,0,numsSize-k-1);
    re(nums,numsSize-k,numsSize-1);
    re(nums,0,numsSize-1);
    }
 
}


