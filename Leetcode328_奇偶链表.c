struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newList1;
    struct ListNode* newList2;
    struct ListNode* point1;
    struct ListNode* point2;
    point1 = head;
    point2 = head->next;
    newList1 = point1;
    newList2 = point2;
    int count = 2;
    head = head->next;
    while (head->next) {
        head = head->next;
        count++;
	//判断奇偶节点
        if (count % 2 != 0) {
            point1->next = head;
            point1 = point1->next;
        } else {
            point2->next = head;
            point2 = point2->next;
        }
    }
	 //链接子链表
    if (count > 2) {
        point2->next = NULL;
        point1->next = newList2;
    }
    return newList1;    
}
