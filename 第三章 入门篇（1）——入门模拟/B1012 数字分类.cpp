#include <stdio.h>

int main()
{
    int n,num;
    scanf("%d",&n);

    int i;
    int a[5][2]= {0};
    for(i=0; i<n; i++)
    {
        scanf("%d",&num);
        if(num%5==0&&num%2==0)
        {
            a[0][0]++;
            a[0][1]+=num;
        }
        if(num%5==1)
        {
            a[1][0]++;
            if(a[1][0]%2==0)
            {
                a[1][1]-=num;
            }
            else
            {
                a[1][1]+=num;
            }
        }
        if(num%5==2)
        {
            a[2][0]++;
            a[2][1]++;
        }
        if(num%5==3)
        {
            a[3][0]++;
            a[3][1]+=num;
        }
        if(num%5==4)
        {
            a[4][0]++;
            if(a[4][0]==1)
            {
                a[4][1];
                a[4][1]=num;
                continue;
            }
            if(a[4][1]<num)
            {
                a[4][1]=num;
            }
        }
    }
    for(i=0; i<4; i++)
    {
        if(a[i][0]==0)
        {
            printf("N ");
            continue;
        }
        if(i==3)
        {
            printf("%.1f ",a[3][1]*1.0/a[3][0]);
            break;
        }
        printf("%d ",a[i][1]);
    }
    if(a[4][0]==0)
        printf("N");
    else
        printf("%d",a[4][1]);

    return 0;
}
