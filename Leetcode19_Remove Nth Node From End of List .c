/*我们让快指针先走n步，再让fast and slow并驾齐驱，那么slow和fast的距离始终是n, 当fast走到尾节点的时候，slow和尾节点的距离是n，那么就是它了*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(!head)
        return NULL;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* tmp = NULL;
    while(n--)
        fast = fast->next;
    if(!fast){
        tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }//返回头节点
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    tmp = slow->next;
    slow->next = slow->next->next;
    free(tmp);
    return head;
}
