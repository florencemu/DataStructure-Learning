    //思路： 
	//设置两个指针，只不过这里是，两个指针同时向前走，前面的指针每次走两步，后面的指针每次走一步，前面的指针走到最后一个结点时，后面的指针所指结点就是中间结点，即第（n/2+1）个结点。注意链表为空，链表结点个数为1和2的情况。时间复杂度O（n） 
	//获取单链表中间结点，若链表长度为n(n>0)，则返回第n/2+1个结点  
    ListNode * GetMiddleNode(ListNode * pHead)  
    {  
        if(pHead == NULL || pHead->m_pNext == NULL) // 链表为空或只有一个结点，返回头指针  
            return pHead;  
      
        ListNode * pAhead = pHead;  
        ListNode * pBehind = pHead;  
        while(pAhead->m_pNext != NULL) // 前面指针每次走两步，直到指向最后一个结点，后面指针每次走一步  
        {  
            pAhead = pAhead->m_pNext;  
            pBehind = pBehind->m_pNext;  
            if(pAhead->m_pNext != NULL)  
                pAhead = pAhead->m_pNext;  
        }  
        return pBehind; // 后面的指针所指结点即为中间结点  
    }  
