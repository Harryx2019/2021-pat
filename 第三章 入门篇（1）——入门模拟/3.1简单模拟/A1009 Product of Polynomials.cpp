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

double res[2021]= {};

int main()
{
    //多项式A以链表形式存储
    LinkList polynomiala = (LinkList)malloc(sizeof(LNode));
    polynomiala->next = NULL;

    LinkList tail=polynomiala;

    int k1,k2;
    double coef;//系数
    int expn;//指数

    scanf("%d",&k1);
    if(k1==0)
    {
        printf("0\n");
        return 0;
    }
    for(; k1>0; k1--)
    {
        scanf("%d%lf",&expn,&coef);
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data.coef = coef;
        p->data.expn = expn;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }

    //多项式依次输入依次处理
    scanf("%d",&k2);
    if(k2==0)
    {
        printf("0\n");
        return 0;
    }
    int expn_r;
    double coef_r;
    for(; k2>0; k2--)
    {
        scanf("%d %lf",&expn,&coef);
        LinkList p=polynomiala->next;
        while(p!=NULL)
        {
            expn_r = p->data.expn+expn;
            coef_r = p->data.coef*coef;
            res[expn_r] += coef_r;
            p=p->next;
        }
    }

    int count=0;
    for(int i=0; i<2021; i++)
    {
        if(res[i]!=0)
        {
            count++;
        }
    }

    printf("%d",count);
    if(count!=0)
    {
        for(int i=2020,k=0; i>=0&&k<count; i--)
        {
            if(res[i]!=0)
            {
                printf(" %d %.1f",i,res[i]);
                k++;
            }
        }
    }
    printf("\n");

    return 0;
}
