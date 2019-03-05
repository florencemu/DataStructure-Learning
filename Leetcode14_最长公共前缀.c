/** 代码思路：既然是公共前缀子字符串，那必然每一组一维字符串都包含在其中，所以可以将第一组字符串整个赋给临时字符串变量temp，然后通过temp与其他几组一维字符串比较，每次比较都必须从第一个字符开始，如果遇到不同字符，本题比较结束，并且temp截短至不同字符出前一位置，直至temp与所有一维字符串变量比较结束，此时再返回temp;

*/

char* longestCommonPrefix(char** strs , int strsSize) {
    char* temp;         //创建一个临时字符指针变量temp
    int i, j;           
    
    if(strsSize <= 0)   //判断输入一维数组是否大于0，即是否存在这个二维字符串；
        return "";
    
    temp = strs[0];     //将第一组字符串变量直接赋给temp；
    for(i=1; i<strsSize; i++){ 
        
        j=0;            //每次都时从字符串第一个字符比较；
        
        while(temp[j] && strs[i][j] && temp[j]==strs[i][j])     //每组一位字符串与temp变量进行比较
            j ++;
        
        temp[j] = '\0'; //比较结束之后截短temp；
    }
    
    return temp;
}

