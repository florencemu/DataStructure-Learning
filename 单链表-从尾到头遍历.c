    // 从尾到头打印链表，使用栈  
    void RPrintList(ListNode * pHead)  
    {  
        std::stack<ListNode *> s;  
        ListNode * pNode = pHead;  
        while(pNode != NULL)  
        {  
            s.push(pNode);  
            pNode = pNode->m_pNext;  
        }  
        while(!s.empty())  
        {  
            pNode = s.top();  
            printf("%d\t", pNode->m_nKey);  
            s.pop();  
        }  
    }  
    
    
        // 从尾到头打印链表，使用递归  
    void RPrintList(ListNode * pHead)  
    {  
        if(pHead == NULL)  
        {  
            return;  
        }  
        else  
        {  
            RPrintList(pHead->m_pNext);  
            printf("%d\t", pHead->m_nKey);  
        }  
    }  
