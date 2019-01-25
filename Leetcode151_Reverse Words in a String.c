/*主要是空格的问题：前导空格，后置空格，以及中间多余的空格。不能够用额外的空间，所以我们只能在原字符串上做修改，而不能另申请
解题思路：先翻转单词，再整体翻转，最后遍历的过程中，将多余的空格删除
核心解决问题：

最后遍历已经逆转好的字符串时，如何去除多余空格：
	前导空格和中间多余空格通过：
	如果当前字符是空格，且之前已经加入一个空格，则这个空格跳过
	s[i] !=' ' || (last && s[last-1]!=s[i])
	s[last++] = s[i];

	后置空格通过：
	s[last] = 0;
	if(last &&s[last-1]==' ') //如果上一步引入了空格（因为满足上面判断的后半部分）
	s[last-1] = 0;

*/



void reverse(char *s, int start, int end) { 
    while (start < end) { 
        char tmp = s[start]; 
        s[start++] = s[end]; 
        s[end--] = tmp; 
    } 
} 

void reverseWords(char *s) { 
    int last = 0, now = 0; 
    while (s[now]) {
        while (s[now] == ' ') now++; 
        last = now; 
        while (s[now] != ' '&&s[now] != '\0') 
            now++; 
        reverse(s, last, now-1); } 
    reverse(s, 0, now - 1); 
    last = 0; //遍历删除多余空格 
    for (int i = 0; i < now; i++) { 
        //前导空格直接跳过 || 如果已经有一个合法空格加入字符串中，则当前相同的字符跳过 
        if (s[i] != ' ' || (last &&s[last-1] != s[i])) { s[last++] = s[i]; } } 
    //删除后面的空格 
    s[last] = 0; 
    if (last&&s[last - 1] == ' ') 
        s[last - 1] = 0; 
}
