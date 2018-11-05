/*约瑟夫环*/
/*约瑟夫环算法是： n 个人围成一圈，每个人都有一个互不相同的密码，该密码是一个整数值，选择一个人作为起点，然后顺时针从 1 到 k（k为起点人手中的密码值）数数。数到 k 的人退出圈子，然后从下一个人开始继续从 1 到 j （j为刚退出圈子的人的密码）数数，数到 j 的人退出圈子。重复上面的过程，直到剩下最后一个人。
*/
#include <stdio.h>
#include <stdlib.h>
 
#define N 9  //环中人的个数
#define OVERFLOW 0
int KeyW[N]={4,7,5,9,3,2,6,1,8};  //每个人手中的密码
 
typedef struct LNode{  //定义循环链表
    int keyword;
    struct LNode * next;
}LNode,*LinkList;
 
void Joseph(LinkList p,int m,int x){  //x为总人数，m为删除的那个人手中的密码，起始的m为第一个人手中的密码
    LinkList q;
    int i;
    if(x==0)return;
    q=p;
    m%=x;
    if(m==0)m=x;
    for(i=1;i<=m;++i){  //找到第m个人  p指向要删除的人的前一人 q指向要删除的人
        p=q;
        q=p->next;
    }
    p->next=q->next;  //删除q
    i=q->keyword;  //得到下一个要删除的人的位置
    printf("%d ",q->keyword);
    free(q);
    Joseph(p,i,x-1);  //递归调用 总人数减1，输入新的密码
}
 
int main()
{
    int i,m;
    LinkList Lhead,p,q;  //Lhead指向头，p指向尾指针，q指向新建指针
    Lhead=(LinkList)malloc(sizeof(LNode));
    if(!Lhead)return OVERFLOW;
    Lhead->keyword=KeyW[0];
    Lhead->next=NULL;
    p=Lhead;
    for(i=1;i<9;++i){
        if(!(q=(LinkList)malloc(sizeof(LNode)))) return OVERFLOW;
        q->keyword=KeyW[i];  //对q的keyword进行赋值
        p->next=q;  //将q赋给p的next
        p=q;  //p要指向尾部，将q赋给p
    }
    p->next=Lhead;  //构造循环链表
    printf("请输入第一次计数值m :\n");
    scanf("%d",&m);
    printf("输出的队列是：\n");
    Joseph(p,m,N);
    return 0;
}
