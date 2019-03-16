int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int i,j,len2;
    int *numsdep,size;
    (*returnSize)=0;
    len2=nums2Size-1;
    size=nums1Size<nums2Size?nums1Size:nums2Size;
    numsdep=(int*)malloc(size*sizeof(int));
    int index=0;
    for(i=0;i<nums1Size;i++)
        for(j=0;j<=len2;j++){
            if(nums1[i]==nums2[j])
            {               
                nums2[j]=nums2[len2];
                len2--;  /**此处应该将数组2中与数组1相交的部分去掉，简单方法是将末尾元素提前，遍历长度减1**/
                numsdep[index++]=nums1[i];
                (*returnSize)++;
                break;
            }
        }
    return numsdep;
}

