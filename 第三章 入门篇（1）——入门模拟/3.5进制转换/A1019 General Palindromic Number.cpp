#include <stdio.h>

int main()
{
    int N,b;
    scanf("%d %d",&N,&b);

    //positive decimal integer
    int ans[31];
    int num = 0;

    do
    {
        ans[num++]=N%b;
        N/=b;
    }
    while(N!=0);

    int i,j;
    for(i=0,j=num-1; i<j; i++,j--)
    {
        if(ans[i]!=ans[j])
        {
            printf("No\n");
            break;
        }
    }

    if(i>=j)
        printf("Yes\n");
    for(i=num-1; i>0; i--)
        printf("%d ",ans[i]);
    printf("%d\n",ans[i]);

    return 0;
}
