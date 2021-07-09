#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int coef; //系数
    int expn; //指数
} term,ElemType; //term表示多项式项，ElemType表示链表数据域

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode,*LinkList;

int main()
{
    LinkList polynomial = (LinkList)malloc(sizeof(LNode));
    polynomial->next = NULL;

    LinkList tail = polynomial;

    int coef,expn;
    while(scanf("%d%d",&coef,&expn)!=EOF)
    {
        if(expn!=0) //指数不等于0
        {
            LNode *p = (LNode*)malloc(sizeof(LNode));
            p->data.coef = coef * expn;
            p->data.expn = expn - 1;
            p->next = NULL;
            tail->next = p;
            tail = p;
        }
    }

    LinkList p = polynomial->next;
    if(p!=NULL)//如果为零多项式 需判断p 否则出现segmenterror报错
    {
        while(p->next!=NULL)
        {
            printf("%d %d ",p->data.coef,p->data.expn);
            p=p->next;
        }
        printf("%d %d\n",p->data.coef,p->data.expn);
    }
    else//零多项式的输出
    {
        printf("0 0\n");
    }



    return 0;
}
