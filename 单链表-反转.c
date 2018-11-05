    // 反转单链表
	//从头到尾遍历原链表，每遍历一个结点，将其摘下放在新链表的最前端。注意链表为空和只有一个结点的情况。时间复杂度为O（n）  
    ListNode * ReverseList(ListNode * pHead)  
    {  
            // 如果链表为空或只有一个结点，无需反转，直接返回原链表头指针  
        if(pHead == NULL || pHead->m_pNext == NULL)    
            return pHead;  
      
        ListNode * pReversedHead = NULL; // 反转后的新链表头指针，初始为NULL  
        ListNode * pCurrent = pHead;  
        while(pCurrent != NULL)  
        {  
            ListNode * pTemp = pCurrent;  
            pCurrent = pCurrent->m_pNext;  
            pTemp->m_pNext = pReversedHead; // 将当前结点摘下，插入新链表的最前端  
            pReversedHead = pTemp;  
        }  
        return pReversedHead;  
    }  
