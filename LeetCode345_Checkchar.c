bool checkchar(char c) {
    return c == 'a' | c == 'e' | c == 'i' | c == 'o' | c == 'u' | c == 'A' | c == 'E' | c == 'I' | c == 'O' | c == 'U'; 
} 

char* reverseVowels(char* s) { 
    int len = strlen(s); 
    int i = 0,j = len -1; 
    while(i < j) { 
        while(i < j && !checkchar(s[i]))//找到左边的元音字母 
        { i++; } 
        while(i < j && !checkchar(s[j]))//找到右边的元音字母 
        { j--; } 
        if(i < j) 
        { char tmp = s[i];//交换左右元音字母 
         s[i] = s[j]; 
         s[j] = tmp;
         i++;
         j--; 
        } 
    } 
    return s; 
} 

