//时间复杂度O(logn)
//另还有红黑树 二叉平衡树 B/B+树 哈希查找需了解 
#include<stdio.h>
//节点构造 
typedef int elemType;
typedef struct BTNode{
 
    int data;
    struct BTNode *lChild;
    struct BTNode *rChild;
}BiTNode,*BiTree;


//创建二叉查找树
/**
 *  输入-1时创建结束,其实是一个不断插入的过程
 */
int CreateBinarySearchTree(BiTree *T){
 
    printf("请输入创建二叉查找树的数字序列：\n");
 
    int num;
    scanf("%d",&num);
 
    while (num != -1) {
        Insert(T,num);
        scanf("%d",&num);
    }
 
    printf("%s函数执行，二叉查找树创建成功\n",__FUNCTION__);
    return 1;
}


//插入节点
void Insert(BiTree *T,int x){
 
    //这里创建一个要插入的节点
    BiTNode *pInsert = (BiTNode *)malloc(sizeof(BiTNode));
    pInsert->data = x;
    pInsert->lChild = NULL;
    pInsert->rChild = NULL;
 
    if ((*T) == NULL) {
        *T = pInsert;
    }
 
    if ((*T)->lChild == NULL && x < (*T)->data) {
        (*T)->lChild = pInsert;
    }
 
    if ((*T)->rChild == NULL && x > (*T)->data) {
        (*T)->rChild = pInsert;
    }
 
    //递归实现
    if (x < (*T)->data) {
        Insert(&(*T)->lChild, x);
    }
 
    if (x > (*T)->data) {
        Insert(&(*T)->rChild, x);
    }
 
    return;
}


//中序遍历二叉查找树
//打印的应该是一个递增的序列
void MiddleOrder(BiTree T){
    if (T == NULL) {
        return;
    }else{
 
        MiddleOrder(T->lChild);
        printf("%d ",T->data);
        MiddleOrder(T->rChild);
    }
}
//先序遍历二叉查找树
//因为先序遍历+中序遍历 可以唯一确定一棵树，等下可以验证树是否正确
void PreOrder(BiTree T){
 
    if (T == NULL) {
        return;
    }else{
 
        printf("%d ",T->data);
        PreOrder(T->lChild);
        PreOrder(T->rChild);
    }
}


//查找某一个值
//返回1表示找到该值，返回0表示没有找到
BiTNode *SearchValue(BiTree T,int x){
    if (T == NULL) {
        return 0;
    }else{
        if (x < T->data) {
            //查左子树
            SearchValue(T->lChild, x);
        }else if (x > T->data){
            //查右子树
            SearchValue(T->rChild, x);
        }else{
            //找到该值
            printf("该值的内存地址为：%p\n",T);
            return T;
        }
    }
 
    return NULL;
}


//删除某一个元素
BiTree *DeleteValue(BiTree *T,int x){
 
 
    //先要查找该节点，同时也要保存该节点的父节点
    BiTNode *searchNode;
    BiTNode *parentNode;
 
    //初始都指向根节点
    searchNode = *T;
    parentNode = *T;
 
    while (searchNode->data != x) {
 
        if (searchNode->lChild == NULL && searchNode->rChild == NULL) {
            //已经是叶子节点了，但是还没有找到该值，表示树种根本就没有要删除的节点
            printf("%s函数执行，不存在该值，删除失败\n",__FUNCTION__);
            return T;
        }
 
        if (x < searchNode->data) {
 
            parentNode = searchNode;
            searchNode = searchNode->lChild;
        }else if (x > searchNode->data){
 
            parentNode = searchNode;
            searchNode = searchNode->rChild;
        }else{
            break;
        }
    }
 
    if (searchNode->lChild == NULL && searchNode->rChild == NULL) {
        //是叶子节点
        if ((*T)->lChild == NULL && (*T)->rChild == NULL) {
            //是根节点
            free(*T);
            *T = NULL;
        }else{
            //不是根节点,是普通的叶子节点
            //需要判断要删除的节点是父节点的左孩子还是右孩子
            if (searchNode->data < parentNode->data) {
                //是左孩子
                parentNode->lChild = NULL;
            }else{
                //是右孩子
                parentNode->rChild = NULL;
            }
            free(searchNode);
            searchNode = NULL;
        }
 
        return T;
    }
 
    if (searchNode->lChild != NULL && searchNode->rChild == NULL) {
        //有左子树，没有右子树
        //直接把父节点的指针指向右子树即可，然后释放自己;
        //首先需要判断当前节点是父节点的左孩子还是右孩子
        if (searchNode->data < parentNode->data) {
            //是左孩子
            parentNode->lChild = searchNode->lChild;
        }else{
            //是右孩子
            parentNode->rChild = searchNode->lChild;
        }
 
        free(searchNode);
        searchNode = NULL;
 
        return T;
    }
 
    if (searchNode->lChild == NULL && searchNode->rChild != NULL) {
        //没有左子树，有右子树
        if (searchNode->data < parentNode->data) {
            //是左孩子
            parentNode->lChild = searchNode->rChild;
        }else{
            //是右孩子
            parentNode->rChild = searchNode->rChild;
        }
 
        free(searchNode);
        searchNode = NULL;
 
        return T;
    }
 
    if (searchNode->lChild != NULL && searchNode->rChild != NULL) {
        //要删除的节点既有左孩子，又有右孩子
        /**
         *  算法：删除节点p的左子树和右子树均不为空。找到p的后继y，因为y一定没有左子树，所以可以删除y，并让y的父节点成为y的右子树的父节点，并用y的值代替p的值；
          
         如何找到要删除节点的后继节点,包括该后继节点的父节点！！
         */
 
        BiTNode *nextNode;//寻找要删除节点的后继节点
        BiTNode *nextParentNode;//寻找要删除节点的后继节点的父节点
        nextParentNode = searchNode;
        nextNode = searchNode->rChild;
        while (nextNode->lChild != NULL) {
            nextParentNode = nextNode;
            nextNode = nextNode->lChild;
        }
 
        //这里要判断nextNode节点和nextParentNode节点的值大小，因为需要判断要删除节点是父亲的左孩子还是右孩子
        if (nextNode->data < nextParentNode->data) {
            //是左孩子
            nextParentNode->lChild = nextNode->rChild;
        }else{
            //是右孩子
            nextParentNode->rChild = nextNode->rChild;
        }
 
        //代替值
        searchNode->data = nextNode->data;
 
        //删除后继节点
        free(nextNode);
        nextNode = NULL;
 
        return T;
    }
 
    return T;
}


int main(int argc, const char * argv[]) {
 
    BiTree tree;
 
    //这个是引用传递
    CreateBinarySearchTree(&tree);
     
    MiddleOrder(tree);
    printf("\n");
 
    printf("请输入要查找的元素：");
    int searchValue;
    scanf("%d",&searchValue);
    SearchValue(tree,searchValue);
 
 
    printf("请输入要删除的元素：");
    int deleteValue;
    scanf("%d",&deleteValue);
    DeleteValue(&tree, deleteValue);
    printf("先序遍历：");
    PreOrder(tree);
    printf("\n中序遍历：");
    MiddleOrder(tree);//遍历检查
    printf("\n");
     
    return 0;
}
