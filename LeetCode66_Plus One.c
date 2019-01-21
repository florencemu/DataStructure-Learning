int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	
	int i;
	int* ren = (int*)malloc((digitsSize + 1)*sizeof(int));
	for (i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i] < 9)       //判断进位
		{
			digits[i] = digits[i] + 1;
			break;
		}
		else                      //进位
		{
			digits[i] = 0;
		}
	}
	if (digits[0] == 0)    //增加数组长度
	{
		int j;
		for (j = i; j < digitsSize + 1; j++)
		{
			ren[j] = 0;
		}
		ren[0] = 1;
		*returnSize = digitsSize + 1;
		//finish = clock();
		//duration = (double)(finish - start) / CLOCKS_PER_SEC;
		//printf("%f \n", duration);
		return ren;
	}
	else                      //不增加数组长度
	{
		for (int i = 0; i < digitsSize; i++)  //拷贝
		{
			ren[i] = digits[i];
		}
		*returnSize = digitsSize;
		
		return ren;
	}
}

