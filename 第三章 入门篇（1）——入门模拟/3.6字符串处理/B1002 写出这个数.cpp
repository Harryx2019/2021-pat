#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *number[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main()
{
    char n[101];
    scanf("%s",n);

    int i;
    int sum=0;
    int len = strlen(n);
    for(i=0;i<len;i++)
        sum+=n[i]-'0';

    int result[4];
    for(i=0;sum!=0;i++)
    {
        result[i]=sum%10;
        sum/=10;
    }

    for(i--;i>0;i--)
        printf("%s ",number[result[i]]);
    printf("%s\n",number[result[0]]);

    return 0;
}
