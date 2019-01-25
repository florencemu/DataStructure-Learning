int strStr(char* haystack, char* needle) {
    int len=strlen(haystack);//原串
    int len2=strlen(needle);//子串
    
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
            ++count;//比较原串子串下一位
        }else{
            count=0;
            i++;//比较原串下一位
        }
    }
    return -1;
   

}
