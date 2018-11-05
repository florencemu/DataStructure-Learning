//判断单链表是否有环 
//设置两个指针(fast,slow)，初始值都指向头指针，slow每次前进一步，fast每次前进两步，如果链表存在环，则fast必定先进入环，而slow后进入环，两个指针必定相遇。（当然，fast先行从头到尾部为NULL，则为无环链表）

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int elem;
    struct node * next;
}Node, *NodeList;

bool IsExitsLoop(NodeList head){
    NodeList slow=head,fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }
    return !(fast==NULL || fast->next==NULL);
}

void main(){
    //创建一个有环的单链表
    NodeList head=NULL,p,q;
    for(int i=1;i<=5;i++){
        p=(NodeList)malloc(sizeof(Node));
        p->elem=i;
        if(head==NULL)
            head=q=p;
        else
            q->next=p;
        q=p;
    }
    p=(NodeList)malloc(sizeof(Node));
    p->elem=6;
    q->next=p;
    q=p;
    q->next=head->next->next->next;
    //判断单链表是否存在环
    printf("单链表是否存在环: ");
    bool b=IsExitsLoop(head);
    printf("%s\n",b==false?"false":"true");
}



//如果单链表有环，则找到环的入口点
//当fast若与slow相遇时，slow肯定没有遍历完链表，而fast已经在环内循环了n圈（1<=n），假设slow走了s步，而fast走了2s步（fast步数还等于s加上在环上多转的n圈），设环长为r，则：
//2s = s + n*r;　　
//s = n*r;
//设整个链表长为L，入口环与相遇点距离为x，起点到环入口点的距离为a。
//a + x = n*r;　　　　
//a + x = (n-1)*r + r = (n-1)*r + L -a;　　　　
//a = (n-1)r + (L – a – x);
//(L – a – x)为相遇点到环入口点的距离，由此可知，从链表头到环入口点等于(n-1)循环内环+相遇点到环入口点，于是我们从链表头、与相遇点分别设一个指针，每次各走一步，两个指针必定相遇，且相遇第一点为环入口点。

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int elem;
    struct node * next;
}Node, *NodeList;

//寻找环的入口点
NodeList FindLoopPort(NodeList head){
    NodeList slow=head,fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }
    if(fast==NULL||fast->next==NULL)
        return NULL;
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

void main(){
    //创建一个有环的单链表
    NodeList head=NULL,p,q;
    for(int i=1;i<=5;i++){
        p=(NodeList)malloc(sizeof(Node));
        p->elem=i;
        if(head==NULL)
            head=q=p;
        else
            q->next=p;
        q=p;
    }
    p=(NodeList)malloc(sizeof(Node));
    p->elem=6;
    q->next=p;
    q=p;
    q->next=head->next->next->next;
    //寻找环的入口点
    NodeList list=FindLoopPort(head);
    printf("环的入口节点元素值为：%d\n",list->elem);
}


//判断两个单链表是否相交，如果相交，给出相交的第一个点（两个链表都不存在环）
//思路：
//一、将其中一个链表首尾相连，检测另外一个链表是否存在环，如果存在，则两个链表相交，而检测出来的依赖环入口即为相交的第一个点。
//二、如果两个链表相交，那么两个链表从相交点到链表结束都是相同的节点，我们可以先遍历一个链表，直到尾部，再遍历另外一个链表，如果也可以走到同样的结尾点，则两个链表相交。这时我们记下两个链表length，再遍历一次，长链表节点先出发前进(lengthMax-lengthMin)步，之后两个链表同时前进，每次一步，相遇的第一点即为两个链表相交的第一个点。 
