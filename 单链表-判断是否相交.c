//判断两个单链表是否相交，如果相交，给出相交的第一个点（两个链表都不存在环）
//思路：
//一、将其中一个链表首尾相连，检测另外一个链表是否存在环，如果存在，则两个链表相交，而检测出来的依赖环入口即为相交的第一个点。
//二、如果两个链表相交，那么两个链表从相交点到链表结束都是相同的节点，我们可以先遍历一个链表，直到尾部，再遍历另外一个链表，如果也可以走到同样的结尾点，则两个链表相交。这时我们记下两个链表length，再遍历一次，长链表节点先出发前进(lengthMax-lengthMin)步，之后两个链表同时前进，每次一步，相遇的第一点即为两个链表相交的第一个点。 
    ListNode* GetFirstCommonNode(ListNode * pHead1, ListNode * pHead2)  
    {  
        if(pHead1 == NULL || pHead2 == NULL)  
            return NULL;  
      
        int len1 = 1;  
        ListNode * pTail1 = pHead1;  
        while(pTail1->m_pNext != NULL)  
        {  
            pTail1 = pTail1->m_pNext;  
            len1++;  
        }  
      
        int len2 = 1;  
        ListNode * pTail2 = pHead2;  
        while(pTail2->m_pNext != NULL)  
        {  
            pTail2 = pTail2->m_pNext;  
            len2++;  
        }  
      
        if(pTail1 != pTail2) // 不相交直接返回NULL  
            return NULL;  
      
        ListNode * pNode1 = pHead1;  
        ListNode * pNode2 = pHead2;  
            // 先对齐两个链表的当前结点，使之到尾节点的距离相等  
        if(len1 > len2)  
        {  
            int k = len1 - len2;  
            while(k--)  
                pNode1 = pNode1->m_pNext;  
        }  
        else  
        {  
            int k = len2 - len1;  
            while(k--)  
                pNode2 = pNode2->m_pNext;  
        }  
        while(pNode1 != pNode2)  
        {  
            pNode1 = pNode1->m_pNext;  
            pNode2 = pNode2->m_pNext;  
        }  
            return pNode1;  
    }  
