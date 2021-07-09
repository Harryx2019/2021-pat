#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double coef; //系数
    int expn; //指数
} term,ElemType; //term表示多项式项，ElemType表示链表数据域

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode,*LinkList;

int main()
{
    LinkList polynomial1 = (LinkList)malloc(sizeof(LNode));
    polynomial1->next = NULL;

    LinkList polynomial2 = (LinkList)malloc(sizeof(LNode));
    polynomial2->next = NULL;

    LinkList polynomial3 = (LinkList)malloc(sizeof(LNode));
    polynomial3->next = NULL;

    //输入数据
    int i;
    for(i=0; i<2; i++)
    {
        double coef;
        int expn;
        LinkList tail=(LinkList)malloc(sizeof(LNode));
        if(i==0)
            tail = polynomial1;
        else
            tail = polynomial2;

        int k;
        scanf("%d",&k);
        for(; k>0; k--)
        {
            scanf("%d%lf",&expn,&coef);
            LNode *p = (LNode*)malloc(sizeof(LNode));
            p->data.coef = coef;
            p->data.expn = expn;
            p->next = NULL;
            tail->next = p;
            tail = p;
        }
    }

    //进行相加
    //先比较指数，指数大者插入链表，相等则进行相加
    LinkList p1 = polynomial1->next;
    LinkList p2 = polynomial2->next;
    LinkList tail = polynomial3;
    double coef1,coef2;
    int expn1,expn2;
    int k = 0;
    while(p1!=NULL && p2!=NULL)
    {
        coef1 = p1->data.coef;
        coef2 = p2->data.coef;

        expn1 = p1->data.expn;
        expn2 = p2->data.expn;
        if(expn1>expn2)
        {
            LNode *p = (LNode*)malloc(sizeof(LNode));
            p->data.coef = coef1;
            p->data.expn = expn1;
            p->next = NULL;
            tail->next = p;
            tail = p;
            k++;

            p1=p1->next;
        }
        else if(expn1<expn2)
        {
            LNode *p = (LNode*)malloc(sizeof(LNode));
            p->data.coef = coef2;
            p->data.expn = expn2;
            p->next = NULL;
            tail->next = p;
            tail = p;
            k++;

            p2=p2->next;
        }
        else
        {
            double coef = coef1 + coef2;
            if(coef!=0)
            {
                LNode *p = (LNode*)malloc(sizeof(LNode));
                p->data.coef = coef;
                p->data.expn = expn1;
                p->next = NULL;
                tail->next = p;
                tail = p;
                k++;
            }
            p1=p1->next;
            p2=p2->next;
        }
    }

    while(p1!=NULL)
    {
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data.coef = p1->data.coef;
        p->data.expn = p1->data.expn;
        p->next = NULL;
        tail->next = p;
        tail = p;
        k++;

        p1=p1->next;
    }

    while(p2!=NULL)
    {
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data.coef = p2->data.coef;
        p->data.expn = p2->data.expn;
        p->next = NULL;
        tail->next = p;
        tail = p;
        k++;

        p2=p2->next;
    }

    if(k!=0)
    {
        printf("%d ",k);
        LinkList p=polynomial3->next;
        while(p->next!=NULL)
        {
            printf("%d %.1f ",p->data.expn,p->data.coef);
            p=p->next;
        }
        printf("%d %.1f\n",p->data.expn,p->data.coef);
    }
    else
        printf("0");

    return 0;

}
