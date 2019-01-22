int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) 
{
    int m=matrixRowSize;
    int n=matrixColSize;
    int su=m*n;//返回数组元素数
    int* res=(int*)malloc(sizeof(int)*su);//开辟返回数组
    int cc=0;
    int k=0;
    int count=(m+1)/2;//螺旋层数
    while(k<count && cc<su)
    {
	//从右至左横向遍历(纵定)
        for(int i=k;i<n-k;i++)
        {
            res[cc]=matrix[k][i];
            cc++;
        }
	//从上至下纵向遍历去头尾(横定)
        for(int i=k+1;i<m-1-k;i++)
        {
            res[cc]=matrix[i][n-1-k];
            cc++;
        }
	//从左至右横向遍历(纵定)
        if(k!=m-1-k)
        {
            for(int i=k;i<n-k;i++)
            {
                res[cc]=matrix[m-1-k][n-1-i];
                cc++;
            }
        }
	//从下至上纵向遍历去头尾(横定)
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

