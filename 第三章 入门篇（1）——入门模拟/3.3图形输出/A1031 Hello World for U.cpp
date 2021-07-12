#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *str = (char*)malloc(sizeof(char));
    scanf("%s",str);

    int len = strlen(str);

    int n1,n2,n3;
    for(n2=3;n2<=len;n2++){
        if((len+2-n2)%2==0)
        {
            n1=(len+2-n2)/2;
            n3=n1;
            if(n1<=n2)
                break;
        }
    }

    for(int i=0;i<n1-1;i++){
        printf("%c",str[i]);
        for(int j=0;j<n2-2;j++)
            printf(" ");
        printf("%c\n",str[len-1-i]);
    }

    for(int i=n1-1;i<n1+n2-1;i++)
        printf("%c",str[i]);
    printf("\n");

    return 0;
}
