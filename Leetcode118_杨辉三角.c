//第k层有k个元素
//每层第一个以及最后一个元素值为1
//对于第k（k > 2）层第n（n > 1 && n < k）个元素A[k][n]，A[k][n] = A[k-1][n-1] + A[k-1][n]
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    
    int i, j;
    int **array;
    *columnSizes = calloc(numRows, sizeof(int));//申请返回数组行数
    for(i = 0; i < numRows; i++)
        (*columnSizes)[i] = i+1;//计算返回数组每行元素数
    array = calloc(numRows, sizeof(int *));//申请返回数组

    for(i = 0; i < numRows; i++){
        array[i] = calloc((*columnSizes)[i], sizeof(int));//申请返回数组每行元素空间
        for(j = 0; j < (*columnSizes)[i]; j++){
            
            if(i < 2)
                array[i][j] = 1;
            else
            {
                if(j > 0 && j < (*columnSizes)[i] -1)
                    array[i][j] = array[i-1][j] + array[i-1][j-1];
                else
                    array[i][j] = 1;
            }  
            
        }
    }
    
    return array;
}



