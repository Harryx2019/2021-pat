#include <stdio.h>

#define CLK_TCK 100

int main()
{
    int c1,c2,time;
    scanf("%d %d",&c1,&c2);

    time = (c2 - c1)/CLK_TCK;
    int t = (c2 - c1)%CLK_TCK;
    if(t>=50){
        time++;
    }
    int hour,minute,second;
    hour = time / (60*60);
    time = time % (60*60);

    minute = time / 60;
    time = time % 60;

    second = time;
    printf("%02d:%02d:%02d\n",hour,minute,second);
    return 0;
}
