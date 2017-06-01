//基于链式存储结构实现线性表的基本运算
/* Linear Table On LinkList Structure */
#include <stdio.h>
#include <stdlib.h>


/*---------page 10 on textbook ---------*/
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //数据元素类型定义

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define LENG sizeof(struct Node)

typedef
struct Node{
    
    ElemType data;    //数据域
    struct Node *next;     //指针域(下一个指针）
    
}LinkList;

/*-------------具体函数实现---------------*/

//构建一个链表
status IntiaList() {
    
    LinkList *head;
    head = (LinkList *) malloc(LENG);//生成表头结点
    if (head == NULL) {
        printf("创建失败！\n");
        return FALSE;
    }
    head->next = NULL;  //头节点指针域置NULL
    return OK;
}


//销毁链表
status DestroyList(LinkList *head){
    
    LinkList *p, *q;
    p=head;
    while (p->next!=NULL) {
        q = p->next;  //q指向p的指针域
        p->next = q->next;
        free(q);
    }
    free(p);
    return OK;
}

//清空链表
status ClearList(LinkList *head){
    
    head = head->next;
    free(head);
    return OK;
}

//判断链表是否为空
status ListEmpty(LinkList *head){
    
    if(head == NULL)
        return OK;
    else
        return FALSE;
    
}

//给出链表长度
int ListLength(LinkList *head) {
    
    int i = 0;
    if (head == NULL)
        return printf("链表为空!\n");
    while (head != NULL) {
        i++;
        head = head->next;
    }
    printf("链表的长度为%d:\n", i);
    return OK;
}


//获取链表某节点的数据
status GetElem(LinkList *head, ElemType *e){
    int i=0;
    if(*e<1)
    {
        printf("输入节点值非法,请重新输入(节点值应>=1)");
        return FALSE;
    }
    if(head==NULL)
    {
        printf("链表为空！\n");
    }
    
    while (head!=NULL)
    {
        ++i;
        if(i==*e)
        {
            break;
        }
        head=head->next;
    }
    
    printf("getElement函数执行，位置%d中的元素为%d\n",*e,head->data);
    
    return OK;
}


//找到链表中元素的位置
status LocateElem(LinkList *head, ElemType *e){
    int i=0;
    if(head==NULL)
    {
        printf("链表为空！\n");
    }
    
    while (head!=NULL)
    {
        ++i;
        if(*e==head->data)
            return printf("元素%d的第一个匹配位置为%d\n",head->data,i);
        head=head->next;
        if(i >  ListLength(head)){
            printf("没有找到匹配的位置。\n");
            return FALSE;
        }
    }
    
    return OK;
}


//提取链表元素的直接前驱
status PriorElem(LinkList *head,ElemType *e){
    int i=0;
    if(head==NULL)
    {
        printf("链表为空！\n");
    }
    
    while (head!=NULL)
    {
        ++i;
        if(*e==head->next->data)
        {
            if(i==1){
                printf("元素无直接前驱。\n");
            }
            
            printf("元素%d的直接前驱为%d\n",*e, head->data);
            return OK;
        }
        
        head=head->next;
        if(i >  ListLength(head)){
            printf("没有找到匹配的位置！\n");
            return FALSE;
        }
    }
    
    return OK;
}

//提取链表的直接后驱
status NextElem(LinkList *head,ElemType *e){
    
    int i=0;
    if(head==NULL)
    {
        printf("链表为空！");
    }
    
    while (head!=NULL)
    {
        ++i;
        if(*e==head->data)
        {
            head = head->next;
            printf("元素%d的直接前驱为%d\n",*e, head->data);
            return OK;
        }
        
        head=head->next;
        if(i >  ListLength(head)){
            printf("没有找到匹配的位置.\n");
            return FALSE;
        }
        if(i ==  ListLength(head)){
            printf("该元素没有直接后驱.\n");
            return FALSE;
        }
    }
    
    return OK;
}

//插入元素
status ListInsert(LinkList *head,int i,ElemType *e) {
    
    LinkList *p;
    int j=0;
    while (head&&j<i-1) {
        head = head->next;
        ++j;
    }
    p = (LinkList *) malloc(sizeof(LENG));
    p->data=*e;
    p->next=head->next;
    head->next=p;
    printf("成功插入数值%d\n", *e);
    return OK;
    
}


