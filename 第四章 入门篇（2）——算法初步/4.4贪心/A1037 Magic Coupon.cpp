#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int Nc,Np;

    int i,j;
    scanf("%d",&Nc);
    int coupons[Nc];
    for(i=0;i<Nc;i++)
        scanf("%d",&coupons[i]);

    scanf("%d",&Np);
    int products[Np];
    for(i=0;i<Np;i++)
        scanf("%d",&products[i]);

    sort(coupons,coupons+Nc,cmp);
    sort(products,products+Np,cmp);

    long long ans=0;
    //选择为正的最大优惠券和商品
    for(i=0;i<Nc&&i<Np;i++)
    {
        if(coupons[i]>0&&products[i]>0)
            ans+=coupons[i]*products[i];
        else
            break;
    }
    if(i!=Nc&&i!=Np)
    {
        //选择为负的最小优惠券和商品
        for(i=Nc-1,j=Np-1;i>=0&&j>=0;i--,j--)
        {
            if(coupons[i]>0||products[j]>0)
                break;
            ans+=coupons[i]*products[j];
        }
    }
    printf("%lld\n",ans);

    return 0;
}
