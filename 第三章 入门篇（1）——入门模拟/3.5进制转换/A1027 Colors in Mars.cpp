#include <stdio.h>

int main()
{
    int red,green,blue;
    scanf("%d %d %d",&red,&green,&blue);

    int ans_red[2]= {0},ans_green[2]= {0},ans_blue[2]= {0};
    int num=0;

    do
    {
        ans_red[num++] = red%13;
        red = red/13;
    }
    while(red!=0);

    num=0;
    do
    {
        ans_green[num++] = green%13;
        green = green/13;
    }
    while(green!=0);

    num=0;
    do
    {
        ans_blue[num++] = blue%13;
        blue = blue/13;
    }
    while(blue!=0);

    printf("#");
    for(int i=1; i>=0; i--)
    {
        if(ans_red[i]==10)
            printf("A");
        else if(ans_red[i]==11)
            printf("B");
        else if(ans_red[i]==12)
            printf("C");
        else
            printf("%d",ans_red[i]);
    }

    for(int i=1; i>=0; i--)
    {
        if(ans_green[i]==10)
            printf("A");
        else if(ans_green[i]==11)
            printf("B");
        else if(ans_green[i]==12)
            printf("C");
        else
            printf("%d",ans_green[i]);
    }

    for(int i=1; i>=0; i--)
    {
        if(ans_blue[i]==10)
            printf("A");
        else if(ans_blue[i]==11)
            printf("B");
        else if(ans_blue[i]==12)
            printf("C");
        else
            printf("%d",ans_blue[i]);
    }
    printf("\n");

    return 0;
}
