/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) { 
    if(!head) 
        return NULL; 
    struct ListNode* curTemp = head;/*当前要处理的节点*/ 
    struct ListNode* nextTemp = head->next; /*1.处理头结点以外的结点*/ 
    while(nextTemp) {
        if(val == nextTemp->val) { 
            curTemp->next = nextTemp->next; 
            free(nextTemp); 
            nextTemp = curTemp->next; 
            continue; 
        } 
        nextTemp = nextTemp->next; 
        curTemp = curTemp->next; 
    } 
    /*2.处理头结点*/ 
    if(head->val == val) 
    { 
        curTemp = head; 
        head = head->next; 
        free(curTemp); 
    } 
    return head; 
} 
