int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) 
{
    int m=matrixRowSize;
    int n=matrixColSize;
    int su=m*n;
    int* res=(int*)malloc(sizeof(int)*su);
    int cc=0;
    int k=0;
    int count=(m+1)/2;
    while(k<count && cc<su)
    {
        for(int i=k;i<n-k;i++)
        {
            res[cc]=matrix[k][i];
            cc++;
        }
        for(int i=k+1;i<m-1-k;i++)
        {
            res[cc]=matrix[i][n-1-k];
            cc++;
        }
        if(k!=m-1-k)
        {
            for(int i=k;i<n-k;i++)
            {
                res[cc]=matrix[m-1-k][n-1-i];
                cc++;
            }
        }
        if(k!=n-1-k)
        {
            for(int i=k+1;i<m-1-k;i++)
            {
                res[cc]=matrix[m-1-i][k];
                cc++;
            }
        }
        k++;       
    }
    return res;
}

