int removeElement(int* nums, int numsSize, int val) {
    int tag=0;
    int num=0;
    for(int j=0;j<numsSize;j++){
        if(nums[j]==val){
            num++;      
        }
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i]==val)
        {
            tag=i;
            for(int j=i+1;j<numsSize;j++)
            {
                if(nums[j]!=val){
                nums[i]=nums[j];
                nums[j]=val;break;}
            }
            
        }
        
    }
   return numsSize-num;
}
