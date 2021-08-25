#include <stdio.h>
#include <stdlib.h>

char z[11]= {'1','0','X','9','8','7','6','5','4','3','2'};
int weight[17]= {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

int main()
{
    int n;
    scanf("%d",&n);

    int isTrue[n]= {0};
    char **IDcards = (char**)malloc(sizeof(char*)*n);
    for(int i=0; i<n; i++)
        IDcards[i] = (char*)malloc(sizeof(char)*18);


    int num=0;
    for(int i=0; i<n; i++)
    {
        scanf("%s",IDcards[i]);
        int j,sum=0;
        for(j=0; j<17; j++)
        {
            if(IDcards[i][j]>='0'&&IDcards[i][j]<='9')
            {
                sum+=(IDcards[i][j]-'0')*weight[j];
            }
            else
            {
                break;
            }
        }
        if(j==17 && z[sum%11] == IDcards[i][17])
        {
            num++;
            isTrue[i]=1;
        }
    }

    if(num==n)
        printf("All passed\n");
    else
    {
        for(int i=0; i<n; i++)
        {
            if(!isTrue[i])
                printf("%s\n",IDcards[i]);
        }
    }

    return 0;
}
