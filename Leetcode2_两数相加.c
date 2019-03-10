struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
        struct ListNode *p;
        struct ListNode *q;
        struct ListNode *head;
        struct ListNode *now;    
        p=l1;
        q=l2;
        int x,y,sum;
        int flag=0;
        head=( struct ListNode *)malloc(sizeof(struct ListNode ));
        now=head;
        while(p!=NULL||q!=NULL)
        {
            x=(p!=NULL)?p->val:0;
            y=(q!=NULL)?q->val:0;
            sum=flag+x+y;
            flag=sum/10;//判断进位
            if(p!=NULL)p=p->next;
            if(q!=NULL)q=q->next;
            now->next=(struct ListNode *)malloc(sizeof(struct ListNode));
            now->next->val=(sum%10);
            now=now->next;

        }
        if(flag>0)
        {
            now->next=(struct ListNode *)malloc(sizeof(struct ListNode));
            now->next->val=flag; 
            now=now->next;
            
        }
        now->next=NULL;
        return head->next;
}
