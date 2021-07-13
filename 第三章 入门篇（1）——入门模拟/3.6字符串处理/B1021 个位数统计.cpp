#include <stdio.h>
#include <string.h>

int main()
{
    char num[1001];
    scanf("%s",num);
    int len = strlen(num);

    int ans[10]={0};
    for(int i=0; i<len; i++)
    {
        ans[num[i]-'0']++;
    }

    for(int i=0; i<10; i++)
    {
        if(ans[i]!=0)
        {
            printf("%d:%d\n",i,ans[i]);
        }
    }

    return 0;
}
