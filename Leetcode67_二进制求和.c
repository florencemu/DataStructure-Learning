char* addBinary(char* a, char* b)

{
    int i, tempa,tempb,carry = 0;
    int lena = strlen(a);
    int lenb = strlen(b);
    int maxlen = lena>=lenb?lena:lenb;
    char *value = (char *)calloc(maxlen+2, 1);

    i = maxlen-1;
    while(lena>0 || lenb>0)
    {
        tempa = (lena--)>0?a[lena]-'0':0;
        tempb = (lenb--)>0?b[lenb]-'0':0;
        value[i--] = ((tempa^tempb)^carry) + '0';//当两个值相等时，有进位，则当前值为1，两个值不等时，有进位，当前位则为0
        carry = (tempa&tempb)|((tempa^tempb)&carry);//判断是否需要进位
    }

    if (carry == 1)//计算结束后仍有进位则需要将所有结果后移一位，然后在第一个字节补1
    {
        for (i=maxlen+1; i>0; i--)
        {
            value[i] = value[i-1];
        }
        value[0] = '1';
    }
    return value;
}

