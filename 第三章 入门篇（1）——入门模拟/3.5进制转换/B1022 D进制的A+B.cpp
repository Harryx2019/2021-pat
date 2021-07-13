#include <stdio.h>

int main()
{
    int a,b,d;
    scanf("%d%d%d",&a,&b,&d);

    int c = a+b;

    int ans[31],num=0;
    do{
        ans[num++]=c%d;
        c=c/d;
    }while(c!=0);

    for(num--;num>=0;num--){
        printf("%d",ans[num]);
    }

    return 0;
}
