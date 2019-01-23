int strStr(char* haystack, char* needle) {
    int len=strlen(haystack);
    int len2=strlen(needle);
    
    if((len==0&&len2==0)||len2==0){
        return 0;
    }
    
    int count=0;
    int i=0;
    while(i<=len-len2){
        if(haystack[i+count]==needle[count]){
            if(count==(len2-1)){
                 return i;
             }
            ++count;
        }else{
            count=0;
            i++;
        }
    }
    return -1;
   

}
