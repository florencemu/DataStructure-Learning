typedef struct {
    int val;
    struct MyLinkedList* next;
} MyLinkedList;

/*为头节点申请空间*/
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->next = NULL;
    
    return head;
}

/*获取链表中第 index 个节点的值。如果索引无效，则返回-1*/
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *p = obj;
    int i = 0;  
    while(i <= index && p != NULL) {
        p = p->next;
        i++;
    }
    
    return i - 1 == index && p != NULL ? p->val : -1;
}

/*在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点*/
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *p = obj->next;
    
    MyLinkedList *newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newNode->val = val;
    newNode->next = p;
    
    obj->next = newNode;
}

/* 将值为 val 的节点追加到链表的最后一个元素。*/
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {  b
    MyLinkedList *last = obj;
    while(last->next != NULL) last = last->next;/*一直遍历到最后一个节点*/
    
    MyLinkedList *newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newNode->val = val;
    newNode->next = NULL;
    
    last->next = newNode;
}

/*在链表中的第 index 个节点之前添加值为 val  的节点。*/
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

    // 如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点
    if(index < 0){
        return;
    }

    // 找到位置i的前缀
    MyLinkedList *p = obj;
    int i;
    for(i = 0;i < index  && p != NULL;i++) p = p->next;
    
    // index超过链表的长度
    if(p == NULL) {
        return;
    }
    
    // 创建新节点
    MyLinkedList *newNode = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newNode->val = val;
    
    // 设置链表关系
    newNode->next = p->next;
    p->next = newNode;
}

/*如果索引 index 有效，则删除链表中的第 index 个节点*/
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    
    if(index < 0){
        return;
    }

    // 找到位置i的前缀
    MyLinkedList *p = obj;
    int i;
    for(i = 0;i < index && p->next != NULL;i++) p = p->next;
    
    // index超过链表的长度
    if(p->next == NULL) {
        return;
    }
    
    // 删除节点
    // 要删除的节点(位置i的节点)
    MyLinkedList *s = p->next;
    
    // 修改链表关系
    p->next = s->next;
    
    // 释放删除节点的空间
    free(s);
}

void myLinkedListFree(MyLinkedList* obj) {
    // 删除链表
    MyLinkedList *cur = obj->next, *front = NULL;
    
    while(cur != NULL) {
        front = cur;
        cur = cur->next;
        free(front);
    }
}


