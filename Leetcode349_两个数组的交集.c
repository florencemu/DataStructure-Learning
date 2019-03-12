int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
     for(int i=1;i<nums1Size;i++) {
            int temp=nums1[i];
            int j=i-1;
            while(j>=0&&temp<nums1[j]) {
                nums1[j+1]=nums1[j];
                j--;
            }
            nums1[j+1]=temp;
        }
    for(int i=1;i<nums2Size;i++) {
            int temp=nums2[i];
            int j=i-1;
            while(j>=0&&temp<nums2[j]) {
                nums2[j+1]=nums2[j];
                j--;
            }
            nums2[j+1]=temp;
        }
    // 先排序
    int* n3=(int*)malloc(sizeof(int)*(nums1Size+nums2Size));
    int i=0,j=0;
    int m=0;
    while(i<nums1Size&&j<nums2Size)
    {
        if(nums1[i]>nums2[j]||(j>0&&nums2[j]==nums2[j-1]))
        {
            j++;
            continue;
        }
        if(nums1[i]<nums2[j]||(i>0&&nums1[i]==nums1[i-1]))
        {
            i++;
            continue;
        }
        if(nums1[i]==nums2[j])
        {
            n3[m]=nums1[i];
            m++;
            i++;
            j++;
            continue;
        }
    }
    *returnSize=m;
   
    return n3;
} 
