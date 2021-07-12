#include <stdio.h>

int main()
{
    int n;
    char ch;
    scanf("%d",&n);
    getchar();
    scanf("%c",&ch);

    int row;
    for(row=1;;row++){
        if(2*row*row-1==n)
            break;
        if(2*row*row-1>n)
        {
            row--;
            break;
        }
    }

    int max = 2*row - 1;
    int remain = n - 2*row*row + 1;

    for(int i=0;i<row;i++){
        for(int j=0;j<i;j++)
            printf(" ");
        for(int j=0;j<2*(row-i)-1;j++)
            printf("%c",ch);
        printf("\n");
    }

    for(int i=1;i<row;i++){
        for(int j=row-i-1;j>0;j--)
            printf(" ");
        for(int j=0;j<2*(i+1)-1;j++)
            printf("%c",ch);
        printf("\n");
    }

    printf("%d\n",remain);

    return 0;
}
