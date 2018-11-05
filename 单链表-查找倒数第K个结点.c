    //思路：
    //时间复杂度O(n)
	//用两个指针，先让前面的指针走到正向第k个结点，这样前后两个指针的距离差是k-1，之后前后两个指针一起向前走，前面的指针走到最后一个结点时，后面指针所指结点就是倒数第k个结点 
	// 查找单链表中倒数第K个结点  
    ListNode * RGetKthNode(ListNode * pHead, unsigned int k) // 函数名前面的R代表反向  
    {  
        if(k == 0 || pHead == NULL) // 这里k的计数是从1开始的，若k为0或链表为空返回NULL  
            return NULL;  
      
        ListNode * pAhead = pHead;  
        ListNode * pBehind = pHead;  
        while(k > 1 && pAhead != NULL) // 前面的指针先走到正向第k个结点  
        {  
            pAhead = pAhead->m_pNext;  
            k--;  
        }  
        if(k > 1 || pAhead == NULL)     // 结点个数小于k，返回NULL  
            return NULL;  
        while(pAhead->m_pNext != NULL)  // 前后两个指针一起向前走，直到前面的指针指向最后一个结点  
        {  
            pBehind = pBehind->m_pNext;  
            pAhead = pAhead->m_pNext;  
        }  
        return pBehind;  // 后面的指针所指结点就是倒数第k个结点  
    }  
