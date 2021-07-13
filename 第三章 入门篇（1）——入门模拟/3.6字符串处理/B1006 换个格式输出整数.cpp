#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int ans[3]={0};
    int num=0;
    do{
        ans[num++]=n%10;
        n=n/10;
    }while(n!=0);

    while(ans[2]!=0){
        printf("B");
        ans[2]--;
    }

    while(ans[1]!=0){
        printf("S");
        ans[1]--;
    }

    for(int i=1;i<=ans[0];i++){
        printf("%d",i);
    }
    printf("\n");

    return 0;
}
