#include <stdio.h>
#include <string.h>

char number[10][6]= {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main()
{
    char num[101];
    scanf("%s",num);

    int sum=0;
    int i;
    for(i=0; i<strlen(num); i++)
        sum+=num[i]-'0';
    if(sum==0)
        printf("%s",number[0]);
    else
    {
        i=0;
        int res[4];
        while(sum!=0)
        {
            res[i]=sum%10;
            sum/=10;
            i++;
        }
        for(i--; i>0; i--)
            printf("%s ",number[res[i]]);
        printf("%s\n",number[res[0]]);
    }
    return 0;
}
