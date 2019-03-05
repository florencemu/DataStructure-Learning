
/*实际上，pa,pb的存在仿佛将两个链表连接到了一起，假若有交点，它们必定会相遇，因为实际上它们推进的根本就是同一条链表，就是那个虚拟链接在一起，长为m + n的链表。只是快慢交错 ，最坏情况下 ，它们在m+n个推进后相遇。*/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;
   struct ListNode *pa = headA, *pb = headB;
    while(true){
        if(pa == pb)
            return pa;
        if(pa->next == NULL && pb->next != NULL){
            pa = headB;
            pb = pb->next;
            continue;
        }
        if(pa->next != NULL && pb->next == NULL){
            pb = headA;
            pa = pa->next;
            continue;
        }
        if(pa->next == NULL && pb->next == NULL)
            return NULL;
        pa = pa->next;
        pb = pb->next;      
    }
    return NULL;     
}
