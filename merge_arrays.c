void merge(int* nums1, int m, int* nums2, int n) {
 int tag=0; 
    if(m==0){
        for(int i=0;i<n;i++) nums1[i]=nums2[i];
    }
    
    else{
    for(int i=0;i<n;i++){
        tag=0;
     for(int j=0;j<m;j++)
     {
         if(nums2[i]>nums1[m-1]){
              nums1[m]=nums2[i]; m++;tag=1;
         }
         else if(nums2[i]<=nums1[j]) {
             for(int k=m-1;k>j-1;k--) 
                 nums1[k+1]=nums1[k];
             nums1[j]=nums2[i];
             m++;tag=1;
         }
       
         if(tag) break;
     }
 }
    }
}
