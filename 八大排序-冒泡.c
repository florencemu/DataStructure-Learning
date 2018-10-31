void BubbleSort(int a[])
{
    int n=sizeof(a)/sizeof(int);
    int i,j;
    int change=1;
    for(i=1;i<n && change;i++)
    {
        change=0;
        for(j=0;j<=n-i-1;j++)
        {
            if(n[j]>n[j+1])
            {
                n[j]=n[j]^n[j+1];
                n[j+1]=n[j]^n[j+1];
                n[j]=n[j]^n[j+1];
                change=1;
            }
        }
    }
}

