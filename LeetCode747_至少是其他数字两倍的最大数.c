int dominantIndex(int* nums, int numsSize) {
    int max=nums[0];
    int flag=0;
    int smax;

    for(int i=0;i<numsSize-1;i++){
        if(max<nums[i+1]){
            max=nums[i+1];
            flag=i+1;
        }
     
    }
  if(flag==0) smax=nums[1];
	else smax=nums[0];
    for(int i=0;i<numsSize;i++)
    {
		
		if(smax<=nums[i+1]&&nums[i+1]<max)
			smax=nums[i+1];
			
    }
	if(numsSize==1) flag=0;
	if(max<(smax*2)&&numsSize!=1) flag=-1;

    return flag;
    
}
