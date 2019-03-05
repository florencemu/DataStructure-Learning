struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* p=head;      
    struct ListNode* New=NULL;   //定义一个新链头
 
    if(head==NULL||head->next==NULL)
    {
        return head;            //如果只有一个结点或者为空，则返回head
    }
   while(p!=NULL)               //一直迭代到链尾
    {
     struct ListNode*temp;      //定义一个临时存放批p->next后后面的值得指针变量
        temp=p->next;           //temp存放p->next的地址
        p->next=New;            //将p指向New
        New=p;                  
        p=temp;
    }
    return New;
}
