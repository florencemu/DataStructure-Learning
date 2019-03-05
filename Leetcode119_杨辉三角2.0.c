/*主要方法是采用倒序，从后往前加，每次循环逐个覆盖。
第一次外循环 1
第二次外循环 1  1
第三次外循环 1  2  1
第三次外循环 1  3  3  1
规律如果col == row或col == 0 则res[col] = 1,否则res[col] = res[col] + res[col - 1];仅覆盖了res[col].*/

int* getRow(int rowIndex, int* returnSize) {
       if (rowIndex < 0)
        return NULL;
     
    int *res = (int*)malloc(sizeof(int) * (rowIndex + 1));
     
    for (int row = 0; row <= rowIndex; row++)
        for (int col = row; col >= 0; col--)//控制下标数循环
            res[col] = (col == 0 || col == row) ? 1 : res[col] + res[col - 1];//依次覆盖上一层
     
    *returnSize = rowIndex + 1;
    return res;

}
