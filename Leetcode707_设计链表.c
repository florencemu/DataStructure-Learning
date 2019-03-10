

struct MyListNode{
    int val;
    struct MyListNode* next;
};

typedef struct MyListNode MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj;
    obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->val = 0;
    obj->next = NULL;
    return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    MyLinkedList* cur = obj->next;
    for(i = 0; i < index && cur != NULL; i++){
        cur = cur->next;
    }
    if(i == index && cur != NULL){
        return cur->val;
    }else{
        return -1;
    }
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *temp;
    temp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    temp->val = val;
    temp->next = obj->next;
    obj->next = temp;
    obj->val++;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* cur = obj;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    cur->next->val = val;
    cur->next->next = NULL;
    obj->val++;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0 || index > obj->val){
        return ;
    }
    int i = 0;
    MyLinkedList *cur = obj, *temp;
    for(i = 0; i < index; i++){
        cur = cur->next;
    }
    
    temp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    temp->val = val;
    temp->next = cur->next;
    cur->next = temp;
    obj->val++;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index > obj->val - 1){
        return ;
    }
    int i = 0;
    MyLinkedList* cur = obj, *temp;
    for(i = 0; i < index; i++){
        cur = cur->next;
    }
    
    temp = cur->next;
    cur->next = cur->next->next;
    // free(temp);
    obj->val--;
        
}

void myLinkedListFree(MyLinkedList* obj) {
    // MyLinkedList *cur = obj->next, *temp;
    // while(cur){
    //     temp = cur->next;
    //     free(cur);
    //     cur = temp;
    // }
    // free(obj);
}


