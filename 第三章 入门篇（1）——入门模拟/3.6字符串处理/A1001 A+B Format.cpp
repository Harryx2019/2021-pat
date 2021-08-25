#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    int c = a+b;

    if(c<0)
    {
        printf("-");
        c=-c;
    }

    if(c==0)
        printf("0");

    char num[10];
    int i=0,j=0;
    while(c!=0)
    {
        j++;
        num[i]=c%10+'0';
        c/=10;
        i++;
        if(j==3)
        {
            num[i]=',';
            i++;
            j=0;
        }
    }
    i--;
    if(num[i]==',')
        i--;
    for(; i>=0; i--)
        printf("%c",num[i]);

    return 0;

}