//删除某一结点
status ListDelete(LinkList *head, ElemType *e) {
    
    LinkList *p,*q;
    p=head;
    while(p->next && p->next->data!=*e)
        p=p->next;
    if(p->next) {
        q = p->next;
        p->next = q->next;
        free(q);
        printf("删除数值%d!!\n", *e);
    }
    return OK;
}


//打印全部链表元素
status ListTrabverse(LinkList *head){
    
    int i=0;
    if(head==NULL)
    {
        printf("链表为空！\n");
    }
    
    while (head!=NULL)
    {
        ++i;
        head=head->next;
        printf("位置%d中的元素为%d\n",i,head->data);
    }
    
    return OK;
}



/*--------------------------------------------*/
int main(void) {
    
    LinkList *head;
    int i;
    int op = 1;
    ElemType *e;
    
    while (op) {
        system("cls");
        printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. IntiaList       7. LocateElem\n");
        printf("    	  2. DestroyList     8. PriorElem\n");
        printf("    	  3. ClearList       9. NextElem \n");
        printf("    	  4. ListEmpty     10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem       12. ListTrabverse\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~12]:\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                IntiaList();
                if (IntiaList() == OK) printf("链表创建成功！\n");
                else printf("链表创建失败！\n");
                getchar();
                getchar();
                break;
            case 2:
                if (DestroyList(head) == OK) printf("链表删除成功！\n");
                else printf("链表删除失败！\n");
                getchar();
                getchar();
                break;
            case 3:
                
                if (ClearList(head) == OK) printf("链表清空成功！\n");
                getchar();
                getchar();
                break;
            case 4:
                ListEmpty(head);
                if (ListEmpty(head) == OK) printf("链表是空表！\n");
                getchar();
                getchar();
                break;
            case 5:
                
                if (ListLength(head) == OK)
                    printf("链表的长度如上！\n");
                else printf("链表给出长度失败！\n");
                getchar();
                getchar();
                break;
            case 6:
                printf("请输入要查找的元素的序号：\n");
                scanf("%d", e);
                ListLength(head);
                if (GetElem(head, e) == OK) printf("链表元素如上。\n");
                else printf("链表查找元素失败！\n");
                getchar();
                getchar();
                break;
            case 7:
                printf("请输入要查找的元素：\n");
                scanf("%d", e);
                ListLength(head);
                LocateElem(head,e);
                if (LocateElem(head, e) == OK) printf("链表返回元素位置成功！\n");
                else printf("链表返回元素位置失败！\n");
                getchar();
                getchar();
                break;
            case 8:
                printf("请输入要查找的元素的值：\n");
                scanf("%d", e);
                ListLength(head);
                PriorElem(head,e);
                if (PriorElem(head, e) == OK) printf("查找直接前驱成功！\n");
                else printf("查找直接前驱失败！\n");
                getchar();
                getchar();
                break;
            case 9:
                printf("请输入要查找的元素的序号：");
                scanf("%d", e);
                ListLength(head);
                NextElem(head, e);
                if (NextElem(head, e) == OK) printf("查找直接后驱成功！\n");
                else printf("查找直接后驱失败！\n");
                getchar();
                getchar();
                break;
            case 10:
                printf("请输入要插入的值：");
                scanf("%d", e);
                printf("请输入你要插入的位置:");
                scanf("%d", &i);
                ListInsert(head, i, e);
                if (ListInsert(head, i, e) == OK) printf("线性表插入成功！\n");
                else printf("线性表插入失败！\n");
                getchar();
                getchar();
                break;
            case 11:
                printf("请输入要删除元素的序号：\n");
                scanf("%d", e);
                ListDelete(head,e);
                if (ListDelete(head,e) == OK) printf("线性表删除元素成功！\n");
                else printf("线性表删除元素失败！\n");
                getchar();
                getchar();
                break;
            case 12:
                if (!ListTrabverse(head)) printf("线性表是空表！\n");
                getchar();
                getchar();
                break;
            case 0:
                break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}//end of main()




