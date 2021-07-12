#include <stdio.h>

int main()
{
    int n;
    char ch;
    scanf("%d",&n);
    getchar();
    scanf("%c",&ch);

    int row;
    if(n%2==0)
        row = n/2;
    else
        row = n/2+1;

    for(int i=0; i<row; i++)
    {
        if(i==0||i==row-1)
        {
            for(int j=0; j<n; j++)
            {
                printf("%c",ch);
            }
            printf("\n");
        }
        else{
            printf("%c",ch);
            for(int j=1; j<n-1; j++)
            {
                printf(" ");
            }
            printf("%c\n",ch);
        }
    }
    return 0;
}
