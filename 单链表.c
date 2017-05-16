//基于顺序存储结构实现线性表的基本运算
/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
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


status IntiaList(SqList & L){
	L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L.elem) exit(OVERFLOW);
	L.length=0;
    L.listsize=LIST_INIT_SIZE;
	return OK;
}

status DestroyList(SqList &L){

    if(L.elem)free(L.elem); //释放线性表的存储空间
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    return OK;
}
status ClearList(SqList &L){

    L.length = 0;
    return OK;

}

status ListEmpty(SqList L){

    if(L.length == 0)return TRUE;
    else return FALSE;

}

int ListLength(SqList L){

    return(L.length);

}

status GetElem(SqList L,int i,ElemType &e){

	if(i >= 0 || i <= L.length){

		e = L.elem[i];
		return e;
	}
	return FALSE;

}

status LocateElem(SqList L,ElemType e){

	for(int i = 1;i < L.length; i++)
		if(e == L.elem[i])return i;
		return FALSE;

}

status PriorElem(SqList L,ElemType cur,ElemType &pre_e){

	for(int i = 1;i < L.length; i++)
		if(cur == L.elem[i]){
			if(i == 1)return FALSE;
			pre_e = L.elem[i-1];
	}
	return pre_e;
}
status NextElem(SqList L,ElemType cur,ElemType &next_e){

	for(int i = 1;i < L.length; i++)
		if(cur == L.elem[i]){
			if(i == 1)return FALSE;
			next_e = L.elem[i+1];}

    return next_e;
}

status ListInsert(SqList &L,int i,ElemType e){
    int l;
	if (i<1||i>L.length+1){
		printf("输入i值超过范围，请重新输入\n");
	}

	if (L.length>=L.listsize){

		L.elem=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));

    	if(!L.elem){
    	printf("REALLOC FAIL\n");
    }

		L.listsize+=LISTINCREMENT;
	}

	for (int l=L.length; l>=i; --l)
		L.elem[l+1] = L.elem[l];
  		L.elem[l] = e;
  		++L.length;
        return TRUE;

}

status ListTrabverse(SqList L){
   int i;
   printf("\n-----------all elements -----------------------\n");
   for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);
   printf("\n------------------ end ------------------------\n");
   return L.length;
}


/*--------------------------------------------*/
void main(void){
  SqList L;
  int op=1;
  while(op){
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
	scanf("%d",&op);
    switch(op){
	   case 1:
		 //printf("\n----IntiaList功能待实现！\n");
		 if(IntiaList(L)==OK) printf("线性表创建成功！\n");
		     else printf("线性表创建失败！\n");
		 getchar();getchar();
		 break;
	   case 2:
		 if(DestroyList(L)==OK) printf("线性表删除成功！\n");
		     else printf("线性表删除失败！\n");
		 getchar();getchar();
		 break;
	   case 3:
		 if(ClearList(L)==OK) printf("线性表清空成功！\n");
		 getchar();getchar();
		 break;
	   case 4:
		 if(ListEmpty(L)==OK) printf("线性表删除成功！\n");
		     else printf("线性表删除失败！\n");
		 getchar();getchar();
		 break;
	   case 5:

		if(ListLength(L)==OK ) printf("线性表删除成功！\n");
		     else printf("线性表删除失败！\n");
		 getchar();getchar();
		 getchar();getchar();
		 break;
	   case 6:
	       int i;
	       ElemType e;
	       scanf("%d",&i)
		 if(GetElem(L,i,&e)==OK  || 1<=i || i<= ListLength(L)) printf("线性表删除成功！\n");
		     else printf("线性表删除失败！\n");
		 getchar();getchar(););
		 break;
	   case 7:
		 if(DestroyList(L)==OK) printf("线性表删除成功！\n");
		     else printf("线性表删除失败！\n");
		 getchar();getchar();
		 break;
	   case 8:
		 if(DestroyList(L)==OK) printf("线性表删除成功！\n");
		     else printf("线性表删除失败！\n");
		 getchar();getchar();
		 break;
	   case 9:
		if(DestroyList(L)==OK) printf("线性表删除成功！\n");
		     else printf("线性表删除失败！\n");
		 getchar();getchar();
		 break;
	   case 10:
		 if(DestroyList(L)==OK) printf("线性表删除成功！\n");
		     else printf("线性表删除失败！\n");
		 getchar();getchar();
		 break;
	   case 11:
		 if(ListDelete(L，i, e)==OK) printf("线性表删除成功！\n");
		     else printf("线性表删除失败！\n");
		 getchar();getchar();
		 break;
	   case 12:
		 //printf("\n----ListTrabverse功能待实现！\n");
		  if(!ListTrabverse(L)) printf("线性表是空表！\n");
		 getchar();getchar();
		 break;
	   case 0:
         break;
	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");
}//end of main()




