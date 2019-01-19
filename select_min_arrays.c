//要求是连续子数组，所以我们必须定义 i，j两个指针，i 向前遍历，j 向后遍历，相当与一个滑块，这样所有的子数组都会在 [i...j] 中出现，如果 nums[i..j] 的和小于目标值 s，那么j向后移一位，再次比较，直到大于目标值 s 之后，i 向前移动一位，缩小数组的长度。遍历到i到数组的最末端，就算结束了，如果不存在符合条件的就返回 0。


int minSubArrayLen(int s, int* nums, int numsSize) {
    int old=0,new=0;
    int sum=0;
    for(int j=0;j<numsSize;j++){
        for(int i=j;i<numsSize;i++){
            if(nums[j]>=s) {new=1;break;}
            else{
            sum+=nums[i];
            old++;
            if(sum>=s){
                if(j==0) new=old;
                else if(old<new) new=old;
                old=0;break;
            }}
        }
        sum=0;
    }
    if(numsSize==1||new>numsSize) return 0;
    else return new;
}
