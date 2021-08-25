#include <stdio.h>

int num[10]={0};

int main()
{
    int i;
    for(i=0;i<10;i++)
        scanf("%d",&num[i]);

    for(i=1;i<10;i++)
    {
        if(num[i]!=0)
        {
            printf("%d",i);
            num[i]--;
            break;
        }
    }

    for(i=0;i<10;i++)
    {
        while(num[i]>0)
        {
            printf("%d",i);
            num[i]--;
        }
    }

    return 0;
}
