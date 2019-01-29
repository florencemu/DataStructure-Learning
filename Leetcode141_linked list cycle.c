/*快慢指针，快的一次走两步，慢的一次走一步，当相遇的时候， 返回TRUE

注意如果采用下面这种步进的方法，当判断fast==slow时候需要判断slow!=NULL ,否则出错
比如对于[1] no cycle, fast 走到NULL， slow也走到NULL，但是并没有环*/

bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;
    struct ListNode *fast, *slow;
    fast = slow = head;
    while (fast && slow) {
        fast = fast->next;
        if(fast){
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow ) return true;
    }

    return false;

}
