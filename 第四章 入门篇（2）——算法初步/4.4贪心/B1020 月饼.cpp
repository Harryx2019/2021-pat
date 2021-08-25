#include <iostream>
#include <algorithm>
using namespace std;

typedef struct yuebing
{
    double store;
    double sale;
    double single_sale;
}yuebing;

bool cmp(yuebing y1,yuebing y2)
{
    return y1.single_sale>y2.single_sale;
}

int main()
{
    int n;
    double d;
    scanf("%d %lf",&n,&d);

    yuebing yuebings[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%lf",&yuebings[i].store);

    for(i=0;i<n;i++)
        scanf("%lf",&yuebings[i].sale);

    for(i=0;i<n;i++)
        yuebings[i].single_sale=yuebings[i].sale/yuebings[i].store;

    sort(yuebings,yuebings+n,cmp);
    double profit=0;
    for(i=0;i<n;i++)
    {
        if(yuebings[i].store<=d)
        {
            profit += yuebings[i].sale;
            d=d-yuebings[i].store;
            if(d==0)
                break;
        }
        else
        {
            profit += yuebings[i].single_sale*d;
            break;
        }
    }
    printf("%.2f",profit);

    return 0;
}
