
/*如果链表中存在环，那么fp和sp一定会相遇，当两个指针相遇的时候，我们设相遇点为c，此时fp和sp都指向了c，接下来令fp继续指向c结点，sp指向链表头结点head，此时最大的不同是fp的步数变成为每次走一步，令fp和sp同时走，每次一步，那么它们再次相遇的时候即为环的入口结点。*/
struct ListNode *detectCycle(struct ListNode *head) {
    bool cycle = false;
    int counter;
    struct ListNode *start = NULL;
    if(head == NULL)
    {
        return start;
    }
    struct ListNode *p1,*p2;
    p1 = p2 = head;
    while(p2->next != NULL && p2->next->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
        if(p1 == p2)
        {
            cycle = true;
            p2 = head;
            while(p1 != p2)
            {
                p1 = p1->next;
                p2 = p2->next;                    
            }
            start = p1;//二次相遇即环入口
            break;
        }
    }      
    return cycle ? start : NULL;


}
