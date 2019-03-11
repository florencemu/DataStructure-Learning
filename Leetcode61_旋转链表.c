struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || k == 0) {
        return head;
    }

    int len = 0, f, i = 0;
    struct ListNode * first = head, *pre, *sec;
    while (first) {
        len++;
        first = first->next;
    }

    f = k % len;

    if (f == 0)
        return head;
    first = head;

    while (len - i > f) {
        pre = first;
        first = first->next;

        i++;
    }

    sec = first;

    while (sec->next) {
        sec = sec->next;
    }
    sec->next = head;
    pre->next = NULL;

    return first;
}
