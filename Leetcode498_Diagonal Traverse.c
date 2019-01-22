
//遍历分左下到左上和右上到右下

//观察每个对角线上的元素发现在同一对角线上元素的坐标和为一定值，如第一的对角线为2，依次为3，4，5，6。最大到行数和列数之和。

//故可从2开始到行数和列数和遍历。每一个值对应一条对角线，行依次减，列依次对应加为左下到左上。行依次加，列依次减对应右上到右下，注意边界条件即可。

int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize) {
    *returnSize = matrixRowSize * matrixColSize;  //计算返回数组长度
    int size = matrixRowSize + matrixColSize;//计算最大对角线和
    int bit = 0,row,col,state=0;
    int *obj = (int*)malloc((*returnSize) * sizeof(int));//申请返回数组空间
    
    for(int i=2;i<=size;i++){
	//左下到右上     
        if(bit==0){
	//计算当前对角线元素纵坐标
            if(i>matrixRowSize + 1) 
		col = i - matrixRowSize;//结束对角线(1)
            else col = 1;//起始对角线(1)
            //遍历对角线元素
	    //行减列加遍历 
            for(int j=col;j<i && j-1 < matrixColSize && i-j-1<matrixRowSize;j++){
                obj[state] = matrix[i-j-1][j-1];
                state++;               
            } 
            bit = 1;
            continue;
        }
	//右上到左下
        if(bit==1){
	//计算当前对角线元素横坐标
             if(i>matrixColSize + 1) 
		row = i - matrixColSize;//结束对角线(1)
            else row = 1;//起始对角线(1)
            //遍历对角线元素
	    //行加列减遍历 
             for(int j=row;j<i && j-1<matrixRowSize && i-j-1<matrixColSize;j++){
                 obj[state] = matrix[j-1][i-j-1];
                state++;                
            }
            
            bit = 0; 
        }
    }   
    return obj;
    
}

