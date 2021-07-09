#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    bool flag1,flag2;
    int a=0,b=0;
    while(n!=0)
    {
        flag1=false;
        flag2=false;
        int a1,a2,b1,b2;
        scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
        if(a2==a1+b1)
            flag1=true;

        if(b2==a1+b1)
            flag2=true;

        if(flag1==flag2)
        {
            n--;
            continue;
        }

        if(flag1)
            b++;

        if(flag2)
            a++;
        n--;
    }
    printf("%d %d\n",a,b);
    return 0;
}
