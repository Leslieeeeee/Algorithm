//基于顺序存储结构实现线性表的基本运算
/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <stdlib.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
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

typedef
struct{  //顺序表（顺序结构）的定义

    ElemType * elem;
    int length;
    int listsize;

}SqList;

/*-----page 19 on textbook ---------*/


status IntiaList(SqList *L){
    L->elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L->elem) exit(OVERFLOW);
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    return OK;
}

status DestroyList(SqList *L){

    if(L->elem) free(L->elem); //释放线性表的存储空间
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
    return OK;
}
status ClearList(SqList *L){

    L->length = 0;
    return OK;

}

status ListEmpty(SqList *L){

    if(L->length == 0)return TRUE;
    else return FALSE;

}

int ListLength(SqList *L){

    return(L->length);

}

status GetElem(SqList *L,int i,ElemType *e){

    if(i >= 0 || i <= L->length){

        *e = L->elem[i];
        return OK;
    }
    return FALSE;

}

status LocateElem(SqList *L,ElemType e){
    int i;
    for(i = 0;i < L->length; i++);
    if(e == L->elem[i]) printf("值为%d的元素，其位置为%d\n", e, i+1);
    return OK;

}

status PriorElem(SqList *L,ElemType *cur,ElemType *pre_e){

    for(int i = 1;i < L->length; i++)
        if(*cur == L->elem[i]){
            if(i == 1)return FALSE;
            *pre_e =L->elem[i+1];
        }
    return OK;
}

status NextElem(SqList *L,ElemType *cur,ElemType *next_e){

    for(int i = 1;i < L->length; i++)
        if(*cur == L->elem[i]){
            if(i == 1)return FALSE;
            *next_e = L->elem[i-1];
        }
    return OK;
}


status ListInsert(SqList *L,int i,ElemType e) {
    int l;
    if (i < 1 || i > L->length + 1) {
        printf("输入i值超过范围，请重新输入\n");
    }

    if (L->length >= L->listsize) {

        ElemType *newbase = (ElemType *) realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) {
            return ERROR;
        }
        L->elem = newbase;
        L->listsize += LISTINCREMENT;

        for (int l = L->length; l >= i; --l)
            L->elem[l + 1] = L->elem[l];
            L->elem[l] = e;
            ++L->length;

    }
    return OK;
}

status ListDelete(SqList *L, int i, ElemType *e){

    if (i < 1 || i > L->length) {
        printf("输入i值超过范围，请重新输入\n");
    }

    ElemType *q, *p;
    p = &(L->elem[i-1]);

    q = L->elem + L->length - 1;
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    --L->length;
    *q = e;
    return OK;

}
status ListTrabverse(SqList L){
    int i;
    printf("\n-----------all elements -----------------------\n");
    for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);
    printf("\n------------------ end ------------------------\n");
    return L.length;
}



/*--------------------------------------------*/
int main(void) {
    SqList L;
    int i;
    int op = 1;
    ElemType *e;
    ElemType *cur;
    ElemType *next_e;
    ElemType *pre_e;

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
        printf("    请选择你的操作[0~12]:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                IntiaList(&L);
                if (IntiaList(&L) == OK) printf("线性表创建成功！\n");
                else printf("线性表创建失败！\n");
                getchar();
                getchar();
                break;
            case 2:
                if (DestroyList(&L) == OK) printf("线性表删除成功！\n");
                else printf("线性表删除失败！\n");
                getchar();
                getchar();
                break;
            case 3:

                if (ClearList(&L) == OK) printf("线性表清空成功！\n");
                getchar();
                getchar();
                break;
            case 4:
                ListEmpty(&L);
                if (ListEmpty(&L) == OK) printf("线性表置零成功！\n");
                else printf("线性表置零失败！\n");
                getchar();
                getchar();
                break;
            case 5:

                if (ListLength(&L) == OK) printf("线性表的长度为:%d\n", ListLength(&L));
                else printf("线性表给出长度失败！\n");
                getchar();
                getchar();
                break;
            case 6:
                printf("请输入要查找的元素的序号：");
                scanf("%d", &i);

                if (GetElem(&L, i, &e) == OK) printf("线性表提取元素成功。\n");
                else printf("线性表提取元素失败！\n");
                getchar();
                getchar();
                break;
            case 7:
                printf("请输入要查找的元素：");
                scanf("%d", &e);
                LocateElem(&L,&e);
                if (LocateElem(&L, &e) == OK) printf("线性表返回元素位置成功！\n");
                else printf("线性表返回元素位置失败！\n");
                getchar();
                getchar();
                break;
            case 8:
                printf("请输入要查找的元素的值：");
                scanf("%d", &cur);
                PriorElem(&L,&cur,&pre_e);
                if (PriorElem(&L, &cur, &pre_e) == OK) printf("查找直接前驱成功！\n");
                else printf("查找直接前驱失败！\n");
                getchar();
                getchar();
                break;
            case 9:
                printf("请输入要查找的元素的序号：");
                scanf("%d", &cur);
                NextElem(&L, &cur, &next_e);
                if (NextElem(&L, &cur, &next_e) == OK) printf("查找直接后驱成功！\n");
                else printf("查找直接后驱失败！\n");
                getchar();
                getchar();
                break;
            case 10:
                printf("请输入要插入的值：");
                scanf("%d", &e);
                printf("请输入你要插入的位置:");
                scanf("%d", &i);
                ListInsert(&L, &i, &e);
                if (ListInsert(&L, &i, &e) == OK) printf("线性表插入成功！\n");
                else printf("线性表插入失败！\n");
                getchar();
                getchar();
                break;
            case 11:
                printf("请输入要删除元素的序号：");
                scanf("%d", &i);
                int e;
                ListDelete(&L, i, e);
                if (ListDelete(&L, i, e) == OK) printf("线性表删除元素成功！\n");
                else printf("线性表删除元素失败！\n");
                getchar();
                getchar();
                break;
            case 12:
                if (!ListTrabverse(L)) printf("线性表是空表！\n");
                getchar();
                getchar();
                break;
            case 0:
                break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}

//end of main()


