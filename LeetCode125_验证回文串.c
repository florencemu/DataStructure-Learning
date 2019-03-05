bool isPalindrome(char* s) 
{
    int n=strlen(s);
    if(n==0)
    {
        return true;
    }
    char* res=(char*)malloc(sizeof(int)*(n+1));
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0' && s[i]<='9' || s[i]>='a' && s[i]<='z')
        {
            res[k++]=s[i];
        }
        if(s[i]>='A' && s[i]<='Z')
        {
            res[k++]=(s[i]+32);
        }   
    }
    res[k]='\0';
    for(int i=0;i<k;i++)
    {
        if(res[i]!=res[k-1-i])
        {
            return false;
        }
    }
    return true;
}

