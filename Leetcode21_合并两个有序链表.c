struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1, *p2 = l2, *head = NULL, *p = NULL;
    
    /* 确定新链表头 */
    if(p1 != NULL && p2 != NULL){
        if(p1->val < p2->val){
            head = p1;
            p1 = p1->next;
        }else{
            head = p2;
            p2 = p2->next;
        }
    }else if(p1 != NULL){
        return p1;
    }else{
        return p2;
    }
    
    /* 拼接小值结点*/
    p = head;
    while(p1 != NULL && p2 != NULL){
        if(p1->val < p2->val){
            p = p->next = p1;
            p1 = p1->next;
        }else{
            p = p->next = p2;
            p2 = p2->next;
        }
    }
    if(p1 != NULL){
        p->next = p1;
    }else if(p2 != NULL){
        p->next = p2;
    }
    return head;
}
