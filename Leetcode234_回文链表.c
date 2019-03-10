 bool isPalindrome(struct ListNode* head) {
    struct ListNode *fast = head, *slow = head, *temp = NULL;
    while (fast) {//快慢指针找到链表中点
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
    }
//头插法逆置后半锻链表
    while (slow) {
        fast = slow->next;
        slow->next = temp;
        temp = slow;
        slow = fast;
    }
    fast = head;
    slow = temp;

    while (fast && slow) {
        if (fast->val != slow->val)
            return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}
