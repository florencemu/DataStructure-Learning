    //注意检查链表是否为空
	// 求单链表中结点的个数  
    unsigned int GetListLength(ListNode * pHead)  
    {  
        if(pHead == NULL)  
            return 0;  
      
        unsigned int nLength = 0;  
        ListNode * pCurrent = pHead;  
        while(pCurrent != NULL)  
        {  
            nLength++;  
            pCurrent = pCurrent->m_pNext;  
        }  
        return nLength;  
    }  
