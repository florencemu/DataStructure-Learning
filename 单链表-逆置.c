#include<stdio.h>
 2 #include<stdlib.h>
 3 
 4 typedef struct node{
 5     int data;
 6     struct node *next;
 7 }Node;
 8 
 9 //创建链表
10 Node *CreateList(void){
11     int val,i,n;
12     Node *head,*p,*q;
13 
14     head=NULL;
15     printf("请输入您要建立的链表长度:\n");  
16     scanf("%d",&n);
17     printf("请输入您要输入的数据:\n");  
18     for(i=0;i<n;i++){
19         scanf("%d",&val);
20         p=(Node*)malloc(sizeof(Node));
21         p->data=val;
22         if(head==NULL)
23             head=q=p;
24         else
25             q->next=p;
26         q=p;
27     }
28     p->next=NULL;
29     return head;
30 }
31 
32 //链表的逆置
33 Node *ReverseList(Node *head){
34     Node *p,*q,*r;
35     p=head;
36     q=r=NULL;
37     while(p){
38         q=p->next;
39         p->next=r;
40         r=p;
41         p=q;
42     }
43     return r;
44 }
45 
46 //输出链表
47 void ShowList(Node *head){
48     Node *p;
49     p=head;
50     while(p){
51         printf("%d ",p->data);
52         p=p->next;
53     }
54     printf("\n");
55 }
56 
57 void main(){
58     Node *head;
59 
60     head=CreateList();
61     printf("链表逆置前的数据:\n");
62     ShowList(head);
63 
64     head=ReverseList(head);
65     printf("链表逆置后的数据:\n");  
66     ShowList(head);  
67 }
