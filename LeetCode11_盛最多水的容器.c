int maxArea(int* height, int heightSize) {
    int i,j,max=0,temp,sum;
    for(i=0;i<heightSize-1;i++)
    {
        for(j=i+1;j<heightSize;j++)
    {
        if(height[i]<=height[j])
            temp=height[i];
        else
            temp=height[j];
        sum=temp*(j-i);
        if(sum>max)
            max=sum;   
    }
    }
return max;
}
