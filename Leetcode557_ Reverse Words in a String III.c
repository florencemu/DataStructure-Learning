
/*解题思路 : 计算出空格的个数count , 然后用控制要反转单词顺序的次数 , 用 left 和 right 分别记录每次反转单词的开始和结尾*/


char* reverseWords(char* s) {
    int len=strlen(s);
    if(len<=1)
        return s;
    //count初始化为1,至少要反转一次
    int count=1;
    //计算空格个数
    for(int i=0;i<len;i++){
        if(s[i]==' ')
            count++;
    }
    int left=0;
    int right=0;
    int i=0;
    while(count--){
        //寻找空格的位置
        while(s[i]!=' '&&i<len)
            i++;
        right=i-1;
        i++;
        //反转单词
        while(left<right){
            char cur=s[left];
            s[left]=s[right];
            s[right]=cur;
            left++;
            right--;
        }
        left=i;
    }
    return s;
}

