    // 合并两个有序链表  
    ListNode * MergeSortedList(ListNode * pHead1, ListNode * pHead2)  
    {  
        if(pHead1 == NULL)  
            return pHead2;  
        if(pHead2 == NULL)  
            return pHead1;  
        ListNode * pHeadMerged = NULL;  
        if(pHead1->m_nKey < pHead2->m_nKey)  
        {  
            pHeadMerged = pHead1;  
            pHeadMerged->m_pNext = NULL;  
            pHead1 = pHead1->m_pNext;  
        }  
        else  
        {  
            pHeadMerged = pHead2;  
            pHeadMerged->m_pNext = NULL;  
            pHead2 = pHead2->m_pNext;  
        }  
        ListNode * pTemp = pHeadMerged;  
        while(pHead1 != NULL && pHead2 != NULL)  
        {  
            if(pHead1->m_nKey < pHead2->m_nKey)  
            {  
                pTemp->m_pNext = pHead1;  
                pHead1 = pHead1->m_pNext;  
                pTemp = pTemp->m_pNext;  
                pTemp->m_pNext = NULL;  
            }  
            else  
            {  
                pTemp->m_pNext = pHead2;  
                pHead2 = pHead2->m_pNext;  
                pTemp = pTemp->m_pNext;  
                pTemp->m_pNext = NULL;  
            }  
        }  
        if(pHead1 != NULL)  
            pTemp->m_pNext = pHead1;  
        else if(pHead2 != NULL)  
            pTemp->m_pNext = pHead2;  
        return pHeadMerged;  
    }  
    
    //递归实现
	    ListNode * MergeSortedList(ListNode * pHead1, ListNode * pHead2)  
    {  
        if(pHead1 == NULL)  
            return pHead2;  
        if(pHead2 == NULL)  
            return pHead1;  
        ListNode * pHeadMerged = NULL;  
        if(pHead1->m_nKey < pHead2->m_nKey)  
        {  
            pHeadMerged = pHead1;  
            pHeadMerged->m_pNext = MergeSortedList(pHead1->m_pNext, pHead2);  
        }  
        else  
        {  
            pHeadMerged = pHead2;  
            pHeadMerged->m_pNext = MergeSortedList(pHead1, pHead2->m_pNext);  
        }  
        return pHeadMerged;  
    }   
