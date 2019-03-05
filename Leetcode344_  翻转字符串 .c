void reverseString(char* s, int sSize) {
    int i=0;
    int j=sSize-1;
    char temp;
     if (s == NULL)
        return NULL;
    for(i,j;i<j;i++,j--){
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }

    return s;
    
}
